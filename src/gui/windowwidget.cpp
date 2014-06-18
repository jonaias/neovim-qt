#include "windowwidget.h"
#include <QPainter>
#include <QPaintEvent>

namespace NeovimQt {

WindowWidget::WindowWidget(Gui *g, uint64_t window_id, QWidget *parent)
:QWidget(parent), m_gui(g), 
	m_rows(0), m_cols(0), m_window_id(window_id),
	m_foreground(Qt::black),m_background(Qt::white), m_paintingPaused(false)
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

void WindowWidget::redrawStart()
{
	m_paintingPaused = true;
}

void WindowWidget::redrawEnd()
{
	m_paintingPaused = false;
	update(m_pendingUpdates);
	m_pendingUpdates = QRegion();
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

	clearRow(row);

	if (attrMap.isEmpty()) {
		// Paint line with no formatting
		drawString(text, row, 0);
		return;
	}
	
	int startSection = 0;
	// Split this into multiple paint ops
	int pos;
	for (pos=0; pos<text.size(); pos++) {
		if (pos == 0 || attrMap[pos] == attrMap[pos-1]) {
			continue;
		}
		drawString(text.mid(startSection, pos-startSection),
				row, startSection, attrMap[pos-1]);
		startSection = pos;
	}
	drawString(text.mid(startSection, pos-startSection),
			row, startSection, attrMap[pos-1]);
}

/**
 * Helper method to raw a string into an arbitrary position
 */
void WindowWidget::drawString(const QString& text, 
		uint64_t row, uint64_t col, const QSet<QString>& attrs)
{
	QPainter painter(&m_canvas);
	QPoint pos(col*m_fm->width("W"), row*m_fm->height()+m_fm->ascent());
	QRect rect(col*m_fm->width("W"), row*m_fm->height(),
			(text.size())*m_fm->width("W"), m_fm->height());
	QFont font = m_font;
	QColor fg_color, bg_color;

	foreach(QString name, attrs) {
		if (name == "bold") {
			font.setBold(true);
		} else if (name.startsWith("fg:")) {
			fg_color = QColor(name.mid(3));
		} else if (name.startsWith("bg:")) {
			bg_color = QColor(name.mid(3));
		} else if (name == "underline") {
			font.setUnderline(true);
		} else if (name == "italic") {
			font.setItalic(true);
		} else {
			qWarning() << "Unsupported text attribute" << name;
		}
	}

	if (bg_color.isValid()) {
		painter.fillRect(rect, bg_color);
	}
	if (fg_color.isValid()) {
		painter.setPen(fg_color);
	} else {
		painter.setPen(m_foreground);
	}
	painter.setFont(font);
	painter.drawText(pos, text);
	maybeUpdate(rect);
}

void WindowWidget::insertLine(uint64_t row, uint64_t count)
{
	// Aread to be moved
	QRect rect(0, row*m_fm->height(),
			m_cols*m_fm->width("W"), (m_rows-count)*m_fm->height());
	// Where we placed the selected area
	QPoint pos(0, (row+count)*m_fm->height());
	QImage area = m_canvas.copy();

	QPainter painter(&m_canvas);
	painter.drawImage(pos, area);

	QRect updateRect(
		QPoint(0, (row+count)*m_fm->height()),
		QPoint(m_cols*m_fm->width("W"), m_rows*m_fm->height())
		);
	maybeUpdate(rect);
}

void WindowWidget::deleteLine(uint64_t row, uint64_t count)
{
	// Aread to be moved
	QRect rect(
		QPoint(0, (row+count)*m_fm->height()),
		QPoint(m_cols*m_fm->width("W"), m_rows*m_fm->height())
		);

	// Where we will place the selected area
	QPoint pos(0, row*m_fm->height());
	QImage area = m_canvas.copy();
	QPainter painter(&m_canvas);
	painter.drawImage(pos, area, area.rect());

	QRect updateRect(pos, 
			QSize(m_cols*m_fm->width("W"), (m_rows-row-count)*m_fm->height()));
	maybeUpdate(updateRect);
}

void WindowWidget::redrawLayout(uint64_t height, uint64_t width)
{
	// TODO: there are cases when we cannot resize!
	m_rows = height;
	m_cols = width;
	setFixedSize(m_cols*m_fm->width("W"), m_rows*m_fm->height());
	updateGeometry();
	show();
}

QSize WindowWidget::sizeHint() const
{
	return QSize(m_cols*m_fm->width("W"), m_rows*m_fm->height());
}

/**
 * Fills an area with the background color
 */
void WindowWidget::clearRow(uint64_t row)
{
	QPainter painter(&m_canvas);
	QRect rect = QRect(0, row*m_fm->height(),
			m_cols*m_fm->width("W"), m_fm->height());
	painter.fillRect(rect, m_background);
	maybeUpdate(rect);
}

void WindowWidget::maybeUpdate(const QRect& rect)
{
	if (m_paintingPaused) {
		m_pendingUpdates += rect;
	} else {
		update(rect);
	}
}

void WindowWidget::paintEvent ( QPaintEvent *ev )
{
	QPainter painter(this);
	foreach(QRect rect, ev->region().rects()) {
		painter.drawImage(rect, m_canvas, rect);
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
	// TODO: all clearRow could be a single operation
	for (uint64_t i=row; i<endrow; i++) {
		clearRow(i);
		drawString(text, i, 0);
	}
}

void WindowWidget::resizeEvent(QResizeEvent *ev)
{
	QImage new_canvas = QImage( ev->size(), QImage::Format_ARGB32_Premultiplied);
	if (!ev->oldSize().isValid()) {
		// First resize ever
		m_canvas = new_canvas;
		return;
	}

	m_canvas = new_canvas;

	/*
	 * FIXME: paint margins and copy contents for resize
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
	*/
}

} // Namespace

