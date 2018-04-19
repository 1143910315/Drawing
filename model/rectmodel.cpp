#include "rectmodel.h"
#include <QRegExp>
#include <qdebug.h>
RectModel::RectModel(qreal x, qreal y, qreal w, qreal h):x(x),y(y),w(w),h(h)
{
	addBoundingRect(x,y,w,h);
}

RectModel::~RectModel()
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
	return QRectF(maxX,maxY,maxW,maxH);
}

void RectModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	if(w!=0 && h!=0){
		//painter->drawRect(QRectF(x,y,w,h));
		painter->drawLine(x,y,x+w-1,y);
		painter->drawLine(x+w-1,y,x+w-1,y+h-1);
		painter->drawLine(x+w-1,y+h-1,x,y+h-1);
		painter->drawLine(x,y+h-1,x,y);
	}
	addBoundingRect(x,y,w,h);
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
	list.append(tr("左边( %0 )").arg(x,0,'f',1));
	list.append(tr("顶边( %0 )").arg(y,0,'f',1));
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
		list.append(tr("左边"));
		break;
	case 5:
		list.append(tr("顶边"));
		break;
	case 6:
		list.append(tr("宽度"));
		break;
	case 7:
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
		list.append(QString::asprintf("%f",x));
		break;
	case 5:
		list.append(QString::asprintf("%f",y));
		break;
	case 6:
		list.append(QString::asprintf("%f",w));
		break;
	case 7:
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
	qreal acceptWidth,acceptHeight;
	switch (dataIndex) {
	case 0:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				goto moveLeft;
				break;
			case 1:
				goto moveTop;
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
				goto moveRight;
				break;
			case 1:
				goto moveTop;
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
				goto moveRight;
				break;
			case 1:
				goto moveBottom;
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 3:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				goto moveLeft;
				break;
			case 1:
				goto moveBottom;
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 4:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				goto changeRectLeft;
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 5:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				goto changeRectTop;
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 6:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				goto changeRectWidth;
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	case 7:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				goto changeRectHeight;
				break;
			default:
				break;
			}
		}else{
			return 1;
		}
		break;
	default:
		break;
	}
	return -1;
moveLeft:
	d=data.toDouble();
	acceptWidth=w+x-d;
	if(acceptWidth<0){
		acceptWidth=0;
	}
	addBoundingRect(d,y,acceptWidth,h);
	w=acceptWidth;
	x=d;
	emit updateData(this);
	emit update();
	return 0;
moveTop:
	d=data.toDouble();
	acceptHeight=h+y-d;
	if(acceptHeight<0){
		acceptHeight=0;
	}
	addBoundingRect(x,d,w,acceptHeight);
	h=acceptHeight;
	y=d;
	emit updateData(this);
	emit update();
	return 0;
moveRight:
	d=data.toDouble();
	acceptWidth=d-x+1;
	if(acceptWidth<0){
		acceptWidth=0;
	}
	addBoundingRect(x,y,acceptWidth,h);
	w=acceptWidth;
	emit updateData(this);
	emit update();
	return 0;
moveBottom:
	d=data.toDouble();
	acceptHeight=d-y+1;
	if(acceptHeight<0){
		acceptHeight=0;
	}
	addBoundingRect(x,y,w,acceptHeight);
	h=acceptHeight;
	emit updateData(this);
	emit update();
	return 0;
changeRectLeft:
	d=data.toDouble();
	addBoundingRect(d,y,w,h);
	x=d;
	emit updateData(this);
	emit update();
	return 0;
changeRectTop:
	d=data.toDouble();
	addBoundingRect(x,d,w,h);
	y=d;
	emit updateData(this);
	emit update();
	return 0;
changeRectWidth:
	d=data.toDouble();
	if(d<0){
		d=0;
	}
	addBoundingRect(x,y,d,h);
	w=d;
	emit updateData(this);
	emit update();
	return 0;
changeRectHeight:
	d=data.toDouble();
	if(d<0){
		d=0;
	}
	addBoundingRect(x,y,w,d);
	h=d;
	emit updateData(this);
	emit update();
	return 0;
}

QString RectModel::getErrorMessage(int errorCode)
{
	switch (errorCode) {
	case 1:
		return tr("请输入数字。");
		break;
	case -1:
		return tr("程序出错，参数错误！");
		break;
	default:
		break;
	}
	return QString();
}

void RectModel::addBoundingRect(qreal newX, qreal newY, qreal newW, qreal newH)
{
	if(newW==0 || newH==0){
		maxX=x;
		maxY=y;
		maxW=w;
		maxH=h;
		return;
	}
	if(w==0 || h==0){
		maxX=newX;
		maxY=newY;
		maxW=newW;
		maxH=newH;
		return;
	}
	if(newX<x){
		maxX=newX;
	}else{
		maxX=x;
	}
	if(newY<y){
		maxY=newY;
	}else{
		maxY=y;
	}
	if(newX+newW>x+w){
		maxW=newX+newW-maxX;
	}else{
		maxW=x+w-maxX;
	}
	if(newY+newH>y+h){
		maxH=newY+newH-maxY;
	}else{
		maxH=y+h-maxY;
	}
}
