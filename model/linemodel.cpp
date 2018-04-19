#include "linemodel.h"
//#include <QtMath>
LineModel::LineModel(qreal pointX1, qreal pointY1, qreal pointX2, qreal pointY2):pointX1(pointX1),pointY1(pointY1),pointX2(pointX2),pointY2(pointY2)
{
	addBoundingRect(pointX1,pointY1,pointX2,pointY2);
}

int LineModel::getType()
{
	return 3;//线
}

QString LineModel::getDescription()
{
	return QString::asprintf("线：( %0.1f, %0.1f, %0.1f, %0.1f )",pointX1,pointY1,pointX2,pointY2);
}

QRectF LineModel::boundingRect() const
{
	//重画区域
	return QRectF(maxX,maxY,maxW,maxH);
}

void LineModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawLine(pointX1,pointY1,pointX2,pointY2);
	addBoundingRect(pointX1,pointY1,pointX2,pointY2);
	//消除警告
	(void)option;
	(void)widget;
}

QStringList LineModel::getData()
{
	QStringList list;
	list.append(tr("A( %0, %1 )").arg(pointX1,0,'f',1).arg(pointY1,0,'f',1));
	list.append(tr("B( %0, %1 )").arg(pointX2,0,'f',1).arg(pointY2,0,'f',1));
	list.append(tr("长度( %0 )").arg(sqrt(pow(abs(pointX2-pointX1)+1,2)+pow(abs(pointY2-pointY1)+1,2)),0,'f',1));
	return list;
}

QStringList LineModel::getAttribute(int dataIndex)
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
		list.append(tr("长度"));
		break;
	default:
		break;
	}
	return list;
}

QStringList LineModel::getValue(int dataIndex)
{
	QStringList list;
	switch (dataIndex) {
	case 0:
		list.append(QString::asprintf("%f",pointX1));
		list.append(QString::asprintf("%f",pointY1));
		break;
	case 1:
		list.append(QString::asprintf("%f",pointX2));
		list.append(QString::asprintf("%f",pointY2));
		break;
	case 2:
		list.append(QString::asprintf("%f",sqrt(pow(abs(pointX2-pointX1)+1,2)+pow(abs(pointY2-pointY1)+1,2))));
		break;
	default:
		break;
	}
	return list;
}

int LineModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	bool isNumber=false;
	QRegExp reg("^(-)?([0-9])+(\\.([0-9])+)?$");
	if(reg.indexIn(data)==0){
		isNumber=true;
	}
	double d;
	qreal a,b,c;
	switch (dataIndex) {
	case 0:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				d=data.toDouble();
				addBoundingRect(d,pointY1,pointX2,pointY2);
				pointX1=d;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				addBoundingRect(pointX1,d,pointX2,pointY2);
				pointY1=d;
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
				addBoundingRect(pointX1,pointY1,d,pointY2);
				pointX2=d;
				emit updateData(this);
				emit update();
				break;
			case 1:
				d=data.toDouble();
				addBoundingRect(pointX1,pointY1,pointX2,d);
				pointY2=d;
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
			d=data.toDouble();
			c=sqrt(pow(abs(pointX2-pointX1)+1,2)+pow(abs(pointY2-pointY1)+1,2));
			a=d*(pointY2-pointY1)/c;
			b=d*(pointX2-pointX1)/c;
			addBoundingRect(pointX1,pointY1,pointX2+b,pointY1+a);
			pointX2=pointX1+b;
			pointY2=pointY1+a;
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
}

QString LineModel::getErrorMessage(int errorCode)
{
	switch (errorCode) {
	case 1:
		return tr("请输入数字。");
		break;
	default:
		break;
	}
	return QString();
}

void LineModel::addBoundingRect(qreal pX1,qreal pY1,qreal pX2,qreal pY2)
{
	qreal maxLeft,maxRight,maxTop,maxBottom;
	if(maxW==0 && maxH==0){
		if(pX1<pX2){
			maxX=pX1;
			maxW=pX2-pX1+1;
		}else{
			maxX=pX2;
			maxW=pX1-pX2+1;
		}
		if(pY1<pY2){
			maxY=pY1;
			maxH=pY2-pY1+1;
		}else{
			maxY=pY2;
			maxH=pY1-pY2+1;
		}
		return;
	}
	maxLeft=pX1<pX2?pX1:pX2;
	maxLeft=maxLeft<pointX1?maxLeft:pointX1;
	maxLeft=maxLeft<pointX2?maxLeft:pointX2;
	maxTop=pY1<pY2?pY1:pY2;
	maxTop=maxTop<pointY1?maxTop:pointY1;
	maxTop=maxTop<pointY2?maxTop:pointY2;
	maxRight=pX1>pX2?pX1:pX2;
	maxRight=maxRight>pointX1?maxRight:pointX1;
	maxRight=maxRight>pointX2?maxRight:pointX2;
	maxBottom=pY1>pY2?pY1:pY2;
	maxBottom=maxBottom>pointY1?maxBottom:pointY1;
	maxBottom=maxBottom>pointY2?maxBottom:pointY2;
	maxX=maxLeft;
	maxW=maxRight-maxLeft+1;
	maxY=maxTop;
	maxH=maxBottom-maxTop+1;
	/*
	maxX=pX1;
	maxY=pY1;
	maxW=abs(pX1-pX2+1);
	maxH=abs(pY1-pY2+1);
	*/
}
