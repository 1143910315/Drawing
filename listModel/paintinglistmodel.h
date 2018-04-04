#ifndef PAINTINGLISTMODEL_H
#define PAINTINGLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "model\paintingmodel.h"
#include "model/globalmodel.h"
class PaintingListModel : public QAbstractListModel
{
	Q_OBJECT
public:
	PaintingListModel();
	int rowCount(const QModelIndex &parent= QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	void insertData(int index, PaintingModel *data);
	void removeData(int index);
	PaintingModel *getData(int index);
	bool getSceneRect(qreal &x,qreal &y,qreal &w,qreal &h);
public slots:
	void updateData(PaintingModel* paintingModel);
private:
	QList<PaintingModel *> list;
	GlobalModel *globalModel=NULL;
};

#endif // PAINTINGLISTMODEL_H
