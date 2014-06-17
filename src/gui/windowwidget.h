#ifndef NEOVIM_QT_WINDOWWIDGET
#define NEOVIM_QT_WINDOWWIDGET

#include <QWidget>
#include <QQueue>
#include "gui.h"
#include "basewindow.h"

namespace NeovimQt {

class WindowWidget: public QWidget, public BaseWindow
{
	Q_OBJECT
	Q_ENUMS(PaintOpType)
public:
	WindowWidget(Gui *g, uint64_t window_id, QWidget *parent=0);

	enum PaintOpType {CLEAR_ALL, DELETE_LINE, INSERT_LINE, UPDATE_LINE, CLEAR_RECT, NOOP};
	class PaintOp {
	public:
		PaintOp(PaintOpType t=NOOP) {type=t;}
		PaintOpType type;
		QPoint pos;
		QRect rect;
		QString text;
		QFont font;
		QColor fg_color, bg_color;
	};

	virtual QSize sizeHint() const;
public:
	virtual uint64_t windowId() {return m_window_id;}
	void redrawCursor(uint64_t col, uint64_t row);
	virtual void redrawRuler(const QVariantMap& m);
	virtual void redrawStatusLine(const QVariantMap& m);
	virtual void updateLine(uint64_t row, const QVariantList& line, const QVariantMap& attrs);
	virtual void insertLine(uint64_t row_index, uint64_t count);
	virtual void deleteLine(uint64_t row_index, uint64_t count);
	virtual void redrawLayout(uint64_t height, uint64_t width);
	virtual void setForegroundColor(const QString&);
	virtual void setBackgroundColor(const QString&);
	virtual void windowEnded(uint64_t row, uint64_t endrow, const QString& marker, const QString& fill);

protected:
	void queuePaintOp(PaintOp);
	void paintEvent(QPaintEvent *ev);
	void resizeEvent(QResizeEvent *ev);
	void queueUpdateLine(const QString& text, uint64_t row, 
			uint64_t col, const QSet<QString>& attrs=QSet<QString>());

private:
	QQueue<PaintOp> m_ops;
	Gui *m_gui;
	QFont m_font;
	QFontMetrics *m_fm;
	uint64_t m_rows, m_cols, m_window_id;
	QColor m_foreground, m_background;
	QPixmap m_canvas;
};


} // Namespace

#endif
