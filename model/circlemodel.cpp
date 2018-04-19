#include "circlemodel.h"
#include <QRegExp>
#include <qdebug.h>
CircleModel::CircleModel(qreal x, qreal y, qreal r):x(x),y(y),r(r)
{
	addBoundingRect(x-r,y-r,x+r,y+r);
}

CircleModel::~CircleModel()
{

}

int CircleModel::getType()
{
	return 4;//圆形
}

QString CircleModel::getDescription()
{
	return QString::asprintf("圆形：( %0.1f, %0.1f, %0.1f, %0.1f )",x,y,w,h);
}

QRectF CircleModel::boundingRect() const
{
	//重画区域
	return QRectF(maxX,maxY,maxW,maxH);
}

void CircleModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//消除警告
	(void)option;
	(void)widget;
}

QStringList CircleModel::getData()
{
	QStringList list;
	return list;
}

QStringList CircleModel::getAttribute(int dataIndex)
{
	QStringList list;
	return list;
}

QStringList CircleModel::getValue(int dataIndex)
{
	QStringList list;
	return list;
}

int CircleModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	return 0;
}

QString CircleModel::getErrorMessage(int errorCode)
{
	return QString();
}

void CircleModel::addBoundingRect(qreal newX, qreal newY, qreal newW, qreal newH)
{

}
