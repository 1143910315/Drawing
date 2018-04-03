#ifndef RECTMODEL_H
#define RECTMODEL_H

#include "paintingmodel.h"

class RectModel : public PaintingModel
{
public:
	RectModel(qreal x,qreal y,qreal w,qreal h);
	int getType();
	QString getDescription();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QStringList getData();
private:
	qreal x=0;
	qreal y=0;
	qreal w=0;
	qreal h=0;



};

#endif // RECTMODEL_H
