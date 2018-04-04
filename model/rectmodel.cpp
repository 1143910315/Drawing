#include "rectmodel.h"
#include <QRegExp>
#include <qdebug.h>
RectModel::RectModel(qreal x, qreal y, qreal w, qreal h):x(x),y(y),w(w),h(h),maxX(x),maxY(y),maxW(w),maxH(h)
{

}

RectModel::~RectModel()
{
	w=h=0;
	emit update();
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
	if(w==0 && h==0){
		return ;
	}
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
	list.append(tr("A( %0, %1 )").arg(x,0,'f',1).arg(y,0,'f',1));
	list.append(tr("B( %0, %1 )").arg(x+w-1,0,'f',1).arg(y,0,'f',1));
	list.append(tr("C( %0, %1 )").arg(x+w-1,0,'f',1).arg(y+h-1,0,'f',1));
	list.append(tr("D( %0, %1 )").arg(x,0,'f',1).arg(y+h-1,0,'f',1));
	list.append(tr("宽度( %0 )").arg(w,0,'f',1));
	list.append(tr("高度( %0 )").arg(h,0,'f',1));
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
	case 4:
		list.append(tr("宽度"));
		break;
	case 5:
		list.append(tr("高度"));
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
		list.append(QString::asprintf("%f",x+w-1));
		list.append(QString::asprintf("%f",y));
		break;
	case 2:
		list.append(QString::asprintf("%f",x+w-1));
		list.append(QString::asprintf("%f",y+h-1));
		break;
	case 3:
		list.append(QString::asprintf("%f",x));
		list.append(QString::asprintf("%f",y+h-1));
		break;
	case 4:
		list.append(QString::asprintf("%f",w));
		break;
	case 5:
		list.append(QString::asprintf("%f",h));
		break;
	default:
		break;
	}
	return list;
}

int RectModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	bool isNumber=false;
	QRegExp reg("^(-)?([0-9])+(\\.([0-9])+)?$");
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
					maxW=d-x+1;
				}
				w=d-x+1;
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
					maxW=d-x+1;
				}
				w=d-x+1;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				if(d>y+h){
					maxH=d-y+1;
				}
				h=d-y+1;
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
					maxH=d-y+1;
				}
				h=d-y+1;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}
		break;
	case 4:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				if(d>w){
					maxW=d;
				}
				w=d;
				emit updateData(this);
				emit update();
				break;
			default:
				break;
			}
		}
		break;
	case 5:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				if(d>h){
					maxH=d;
				}
				h=d;
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
