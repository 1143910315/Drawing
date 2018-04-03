#include "rectmodel.h"

RectModel::RectModel(qreal x, qreal y, qreal w, qreal h):x(x),y(y),w(w),h(h)
{

}

int RectModel::getType()
{
	return 1;//矩形
}

QString RectModel::getDescription()
{
	return QString::asprintf("矩形：(%0.2f,%0.2f,%0.2f,%0.2f)",x,y,w,h);
}

QRectF RectModel::boundingRect() const
{
	//重画区域
	return QRectF(x,y,w,h);
}

void RectModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawRect(QRectF(x,y,w,h));
	//消除警告
	(void)option;
	(void)widget;
}
