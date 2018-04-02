#include "paintinglistmodel.h"

PaintingListModel::PaintingListModel()
{

}

int PaintingListModel::rowCount(const QModelIndex &parent) const
{
	if(parent.isValid()){
		return 0;
	}
	return list.count();
}

QVariant PaintingListModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid()){
		return QVariant();
	}
	int row = index.row();
	if(row >= list.count() || row<0){
		return QVariant();
	}
	if(role == Qt::DisplayRole){
		return QVariant(list.at(row)->getDescription());
	}
	/*
	if(role == Qt::EditRole){
		return QVariant::fromValue(list.at(row));
	}
*/
	return QVariant();
}


Qt::ItemFlags PaintingListModel::flags(const QModelIndex &index) const
{
	/*
	if(!index.isValid())
		return Qt::ItemIsEnabled;
	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
*/
	if(!index.isValid())
		return Qt::ItemIsEnabled;
	return QAbstractListModel::flags(index) | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void PaintingListModel::insertData(int index, PaintingModel *data)
{
	list.insert(index,data);
}

void PaintingListModel::removeData(int index)
{
	list.removeAt(index);
}

PaintingModel *PaintingListModel::getData(int index)
{
	return list.at(index);
}










