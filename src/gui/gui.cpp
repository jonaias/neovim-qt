#include "gui.h"

#include "windowwidget.h"

namespace NeovimQt {

Gui::Gui(NeovimConnector *n, QObject *parent)
:BaseGui(n, parent)
{
	// FIXME: root widget, margins, etc
	m_widget = new QSplitter();
}

void Gui::handleRedrawLayout(const QVariantMap& m)
{
	QString type = m.value("type").toString();
	// FIXME: remove layout
	/*
	if (type == "column") {
		m_root_layout = new QVBoxLayout(m_widget);
		foreach(const QVariant v, m.value("children").toList()) {
			handleRedrawLayout(v.toMap(), m_root_layout);
		}
	} else if (type == "row") {
		m_root_layout = new QHBoxLayout(m_widget);
		foreach(const QVariant v, m.value("children").toList()) {
			handleRedrawLayout(v.toMap(), m_root_layout);
		}
	} else if (type == "leaf") {
		handleRedrawLayout(m, m_root_layout);	
	}*/

	handleRedrawLayout(m, m_widget);	
	m_widget->show();
}

/**
 * Recursive layout builder
 */
void Gui::handleRedrawLayout(const QVariantMap& m, QSplitter *splitter)
{
	QString type = m.value("type").toString();
	if (type == "column") {
		QSplitter *column = new QSplitter(Qt::Vertical);
		splitter->addWidget(column);
		foreach(const QVariant v, m.value("children").toList()) {
			handleRedrawLayout(v.toMap(), column);
		}
	} else if (type == "row") {
		QSplitter *row = new QSplitter();
		splitter->addWidget(row);
		foreach(const QVariant v, m.value("children").toList()) {
			handleRedrawLayout(v.toMap(), row);
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
			m_windows.insert(window, w);
		}
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
