#ifndef VOIDMODEL_H
#define VOIDMODEL_H

#include "paintingmodel.h"

class VoidModel : public PaintingModel
{
	Q_OBJECT
public:
	VoidModel();
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

#endif // VOIDMODEL_H
