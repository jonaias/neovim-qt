
#include <QtTest/QtTest>
#include <QLocalSocket>
#include <neovimconnector.h>

class TestConnector: public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void invalidSocket();

private:
	NeovimQt::NeovimConnector *m_c;

};

void TestConnector::initTestCase()
{
	QLocalSocket *s = new QLocalSocket();
	s->connectToServer(QLatin1String("/tmp/neovim"));
	QVERIFY(s->waitForConnected());
	m_c = new NeovimQt::NeovimConnector(s);
}

void TestConnector::invalidSocket()
{
	// we expect the connector to complain
	QLocalSocket s;
	NeovimQt::NeovimConnector *c = new NeovimQt::NeovimConnector(&s);
	QVERIFY(c->error() != NeovimQt::NeovimConnector::NoError);
}

QTEST_MAIN(TestConnector)
#include "tst_connector.moc"

