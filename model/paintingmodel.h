#ifndef PAINTINGMODEL_H
#define PAINTINGMODEL_H

#include <QString>
#include <QGraphicsItem>
#include <QPainter>
#include <QStringList>
class PaintingModel :public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	virtual int getType()=0; //获得图案类型
	//0：无图案（voidmodel）
	//1：矩形（rectmodel）
	//2：全局设置（globalmodel）
	//3：线（linemodel）
	virtual QString getDescription()=0; //获得图案描述
	virtual QStringList getData()=0;//获得图案数据
	virtual QStringList getAttribute(int dataIndex)=0;//获得数据的属性
	virtual QStringList getValue(int dataIndex)=0;//获得数据的数值
	virtual int setValue(int dataIndex,int attrIndex,const QString &data)=0;//设置数据的属性的值，成功返回0，失败返回非0
	virtual QString getErrorMessage(int errorCode)=0;
signals:
	void updateData(PaintingModel* paintingModel);
};

#endif // PAINTINGMODEL_H
