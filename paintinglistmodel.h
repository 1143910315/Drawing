#ifndef PAINTINGLISTMODEL_H
#define PAINTINGLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "paintingmodel.h"
class PaintingListModel : public QAbstractListModel
{
public:
	PaintingListModel();
	int rowCount(const QModelIndex &parent= QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	void insertData(int index, PaintingModel *data);
	void removeData(int index);
	PaintingModel *getData(int index);
	//bool setData(const QModelIndex &index, const QVariant &value, int role);
	//bool insertRows(int row, int count, const QModelIndex &parent);
	//bool removeRows(int row, int count, const QModelIndex &parent);
	//bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild);
private:
	QList<PaintingModel *> list;
};

#endif // PAINTINGLISTMODEL_H
