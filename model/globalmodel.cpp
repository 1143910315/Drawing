#include "globalmodel.h"

GlobalModel::GlobalModel()
{

}

int GlobalModel::getType()
{
	return 2;//全局设置
}

QString GlobalModel::getDescription()
{
	return "无数据";
}

QRectF GlobalModel::boundingRect() const
{
	return QRectF();
}

void GlobalModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//消除警告
	(void)painter;
	(void)option;
	(void)widget;
}

QStringList GlobalModel::getData()
{
	return QStringList();
}

QStringList GlobalModel::getAttribute(int dataIndex)
{
	(void)dataIndex;
	return QStringList();
}

QStringList GlobalModel::getValue(int dataIndex)
{
	(void)dataIndex;
	return QStringList();
}

int GlobalModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	(void)dataIndex;
	(void)attrIndex;
	(void)data;
	return 0;
}

QString GlobalModel::getErrorMessage(int errorCode)
{
	(void)errorCode;
	return QString();
}
