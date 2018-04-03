#ifndef PAINTINGMODEL_H
#define PAINTINGMODEL_H

#include <QString>
#include <QGraphicsItem>
#include <QPainter>
#include <QStringList>
class PaintingModel : public QGraphicsItem
{
public:
	virtual int getType()=0; //获得图案类型
	//0：无图案（voidmodel）
	//1：矩形（rectmodel）
	virtual QString getDescription()=0; //获得图案描述
	virtual QStringList getData()=0;
};

#endif // PAINTINGMODEL_H
