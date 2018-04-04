#ifndef DATALISTMODEL_H
#define DATALISTMODEL_H

#include <QAbstractListModel>
#include "model/paintingmodel.h"
class DataListModel : public QAbstractListModel
{
	Q_OBJECT
public:
	DataListModel();
	int rowCount(const QModelIndex &parent= QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	void setPaintingModel(PaintingModel *m=NULL);
public slots:
	void updateData(PaintingModel* paintingModel);
private:
	PaintingModel *model=NULL;
};

#endif // DATALISTMODEL_H
