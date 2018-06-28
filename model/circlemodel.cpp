#include "circlemodel.h"
#include <QRegExp>
#include <qdebug.h>
CircleModel::CircleModel(qreal x, qreal y, qreal r):x(x-r),y(y-r),w(r*2),h(r*2)
{
	addBoundingRect(x-r,y-r,r*2,r*2);
}

CircleModel::CircleModel(qreal x, qreal y, qreal w, qreal h):x(x),y(y),w(w),h(h)
{
	addBoundingRect(x,y,w,h);
}

CircleModel::~CircleModel()
{

}

int CircleModel::getType()
{
	return 4;//圆形||椭圆
}

QString CircleModel::getDescription()
{
	if(w==h){
		return QString::asprintf("圆形：( %0.1f, %0.1f, %0.1f )",x+w/2,y+w/2,w/2);
	}else{
		return QString::asprintf("椭圆：( %0.1f, %0.1f, %0.1f, %0.1f )",x,y,w,h);
	}
}

QRectF CircleModel::boundingRect() const
{
	//重画区域
	return QRectF(maxX,maxY,maxW,maxH);
}

void CircleModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawEllipse(x,y,w,h);
	addBoundingRect(x,y,w,h);
	//消除警告
	(void)option;
	(void)widget;
}

QStringList CircleModel::getData()
{
	QStringList list;
	list.append(tr("位置( %0, %1 )").arg(x,0,'f',1).arg(y,0,'f',1));
	list.append(tr("宽高( %0, %1 )").arg(w,0,'f',1).arg(h,0,'f',1));
	list.append(tr("圆心( %0, %1 )").arg(x+w/2,0,'f',1).arg(y+h/2,0,'f',1));
	if(w==h){
		list.append(tr("半径( %0 )").arg(w/2,0,'f',1));
	}
	return list;
}

QStringList CircleModel::getAttribute(int dataIndex)
{
	QStringList list;
	switch (dataIndex) {
	case 0:
		list.append(tr("横坐标"));
		list.append(tr("纵坐标"));
		break;
	case 1:
		list.append(tr("宽度"));
		list.append(tr("高度"));
		break;
	case 2:
		list.append(tr("圆心横坐标"));
		list.append(tr("圆心纵坐标"));
		break;
	case 3:
		if(w==h){
			list.append(tr("半径"));
		}
		break;
	default:
		break;
	}
	return list;
}

QStringList CircleModel::getValue(int dataIndex)
{
	QStringList list;
	switch (dataIndex) {
	case 0:
		list.append(QString::asprintf("%f",x));
		list.append(QString::asprintf("%f",y));
		break;
	case 1:
		list.append(QString::asprintf("%f",w));
		list.append(QString::asprintf("%f",h));
		break;
	case 2:
		list.append(QString::asprintf("%f",x+w/2));
		list.append(QString::asprintf("%f",y+h/2));
		break;
	case 3:
		if(w==h){
			list.append(QString::asprintf("%f",w/2));
		}
		break;
	default:
		break;
	}
	return list;
}

int CircleModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	bool isNumber=false;
	QRegExp reg("^(-)?([0-9])+(\\.([0-9])+)?$");
	if(reg.indexIn(data)==0){
		isNumber=true;
	}
	double d;
	qreal ox,oy;
	switch (dataIndex) {
	case 0:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				addBoundingRect(d,y,w,h);
				x=d;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				addBoundingRect(x,d,w,h);
				y=d;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 1:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				addBoundingRect(x,y,d,h);
				w=d;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				addBoundingRect(x,y,w,d);
				h=d;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 2:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				addBoundingRect(d-w/2,y,w,h);
				x=d-w/2;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				addBoundingRect(x,d-h/2,w,h);
				y=d-h/2;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 3:
		if(isNumber&&w==h){
			ox=x+w/2;
			oy=y+h/2;
			d=data.toDouble();
			addBoundingRect(ox-d,oy-d,2*d,2*d);
			x=ox-d;
			y=oy-d;
			w=2*d;
			h=2*d;
			emit updateData(this);
			emit update();

		}else{
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
	return 0;
}

QString CircleModel::getErrorMessage(int errorCode)
{
	return QString();
}

void CircleModel::addBoundingRect(qreal newX, qreal newY, qreal newW, qreal newH)
{
	maxX=newX<x?newX:x;
	maxY=newY<y?newY:y;
	maxW=newX+newW>x+w?newX+newW-maxX:x+w-maxX;
	maxH=newY+newH>y+h?newY+newH-maxY:y+h-maxY;
}
