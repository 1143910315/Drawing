#ifndef VOIDMODEL_H
#define VOIDMODEL_H

#include "paintingmodel.h"

class VoidModel : public PaintingModel
{
public:
	VoidModel();
	int getType();
	QString getDescription();
};

#endif // VOIDMODEL_H
