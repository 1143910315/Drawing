#ifndef VOIDMODEL_H
#define VOIDMODEL_H

#include "paintingmodel.h"

class VoidModel : public PaintingModel
{
public:
	VoidModel();
	int getType();
	QString getDescription();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QStringList getData();
};

#endif // VOIDMODEL_H
