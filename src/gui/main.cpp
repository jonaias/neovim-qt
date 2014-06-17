#include <QApplication>
#include <neovimconnector.h>
#include <QLocalSocket>
#include "gui.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QLocalSocket s;
	s.connectToServer(QLatin1String("/tmp/neovim"));
	NeovimQt::NeovimConnector c(&s);

	NeovimQt::Gui g(&c);

	return app.exec();
}
