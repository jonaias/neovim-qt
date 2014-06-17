#include "gui.h"

namespace NeovimQt {


BaseGui::BaseGui(NeovimConnector *connector, QObject *parent)
:QObject(parent), m_nc(connector)
{
	connect(m_nc, &NeovimConnector::ready,
			this, &BaseGui::neovimReady);
	connect(m_nc, &NeovimConnector::notification,
			this, &BaseGui::neovimNotification);
	//connect(m_nc->neovimObject(), &Neovim::on_vim_get_windows);
}

void BaseGui::neovimReady()
{
	m_nc->neovimObject()->vim_subscribe("redraw:*");
	m_nc->neovimObject()->vim_subscribe("redraw:insert_line");
	m_nc->neovimObject()->vim_subscribe("redraw:delete_line");
	m_nc->neovimObject()->vim_subscribe("redraw:status_line");
	m_nc->neovimObject()->vim_subscribe("redraw:ruler");
	m_nc->neovimObject()->vim_subscribe("redraw:cursor");
	m_nc->neovimObject()->vim_subscribe("redraw:layout");
	m_nc->neovimObject()->vim_subscribe("redraw:tabs");
	m_nc->neovimObject()->vim_subscribe("redraw:update_line");
	m_nc->neovimObject()->vim_subscribe("redraw:foreground_color");
	m_nc->neovimObject()->vim_subscribe("redraw:background_color");
	m_nc->neovimObject()->vim_subscribe("redraw:win_end");
	// Ask Neovim to redraw everything for us
	m_nc->neovimObject()->vim_request_screen();
}

void BaseGui::handleRedrawCursor(const QVariantMap& m)
{
	if ( !m.contains("col") || !m.contains("row") || 
			!m.value("col").canConvert<quint64>() ||
			!m.value("row").canConvert<quint64>()) {
		qWarning() << "Invalid event for redraw:cursor" << m;
		return;
	}

	uint64_t col = m.value("col").toLongLong();
	uint64_t row = m.value("row").toLongLong();

	emit redrawCursor(col, row);
}
void BaseGui::handleRedrawRuler(const QVariantMap& m)
{
	// FIXME: do something w/ the ruler
}

void BaseGui::handleRedrawUpdateLine(const QVariantMap& m)
{
	if (!m.value("window_id").canConvert<quint64>()) {
		qWarning() << "Received redraw:update_line event with invalid window_id";
		return;
	}
	uint64_t window = m.value("window_id").toLongLong();

	if (!m.value("row").canConvert<quint64>()) {
		qWarning() << "Received redraw:update_line event with invalid row";
		return;
	}
	uint64_t row = m.value("row").toLongLong();

	if (!m.value("line").type() == QMetaType::QVariantList ) {
		qWarning() << "Received redraw:update_line event without a line";
		return;
	}

	QVariantMap attrs;
	if (m.contains("attributes")) {
		// attributes are OPTIONAL
		attrs = m.value("attributes").toMap();
	}

	// FIXME: consider moving this out of each method
	if (hasWindow(window)) {
		getWindow(window)->updateLine(row, m.value("line").toList(), attrs);
	} else {
		qWarning() << "Received event" << __func__ << "for unknown window";
	}
}

void BaseGui::handleRedrawInsertLine(const QVariantMap& m)
{
	if (!m.value("window_id").canConvert<quint64>()) {
		qWarning() << "Received redraw:insert_line event with invalid window_id";
		return;
	}
	uint64_t window = m.value("window_id").toLongLong();

	if (!m.value("row").canConvert<quint64>()) {
		qWarning() << "Received redraw:insert_line event with invalid row";
		return;
	}
	uint64_t row = m.value("row").toLongLong();

	if (!m.value("count").canConvert<quint64>()) {
		qWarning() << "Received redraw:insert_line event with invalid count";
		return;
	}
	uint64_t count = m.value("count").toLongLong();

	// FIXME
	if (hasWindow(window)) {
		getWindow(window)->insertLine(row, count);
	}
}

void BaseGui::handleRedrawDeleteLine(const QVariantMap& m)
{
	if (!m.value("window_id").canConvert<quint64>()) {
		qWarning() << "Received redraw:insert_line event with invalid window_id";
		return;
	}
	uint64_t window = m.value("window_id").toLongLong();

	if (!m.value("row").canConvert<quint64>()) {
		qWarning() << "Received redraw:delete_line event with invalid row";
		return;
	}
	uint64_t row = m.value("row").toLongLong();

	if (!m.value("count").canConvert<quint64>()) {
		qWarning() << "Received redraw:delete_line event with invalid count";
		return;
	}
	uint64_t count = m.value("count").toLongLong();

	// FIXME
	if (hasWindow(window)) {
		getWindow(window)->deleteLine(row, count);
	}
}

/**
 * Neovim informs us of the window layout and the dimensions of each
 * window
 *
 * To implement your own GUI widgets/layout you should override this
 * method @see setWindow
 */


void BaseGui::handleRedrawForegroundColor(const QVariantMap& m)
{
	// FIXME
	foreach(uint64_t id, windows()) {
		getWindow(id)->setForegroundColor(m.value("color").toString());
	}
}

void BaseGui::handleRedrawBackgroundColor(const QVariantMap& m)
{
	// FIXME
	foreach(uint64_t id, windows()) {
		getWindow(id)->setBackgroundColor(m.value("color").toString());
	}
}

void BaseGui::handleRedrawWinEnd(const QVariantMap& m)
{
	if (!m.value("window_id").canConvert<uint64_t>()) {
		qWarning() << "Received redraw:win_end event with invalid window_id";
		return;
	}
	uint64_t window_id = m.value("window_id").toLongLong();

	if (!m.value("row").canConvert<uint64_t>()) {
		qWarning() << "Received redraw:win_end event with invalid row";
		return;
	}
	uint64_t row = m.value("row").toLongLong();

	if (!m.value("endrow").canConvert<uint64_t>()) {
		qWarning() << "Received redraw:win_end event with invalid endrow";
		return;
	}
	uint64_t endrow = m.value("endrow").toLongLong();

	if (!m.value("marker").canConvert<QString>()) {
		qWarning() << "Received redraw:win_end event with invalid marker";
		return;
	}
	QString marker = m.value("marker").toString();

	if (!m.value("fill").canConvert<QString>()) {
		qWarning() << "Received redraw:win_end event with invalid fill";
		return;
	}
	QString fill = m.value("fill").toString();

	// FIXME
	if (hasWindow(window_id)) {
		getWindow(window_id)->windowEnded(row, endrow, marker, fill);
	}
}

void BaseGui::neovimNotification(const QByteArray& name, const QVariant& args)
{
	if (name == "redraw:cursor") {
		handleRedrawCursor(args.toMap());
		return;
	} else if (name == "redraw:ruler") {
		handleRedrawRuler(args.toMap());
		return;
	} else if (name == "redraw:update_line") {
		handleRedrawUpdateLine(args.toMap());
		return;
	} else if (name == "redraw:insert_line") {
		handleRedrawInsertLine(args.toMap());
		return;
	} else if (name == "redraw:delete_line") {
		handleRedrawDeleteLine(args.toMap());
		return;
	} else if (name == "redraw:layout") {
		handleRedrawLayout(args.toMap());
		return;
	} else if (name == "redraw:foreground_color") {
		handleRedrawForegroundColor(args.toMap());
		return;
	} else if (name == "redraw:background_color") {
		handleRedrawBackgroundColor(args.toMap());
		return;
	} else if (name == "redraw:win_end") {
		handleRedrawWinEnd(args.toMap());
		return;
	} else {
		qWarning() << "Received unknown event" << name;
	}
}

} // Namespace

