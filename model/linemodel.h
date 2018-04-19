#ifndef LINEMODEL_H
#define LINEMODEL_H

#include "paintingmodel.h"

class LineModel : public PaintingModel
{
	Q_OBJECT
public:
	LineModel(qreal pointX1,qreal pointY1,qreal pointX2,qreal pointY2);
	int getType();
	QString getDescription();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QStringList getData();
	QStringList getAttribute(int dataIndex);
	QStringList getValue(int dataIndex);
	int setValue(int dataIndex, int attrIndex, const QString &data);
	QString getErrorMessage(int errorCode);
private:
	qreal pointX1;
	qreal pointY1;
	qreal pointX2;
	qreal pointY2;
	qreal maxX;
	qreal maxY;
	qreal maxW=0;
	qreal maxH=0;
	void addBoundingRect(qreal pX1,qreal pY1,qreal pX2,qreal pY2);
};

#endif // LINEMODEL_H
