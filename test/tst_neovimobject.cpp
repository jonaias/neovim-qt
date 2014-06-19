
#include <QtTest/QtTest>
#include <QLocalSocket>
#include <neovimconnector.h>
#include "auto/neovim.h"

class TestNeovimObject: public QObject
{
	Q_OBJECT
public slots:
	void notification(const QByteArray& name, const QVariant& v);

protected slots:
	void delayedSetup();

private slots:
	void initTestCase();
	void test_callback();
	void eventTypes();
private:
	NeovimQt::NeovimConnector *m_c;
	bool m_test_event_string;
	bool m_test_event_uint;
	bool m_test_event_stringlist;
};

void TestNeovimObject::notification(const QByteArray& name, const QVariant& v)
{
	if ( (QMetaType::Type)v.type() == QMetaType::QString ) {
		QVERIFY(v.toString() == "WAT");
		m_test_event_string = true;
	}

	if ( (QMetaType::Type)v.type() == QMetaType::ULongLong ) {
		QVERIFY(v.toInt() == 42);
		m_test_event_uint = true;
	}

	if (v.canConvert(QMetaType::QStringList)) {
		QStringList l = v.toStringList();
		m_test_event_stringlist = true;
	}
}

void TestNeovimObject::delayedSetup()
{
	NeovimQt::Neovim *n = m_c->neovimObject();

	m_test_event_string = false;
	m_test_event_uint = false;
	m_test_event_stringlist = false;
	n->vim_command(QString("call send_event(%1, \"test_event\", \"WAT\")").arg(m_c->channel()));
	n->vim_command(QString("call send_event(%1, \"test_event\", 42)").arg(m_c->channel()));
	n->vim_command(QString("call send_event(%1, \"test_event\", [\"one\", \"two\", \"\"])").arg(m_c->channel()));
}

//
// Tests start here
//
void TestNeovimObject::eventTypes()
{
	QVERIFY(m_test_event_string);
	QVERIFY(m_test_event_uint);
	QVERIFY(m_test_event_stringlist);
}

void TestNeovimObject::test_callback()
{
	bool success = false;
	m_c->neovimObject()->vim_subscribe("redraw:*", [&success](){
				success = true;
			});

	QTest::qWait(500);
	QVERIFY(success);
}

void TestNeovimObject::initTestCase()
{
	QLocalSocket *s = new QLocalSocket();
	s->connectToServer(QLatin1String("/tmp/neovim"));
	QVERIFY(s->waitForConnected());
	m_c = new NeovimQt::NeovimConnector(s);
	QVERIFY(m_c->neovimObject());

	connect(m_c, &NeovimQt::NeovimConnector::ready,
			this, &TestNeovimObject::delayedSetup);
	connect(m_c, &NeovimQt::NeovimConnector::notification,
			this, &TestNeovimObject::notification);
	QTest::qWait(500);
}

QTEST_MAIN(TestNeovimObject)
#include "tst_neovimobject.moc"

