#ifndef NEOVIM_QT_GUI_GUI
#define NEOVIM_QT_GUI_GUI

#include "basegui.h"
#include <QSplitter>

namespace NeovimQt {

class WindowWidget;
class Gui: public BaseGui
{
public:
	Gui(NeovimConnector *n, QObject *parent=0);

protected:
	virtual void handleRedrawLayout(const QVariantMap&);
	virtual bool hasWindow(uint64_t id);
	virtual BaseWindow* getWindow(uint64_t id);
	virtual QList<uint64_t> windows();

private:
	void handleRedrawLayout(const QVariantMap& arg, QSplitter *);
	QSplitter *m_widget;
	QHash<uint64_t,WindowWidget*> m_windows;
};
} // namespace;

#endif
