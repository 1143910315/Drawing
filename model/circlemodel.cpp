#include "circlemodel.h"
#include <QRegExp>
#include <qdebug.h>
CircleModel::CircleModel(qreal x, qreal y, qreal r):x(x),y(y),w(r*2),h(r*2)
{
	addBoundingRect(x,y,r*2,r*2);
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
	painter->drawEllipse(x,y,w,h);
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
