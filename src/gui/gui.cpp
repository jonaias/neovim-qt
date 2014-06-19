#include "gui.h"

#include "windowwidget.h"

namespace NeovimQt {

Gui::Gui(NeovimConnector *n, QObject *parent)
:BaseGui(n, parent)
{
	m_widget = new QSplitter();
}

void Gui::handleRedrawLayout(const QVariantMap& m)
{
	QHash<uint64_t,WindowWidget*> new_windows;
	handleRedrawLayout(m, m_widget, new_windows);

	foreach(uint64_t window_id, m_windows.keys()) {
		if (!new_windows.contains(window_id)) {
			WindowWidget *w = m_windows.take(window_id);
			w->hide();
			w->deleteLater();
		}
	}

	m_windows = new_windows;
	m_widget->show();
}

/**
 * Recursive layout builder
 *
 */
void Gui::handleRedrawLayout(const QVariantMap& m, QSplitter *splitter,
	QHash<uint64_t,WindowWidget*>& windows)
{
	// FIXME: we are leaking memory on the splitters
	QString type = m.value("type").toString();
	if (type == "column") {
		QSplitter *column = new QSplitter(Qt::Vertical);
		splitter->addWidget(column);
		foreach(const QVariant v, m.value("children").toList()) {
			handleRedrawLayout(v.toMap(), column, windows);
		}
	} else if (type == "row") {
		QSplitter *row = new QSplitter();
		splitter->addWidget(row);
		foreach(const QVariant v, m.value("children").toList()) {
			handleRedrawLayout(v.toMap(), row, windows);
		}
	} else if (type == "leaf") {
		// We are a leaf - i.e. a window
		if (!m.value("window_id").canConvert<quint64>()) {
			qWarning() << "Received redraw:layout event with invalid window_id";
			return;
		}
		uint64_t window = m.value("window_id").toLongLong();

		if (!m.value("height").canConvert<quint64>()) {
			qWarning() << "Received redraw:layout event with invalid height";
			return;
		}
		uint64_t height = m.value("height").toLongLong();

		if (!m.value("width").canConvert<quint64>()) {
			qWarning() << "Received redraw:layout event with invalid width";
			return;
		}
		uint64_t width = m.value("width").toLongLong();

		WindowWidget *w;
		if (hasWindow(window)) {
			w = m_windows.value(window);
		} else {
			w = new WindowWidget(this, window, splitter);
		}

		windows.insert(window, w);
		splitter->addWidget(w);
		w->redrawLayout(height, width);
	} else {
		qWarning() << "Unrecognised layout node: " << type;
	}
}

BaseWindow* Gui::getWindow(uint64_t window_id)
{
	return m_windows.value(window_id);
}

bool Gui::hasWindow(uint64_t window_id)
{
	return m_windows.contains(window_id);
}

QList<uint64_t> Gui::windows()
{
	return m_windows.keys();
}

} //neovim
