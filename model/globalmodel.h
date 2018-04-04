#ifndef GLOBALMODEL_H
#define GLOBALMODEL_H

#include "paintingmodel.h"

class GlobalModel : public PaintingModel
{
	Q_OBJECT
public:
	GlobalModel();
	int getType();
	QString getDescription();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QStringList getData();
	QStringList getAttribute(int dataIndex);
	QStringList getValue(int dataIndex);
	int setValue(int dataIndex, int attrIndex, const QString &data);
	QString getErrorMessage(int errorCode);
};

#endif // GLOBALMODEL_H
