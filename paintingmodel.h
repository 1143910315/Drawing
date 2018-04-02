#ifndef PAINTINGMODEL_H
#define PAINTINGMODEL_H

#include <QString>

class PaintingModel
{
public:
	virtual int getType()=0; //获得图案类型
	virtual QString getDescription()=0; //获得图案描述
};

#endif // PAINTINGMODEL_H
