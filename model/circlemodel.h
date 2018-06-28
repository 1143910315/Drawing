#ifndef CIRCLEMODEL_H
#define CIRCLEMODEL_H

#include "paintingmodel.h"

class CircleModel : public PaintingModel
{
	Q_OBJECT
public:
	CircleModel(qreal x,qreal y,qreal r);
	CircleModel(qreal x,qreal y,qreal w,qreal h);
	~CircleModel();
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
	qreal x=0;
	qreal y=0;
	qreal w=0;
	qreal h=0;
	qreal maxX=0;
	qreal maxY=0;
	qreal maxW=0;
	qreal maxH=0;
	void addBoundingRect(qreal newX,qreal newY,qreal newW,qreal newH);
};

#endif // CIRCLEMODEL_H
