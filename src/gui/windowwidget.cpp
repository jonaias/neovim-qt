#include "windowwidget.h"
#include <QPainter>
#include <QPaintEvent>

namespace NeovimQt {

WindowWidget::WindowWidget(Gui *g, uint64_t window_id, QWidget *parent)
:QWidget(parent), m_gui(g), 
	m_rows(0), m_cols(0), m_window_id(window_id),
	m_foreground(Qt::black),m_background(Qt::white)
{
	// Set default font
	QFont f;
	f.setStyleStrategy(QFont::StyleStrategy(QFont::PreferDefault | QFont::ForceIntegerMetrics) );
	f.setStyleHint(QFont::TypeWriter);
	f.setFamily("Monospace");
	f.setFixedPitch(true);
	f.setPointSize(10);
	f.setKerning(false);
	f.setFixedPitch(true);

	m_font = f;
	m_fm = new QFontMetrics(m_font);

	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	setAttribute(Qt::WA_OpaquePaintEvent, true);
	setAttribute(Qt::WA_StaticContents, true);
}

void WindowWidget::redrawCursor(uint64_t col, uint64_t row)
{

}

void WindowWidget::redrawRuler(const QVariantMap& m)
{
	qDebug() << __func__ << windowId() << m;
}

void WindowWidget::redrawStatusLine(const QVariantMap& m)
{
	qDebug() << __func__ << windowId() << m;
}

void WindowWidget::updateLine(uint64_t row, const QVariantList& line, const QVariantMap& attrs)
{
	QString text;
	QList<QSet<QString> > attrMap;
	if (line.size() == 0) {
		text = "";
	} else {
		// Build final string and attribute map
		foreach(QVariant v, line) {
			QVariantMap map = v.toMap();
			text += map.value("content").toString();
		}
		attrMap = attrsToMap(text, attrs);
	}

	PaintOp bgp(CLEAR_RECT);
	bgp.rect = QRect(0, row*m_fm->height(),
			m_cols*m_fm->width("W"), m_fm->height());
	queuePaintOp(bgp);

	if (attrMap.isEmpty()) {
		// Paint line with no formatting
		queueUpdateLine(text, row, 0);
		return;
	}
	
	int startSection = 0;
	// Split this into multiple paint ops
	int pos;
	for (pos=0; pos<text.size(); pos++) {
		if (pos == 0 || attrMap[pos] == attrMap[pos-1]) {
			continue;
		}
		queueUpdateLine(text.mid(startSection, pos-startSection),
				row, startSection, attrMap[pos-1]);
		startSection = pos;
	}
	queueUpdateLine(text.mid(startSection, pos-startSection),
			row, startSection, attrMap[pos-1]);
}

/**
 * A helper method to push text paint operations with
 * attributes
 */
void WindowWidget::queueUpdateLine(const QString& text, 
		uint64_t row, uint64_t col, const QSet<QString>& attrs)
{
	PaintOp p(UPDATE_LINE);
	p.text = text;
	p.pos = QPoint(col*m_fm->width("W"), row*m_fm->height()+m_fm->ascent());
	p.rect = QRect(col*m_fm->width("W"), row*m_fm->height(),
			(text.size())*m_fm->width("W"), m_fm->height());
	p.font = m_font;

	foreach(QString name, attrs) {
		if (name == "bold") {
			p.font.setBold(true);
		} else if (name.startsWith("fg:")) {
			QColor c(name.mid(3));
			if (c.isValid()) {
				p.fg_color = c;
			}
		} else if (name.startsWith("bg:")) {
			QColor c(name.mid(3));
			if (c.isValid()) {
				p.bg_color = c;
			}
		} else if (name == "underline") {
			p.font.setUnderline(true);
		} else if (name == "italic") {
			p.font.setItalic(true);
		} else {
			qWarning() << "Unsupported text attribute" << name;
		}
	}

	queuePaintOp(p);
}

void WindowWidget::insertLine(uint64_t row, uint64_t count)
{
	PaintOp p(INSERT_LINE);
	p.rect = QRect(0, row*m_fm->height(),
			m_cols*m_fm->width("W"), m_rows*m_fm->height());
	p.pos = QPoint(0, count*m_fm->height());
	queuePaintOp(p);
}

void WindowWidget::deleteLine(uint64_t row, uint64_t count)
{
	PaintOp p(DELETE_LINE);
	p.rect = QRect(0, row*m_fm->height(),
			m_cols*m_fm->width("W"), m_rows*m_fm->height());
	p.pos = QPoint(0, -count*m_fm->height());
	queuePaintOp(p);
}

void WindowWidget::redrawLayout(uint64_t height, uint64_t width)
{
	// TODO: there are cases when we cannot resize!
	m_rows = height;
	// FIXME: set width correctly
	m_cols = width;
	setFixedSize(m_cols*m_fm->width("W"), m_rows*m_fm->height());
	updateGeometry();
	show();
}

QSize WindowWidget::sizeHint() const
{
	return QSize(m_cols*m_fm->width("W"), m_rows*m_fm->height());
}

void WindowWidget::paintEvent ( QPaintEvent *ev )
{
	QPainter painter(this);
	while ( !m_ops.isEmpty() ) {
		painter.save();
		PaintOp op = m_ops.dequeue();

		switch( op.type ) {
		case INSERT_LINE:
		case DELETE_LINE:
			// Insert/Delete line just scroll the canvas
			painter.restore();
			painter.end();
			this->scroll(op.pos.x(), op.pos.y(), op.rect);
			painter.begin(this);
			continue;
		case UPDATE_LINE:
			// FIXME: see CLEAR_RECT
			if (op.bg_color.isValid()) {
				painter.fillRect(op.rect, op.bg_color);
			}
			if (op.fg_color.isValid()) {
				painter.setPen(op.fg_color);
			} else {
				painter.setPen(m_foreground);
			}
			painter.setFont(op.font);
			painter.drawText( op.pos, op.text);
			break;
		case WINDOW_END:
		case CLEAR_RECT:
			painter.fillRect(op.rect, m_background);
			break;
		default:
			qWarning() << "Unsupported paint op" << op.type;
		}
		painter.restore();
	}
}

/**
 * Queue a painting operation on the widget
 */
void WindowWidget::queuePaintOp(PaintOp op)
{
	m_ops.enqueue(op);
	if (op.rect.isValid()) {
		update(op.rect);
	}
}

void WindowWidget::setBackgroundColor(const QString& name)
{
	QColor c = QColor(name);
	if (c.isValid()) {
		m_background = c;
	}
}

void WindowWidget::setForegroundColor(const QString& name)
{
	QColor c = QColor(name);
	if (c.isValid()) {
		m_foreground = c;
	}
}

/**
 * Called when a window has scrolled to the end and the empty rows need to
 * be cleared - Neovim places a _marker_ at the line start and fills the
 * remaining positions with _fill_
 */
void WindowWidget::windowEnded(uint64_t row, uint64_t endrow, const QString& marker, const QString& fill)
{
	QString text = marker;
	for (uint64_t i=1; i<m_cols; i++ ) {
		text += fill;
	}
	for (uint64_t i=row; i<endrow; i++) {
		// FIXME: clean this up please
		PaintOp bgp(WINDOW_END);
		bgp.rect = QRect(0, i*m_fm->height(),
				m_cols*m_fm->width("W"), (i+1)*m_fm->height());
		queuePaintOp(bgp);
		queueUpdateLine(text, i, 0);
	}
}

void WindowWidget::resizeEvent(QResizeEvent *ev)
{
	if (!ev->oldSize().isValid()) {
		// When first resizing fill up with the background
		// color
		PaintOp p(CLEAR_RECT);
		p.rect = rect();
		queuePaintOp(p);
		return;
	}

	// Paint margins outside the Neovim window
	int dx = ev->size().width() - (int)m_cols*m_fm->width("W");
	int dy = ev->size().height() - (int)m_rows*m_fm->height();

	if (dx > 0) {
		PaintOp bgp(CLEAR_RECT);
		bgp.rect = QRect(m_cols*m_fm->width("W"), 0,
			ev->size().width(), m_rows*m_fm->height());
		queuePaintOp(bgp);
	}
	if (dy > 0) {
		PaintOp bgp(CLEAR_RECT);
		bgp.rect = QRect(0, m_rows*m_fm->height(),
			m_cols*m_fm->width("W"), ev->size().height());
		queuePaintOp(bgp);
	}
	if (dx > 0 && dy > 0) {
		PaintOp bgp(CLEAR_RECT);
		bgp.rect = QRect(m_cols*m_fm->width("W"), m_rows*m_fm->height(),
			ev->size().width(), ev->size().height());
		queuePaintOp(bgp);
	}
}

} // Namespace


QDebug operator<<(QDebug dbg, const NeovimQt::WindowWidget::PaintOpType t)
{
	switch(t) {
	case NeovimQt::WindowWidget::DELETE_LINE:
		dbg.space() << "DELETE_LINE";
		break;
	case NeovimQt::WindowWidget::INSERT_LINE:
		dbg.space() << "INSERT_LINE";
		break;
	case NeovimQt::WindowWidget::UPDATE_LINE:
		dbg.space() << "UPDATE_LINE";
		break;
	case NeovimQt::WindowWidget::CLEAR_RECT:
		dbg.space() << "CLEAR_RECT";
		break;
	case NeovimQt::WindowWidget::WINDOW_END:
		dbg.space() << "WINDOW_END";
		break;
	case NeovimQt::WindowWidget::NOOP:
		dbg.space() << "NOOP";
		break;
	}
	return dbg.maybeSpace();
}


