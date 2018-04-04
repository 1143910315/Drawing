#include "rectmodel.h"
#include <QRegExp>
#include <qdebug.h>
RectModel::RectModel(qreal x, qreal y, qreal w, qreal h):x(x),y(y),w(w),h(h),maxX(x),maxY(y),maxW(w),maxH(h)
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
	return QRectF(maxX,maxY,maxW,maxH);;
}

void RectModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawRect(QRectF(x,y,w,h));
	maxX=x;
	maxY=y;
	maxW=w;
	maxH=h;
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

QStringList RectModel::getAttribute(int dataIndex)
{
	QStringList list;
	switch (dataIndex) {
	case 0:
		list.append(tr("横坐标"));
		list.append(tr("纵坐标"));
		break;
	case 1:
		list.append(tr("横坐标"));
		list.append(tr("纵坐标"));
		break;
	case 2:
		list.append(tr("横坐标"));
		list.append(tr("纵坐标"));
		break;
	case 3:
		list.append(tr("横坐标"));
		list.append(tr("纵坐标"));
		break;
	default:
		break;
	}
	return list;
}

QStringList RectModel::getValue(int dataIndex)
{
	QStringList list;
	switch (dataIndex) {
	case 0:
		list.append(QString::asprintf("%f",x));
		list.append(QString::asprintf("%f",y));
		break;
	case 1:
		list.append(QString::asprintf("%f",x+w));
		list.append(QString::asprintf("%f",y));
		break;
	case 2:
		list.append(QString::asprintf("%f",x+w));
		list.append(QString::asprintf("%f",y+h));
		break;
	case 3:
		list.append(QString::asprintf("%f",x));
		list.append(QString::asprintf("%f",y+h));
		break;
	default:
		break;
	}
	return list;
}

int RectModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	bool isNumber=false;
	QRegExp reg("^([0-9])+(\\.([0-9])+)?$");
	if(reg.indexIn(data)==0){
		isNumber=true;
	}
	double d;
	switch (dataIndex) {
	case 0:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				if(d<x){
					maxX=d;
					maxW=w+x-d;
				}
				w=w+x-d;
				x=d;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				if(d<y){
					maxY=d;
					maxH=h+y-d;
				}
				h=h+y-d;
				y=d;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}
		break;
	case 1:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				if(d>x+w){
					maxW=d-x;
				}
				w=d-x;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				if(d<y){
					maxY=d;
					maxH=h+y-d;
				}
				h=h+y-d;
				y=d;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}
		break;
	case 2:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				if(d>x+w){
					maxW=d-x;
				}
				w=d-x;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				if(d>y+h){
					maxH=d-y;
				}
				h=d-y;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}
		break;
	case 3:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				if(d<x){
					maxX=d;
					maxW=w+x-d;
				}
				w=w+x-d;
				x=d;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				if(d>y+h){
					maxH=d-y;
				}
				h=d-y;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
	return 0;
}

QString RectModel::getErrorMessage(int errorCode)
{
	(void)errorCode;
	return QString();
}
