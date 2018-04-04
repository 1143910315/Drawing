#include "voidmodel.h"

VoidModel::VoidModel()
{

}

int VoidModel::getType()
{
	return 0;//无数据
}

QString VoidModel::getDescription()
{
	return "无数据";
}

QRectF VoidModel::boundingRect() const
{
	return QRectF();
}

void VoidModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//消除警告
	(void)painter;
	(void)option;
	(void)widget;
}

QStringList VoidModel::getData()
{
	return QStringList();
}

QStringList VoidModel::getAttribute(int dataIndex)
{
	(void)dataIndex;
	return QStringList();
}

QStringList VoidModel::getValue(int dataIndex)
{
	(void)dataIndex;
	return QStringList();
}

int VoidModel::setValue(int dataIndex, int attrIndex, const QString &data)
{
	(void)dataIndex;
	(void)attrIndex;
	(void)data;
	return 0;
}

QString VoidModel::getErrorMessage(int errorCode)
{
	(void)errorCode;
	return QString();
}
