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
	virtual void redrawStart();
	virtual void redrawEnd();

protected:
	//void queuePaintOp(PaintOp);
	void paintEvent(QPaintEvent *ev);
	void resizeEvent(QResizeEvent *ev);
	void queueUpdateLine(const QString& text, uint64_t row, 
			uint64_t col, const QSet<QString>& attrs=QSet<QString>());

	// Painting operations
	void clearRow(uint64_t row);
	void maybeUpdate(const QRect&);


private:
	Gui *m_gui;
	QFont m_font;
	QFontMetrics *m_fm;
	uint64_t m_rows, m_cols, m_window_id;
	QColor m_foreground, m_background;
	bool m_paintingPaused;
	QRegion m_pendingUpdates;
	QImage m_canvas;
};


} // Namespace

#endif
