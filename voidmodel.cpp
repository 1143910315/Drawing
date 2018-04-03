#include "voidmodel.h"

VoidModel::VoidModel()
{

}

int VoidModel::getType()
{
	return 0;
}

QString VoidModel::getDescription()
{
	return "无数据";
}

QRectF VoidModel::boundingRect() const
{
	return QRectF();
}

void VoidModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//消除警告
	(void)painter;
	(void)option;
	(void)widget;
}
