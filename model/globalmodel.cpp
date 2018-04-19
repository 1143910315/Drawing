#include "globalmodel.h"
GlobalModel::GlobalModel(QGraphicsScene *scene):scene(scene)
{
	setSceneRect(0,0,200,200);
}

GlobalModel::~GlobalModel()
{

}

int GlobalModel::getType()
{
	return 2;//全局设置
}

QString GlobalModel::getDescription()
{
	return "图片信息";
}

QRectF GlobalModel::boundingRect() const
{
	return QRectF(x-10,y-10,w+20,h+20);
}

void GlobalModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	for(int i=0;i<10;i++){
		painter->setPen(QPen(QColor(255-i*255/9,255-i*255/9,255-i*255/9)));
		//painter->setBrush(QBrush(QColor(255/(10-i),255/(10-i),255/(10-i))));
		//painter->drawRect(x-10+i,y-10+i,w+20-i*2,h+20-i*2);
		painter->drawLine(x-10+i,y-10+i,x+w+10-i,y-10+i);
		painter->drawLine(x+w+10-i,y-10+i,x+w+10-i,y+h+10-i);
		painter->drawLine(x-10+i,y+h+10-i,x+w+10-i,y+h+10-i);
		painter->drawLine(x-10+i,y-10+i,x-10+i,y+h+10-i);
	}
	//消除警告
	(void)option;
	(void)widget;
}

QStringList GlobalModel::getData()
{
	QStringList list;
	list.append(tr("起点( %0, %1 )").arg(x,0,'f',1).arg(y,0,'f',1));
	list.append(tr("宽高( %0, %1 )").arg(w,0,'f',1).arg(h,0,'f',1));
	return list;
}

QStringList GlobalModel::getAttribute(int dataIndex)
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
		list.append(tr("像素点"));
		break;
	default:
		break;
	}
	return list;
}

QStringList GlobalModel::getValue(int dataIndex)
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
		list.append(QString::asprintf("%0.0f",w*h));
		break;
	default:
		break;
	}
	return list;
}

int GlobalModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	bool isNumber=false;
	QRegExp reg("^(-)?([0-9])+(\\.([0-9])+)?$");
	if(reg.indexIn(data)==0){
		isNumber=true;
	}
	switch (dataIndex) {
	case 0:
		if(isNumber){
			switch (attrIndex) {
			case 0:
				x=data.toDouble();
				setSceneRect(x,y,w,h);
				emit updateData(this);
				emit update();
				break;
			case 1:
				y=data.toDouble();
				setSceneRect(x,y,w,h);
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
		switch (attrIndex) {
		case 0:
			if(isNumber){
				w=data.toDouble();
				setSceneRect(x,y,w,h);
				emit updateData(this);
				emit update();
			}else{
				return 1;
			}
			break;
		case 1:
			if(isNumber){
				h=data.toDouble();
				setSceneRect(x,y,w,h);
				emit updateData(this);
				emit update();
			}else{
				return 1;
			}
			break;
		case 2:
			return 2;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

QString GlobalModel::getErrorMessage(int errorCode)
{
	switch (errorCode) {
	case 1:
		return tr("请输入数字。");
		break;
	case 2:
		return tr("不可修改！只读属性！");
		break;
	default:
		break;
	}
	return QString();
}

void GlobalModel::addItem(PaintingModel *model)
{
	scene->addItem(model);
}

void GlobalModel::removeItem(PaintingModel *model)
{
	scene->removeItem(model);
}

void GlobalModel::setSceneRect(qreal x, qreal y, qreal w, qreal h)
{
	scene->setSceneRect(x-1,y-1,w+2,h+2);
	this->x=x;
	this->y=y;
	this->w=w;
	this->h=h;
	emit changeSceneRect();
}

void GlobalModel::getSceneRect(qreal &x, qreal &y, qreal &w, qreal &h)
{
	x=this->x;
	y=this->y;
	w=this->w;
	h=this->h;
}
