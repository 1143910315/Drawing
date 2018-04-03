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
	return QString::asprintf("矩形：( %0.1f, %0.1f, %0.1f, %0.1f )",x,y,w,h);
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

QStringList RectModel::getData()
{
	QStringList list;
	list.append(QString::asprintf("A( %0.1f, %0.1f )",x,y));
	list.append(QString::asprintf("B( %0.1f, %0.1f )",x+w,y));
	list.append(QString::asprintf("C( %0.1f, %0.1f )",x+w,y+h));
	list.append(QString::asprintf("D( %0.1f, %0.1f )",x,y+h));
	return list;
}
