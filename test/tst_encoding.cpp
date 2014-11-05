
#include <QtTest/QtTest>
#include <QLocalSocket>
#include <neovimconnector.h>

class TestEncoding: public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void encodeString();
	void map();
	void checkVariant();
protected:
	NeovimQt::NeovimConnector *m_c;
};

void TestEncoding::encodeString()
{
	bool failed_to_set = false;
	QMetaObject::Connection conn;
	m_c->neovimObject()->vim_set_var("testing-neovim-qt", QString("value"));
	m_c->neovimObject()->vim_get_var("testing-neovim-qt");
	conn = connect(m_c->neovimObject(), &NeovimQt::Neovim::on_vim_get_var,
			[&failed_to_set](const QVariant& v) {
				(void) v;
				Q_ASSERT(v == QByteArray("value"));
			});
	QTest::qWait(500);
	disconnect(conn);

	bool var_set = false;
	m_c->neovimObject()->vim_set_var("testing-neovim-qt", QByteArray("value"));
	m_c->neovimObject()->vim_get_var("testing-neovim-qt");
	conn = connect(m_c->neovimObject(), &NeovimQt::Neovim::on_vim_get_var,
			[&var_set](const QVariant& v) {
				(void) v;
				var_set = true;
				Q_ASSERT(v == QVariant(QByteArray("value")));
			});
	QTest::qWait(500);
	Q_ASSERT(var_set);
	disconnect(conn);
}

void TestEncoding::map()
{
	QMetaObject::Connection conn;
	QVariantMap map;
	map.insert("answer", 42);
	m_c->neovimObject()->vim_set_var("test-map", map);
	m_c->neovimObject()->vim_get_var("test-map");
	conn = connect(m_c->neovimObject(), &NeovimQt::Neovim::on_vim_get_var,
			[map](const QVariant& v) {
				(void) v;
				Q_ASSERT(v == map);
			});
	QTest::qWait(500);
	disconnect(conn);
}

/**
 * QVariant can represent content that cannot be serialized into
 * msgpack, ::checkVariant is used by NeovimConnector::send to
 * verify it
 */
void TestEncoding::checkVariant()
{
	// Some Unsupported types
	Q_ASSERT(!NeovimQt::checkVariant(QRect()));

	// Supported types
	Q_ASSERT(NeovimQt::checkVariant(QVariant()));
	Q_ASSERT(NeovimQt::checkVariant(true));
	Q_ASSERT(NeovimQt::checkVariant(42));
	Q_ASSERT(NeovimQt::checkVariant(4.4));
	Q_ASSERT(NeovimQt::checkVariant(QString("test")));
	Q_ASSERT(NeovimQt::checkVariant(QByteArray()));
	Q_ASSERT(NeovimQt::checkVariant(QVariantList() << "test"));
	Q_ASSERT(NeovimQt::checkVariant(QVariantMap()));
	Q_ASSERT(NeovimQt::checkVariant(QPoint(1,1)));
}

void TestEncoding::initTestCase()
{
	bool ready = false;
	m_c = NeovimQt::NeovimConnector::spawn();
	Q_ASSERT(m_c->errorCause() == NeovimQt::NeovimConnector::NoError);
	connect(m_c, &NeovimQt::NeovimConnector::ready,
		[&ready](){
			ready = true;
		});
	QTest::qWait(1500);
	Q_ASSERT(ready);
}

QTEST_MAIN(TestEncoding)
#include "tst_encoding.moc"

