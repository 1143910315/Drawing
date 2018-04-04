#include "datalistmodel.h"

DataListModel::DataListModel()
{
}

int DataListModel::rowCount(const QModelIndex &parent) const
{
	if(!parent.isValid() && model!=NULL){
		return model->getData().count();
	}
	return 0;
}

QVariant DataListModel::data(const QModelIndex &index, int role) const
{
	if(model!=NULL && index.isValid()){
		int row = index.row();
		QStringList list=model->getData();
		if(row>=0 && row < list.count() && role == Qt::DisplayRole){
			return QVariant(list.at(row));
		}
	}
	return QVariant();
}

Qt::ItemFlags DataListModel::flags(const QModelIndex &index) const
{
	if(!index.isValid()){
		return Qt::ItemIsEnabled;
	}
	return QAbstractListModel::flags(index) | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void DataListModel::setPaintingModel(PaintingModel *m)
{
	if(model!=NULL){
		beginRemoveRows(QModelIndex(),0,rowCount());
		disconnect(model,SIGNAL(updateData(PaintingModel*)),this,SLOT(updateData(PaintingModel*)));
		model=NULL;
		endRemoveRows();
	}
	if(m!=NULL){
		QStringList list=m->getData();
		if(!list.isEmpty()){
			int row=m->getData().count();
			beginInsertRows(QModelIndex(),0,row-1);
			model=m;
			endInsertRows();
		}
	}
	if(model!=NULL){
		connect(model,SIGNAL(updateData(PaintingModel*)),this,SLOT(updateData(PaintingModel*)));
	}
}

void DataListModel::updateData(PaintingModel *paintingModel)
{
	if(paintingModel == model){
		emit dataChanged(index(0),index(rowCount()-1));
	}else if(paintingModel == NULL){
		setPaintingModel();
	}
}
