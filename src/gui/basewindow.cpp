#include "basewindow.h"
#include <QDebug>

namespace NeovimQt {

/**
 * Neovim sends us a list of attributes and a text range where they
 * should be applied - this method breaks down the ranges into a map
 * between each char position and the attributes to be applied
 *
 *     attrsToMap({attr:[range_pos]}) -> [[attr1,attr2], ...]
 *
 * You can use this if you need to do char-by-char rendering
 */
QList<QSet<QString> > BaseWindow::attrsToMap(const QString& text, const QVariantMap& attrs)
{
	QList<QSet<QString> > attrMap;
	for (int j=0; j<text.size(); j++) {
		attrMap.append(QSet<QString>());
	}

	for (int i=0; i<attrs.keys().size(); i++) {
		QVariantList targets = attrs.value(attrs.keys().at(i)).toList();
		foreach(QVariant target, targets) {
			// Either a range [1,2) or an integer (1) == [1,2)
			uint64_t start, end;
			if (target.canConvert<quint64>()) {
				// FIXME: Is this the right way
				start = target.toLongLong();
				end = start + 1;
			} else if ((QMetaType::Type)target.type() == QMetaType::QVariantList &&
					target.toList().size() == 2 &&
					target.toList().at(0).canConvert<quint64>() &&
					target.toList().at(1).canConvert<quint64>()) {

				start = target.toList().at(0).toLongLong();
				end = target.toList().at(1).toLongLong();
			} else {
				qWarning() << "Invalid line attribute";
				continue;
			}

			for (uint64_t j=0; j<(uint64_t)text.size(); j++) {
				if (j >= start && j < end) {
					attrMap[j].insert(attrs.keys().at(i));
				}
			}
		}
	}
	return attrMap;
}

}
