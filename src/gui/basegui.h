#ifndef NEOVIM_QT_GUI_BASEGUI
#define NEOVIM_QT_GUI_BASEGUI

#include <neovimconnector.h>
#include "basewindow.h"

namespace NeovimQt {

class BaseGui: public QObject
{
	Q_OBJECT
public:
	BaseGui(NeovimConnector *n, QObject *parent=0);
	Neovim* neovimObject();

signals:
	void redrawCursor(uint64_t col, uint64_t row);
	void updateLine(uint64_t window, uint64_t row, const QVariantList& line, const QVariantMap& attrs);
	void insertLine(uint64_t window, uint64_t row_index, uint64_t count);
	void deleteLine(uint64_t window, uint64_t row_index, uint64_t count);
	void redrawLayout(uint64_t window, uint64_t height, uint64_t width);
	void backgroundColor(const QString&);
	void foregroundColor(const QString&);
	void windowEnded(uint64_t window_id, uint64_t row, uint64_t endrow, const QString& marker, const QString& fill);

protected:
	void handleRedrawCursor(const QVariantMap&);
	void handleRedrawRuler(const QVariantMap&);
	void handleRedrawStatusLine(const QVariantMap&);
	void handleRedrawUpdateLine(const QVariantMap&);
	void handleRedrawInsertLine(const QVariantMap&);
	void handleRedrawDeleteLine(const QVariantMap&);
	void handleRedrawForegroundColor(const QVariantMap&);
	void handleRedrawBackgroundColor(const QVariantMap&);
	void handleRedrawWinEnd(const QVariantMap&);
	void handleRedrawStart();
	void handleRedrawEnd();

	virtual void handleRedrawLayout(const QVariantMap&)=0;

	virtual bool hasWindow(uint64_t id)=0;
	virtual BaseWindow* getWindow(uint64_t id)=0;
	virtual QList<uint64_t> windows()=0;

protected slots:
	void neovimReady();
	void neovimNotification(const QByteArray &name, const QVariant& args);

private:
	NeovimConnector *m_nc;

};

} // Namespace

#endif
