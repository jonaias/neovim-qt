#ifndef NEOVIM_QT_GUI_BASEWINDOW
#define NEOVIM_QT_GUI_BASEWINDOW

#include <QSet>
#include <QVariant>
#include <QString>


namespace NeovimQt {

class BaseWindow
{

public:

	static QList<QSet<QString> > attrsToMap(const QString& text, const QVariantMap& attrs);

	virtual uint64_t windowId()=0;
	virtual void redrawCursor(uint64_t col, uint64_t row)=0;
	virtual void redrawRuler(const QVariantMap& m)=0;
	virtual void redrawStatusLine(const QVariantMap& m)=0;
	virtual void updateLine(uint64_t row, const QVariantList& line,
		 		const QVariantMap& attrs)=0;
	virtual void insertLine(uint64_t row_index, uint64_t count)=0;
	virtual void deleteLine(uint64_t row_index, uint64_t count)=0;
	virtual void redrawLayout(uint64_t height, uint64_t width)=0;
	virtual void setForegroundColor(const QString&)=0;
	virtual void setBackgroundColor(const QString&)=0;
	virtual void windowEnded(uint64_t row, uint64_t endrow,
			const QString& marker, const QString& fill)=0;
	virtual void redrawStart()=0;
	virtual void redrawEnd()=0;
};

} // namespace

#endif
