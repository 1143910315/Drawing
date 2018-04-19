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
	if(!index.isValid()){
		return Qt::ItemIsEnabled;
	}
	return QAbstractListModel::flags(index) | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void PaintingListModel::insertData(int index, PaintingModel *data)
{
	int type=data->getType();
	if(type==2){
		globalModel=(GlobalModel *)data;
	}
	beginInsertRows(QModelIndex(), index, index);
	if(globalModel!=NULL){
		globalModel->addItem(data);
		list.insert(index,data);
		connect(data,SIGNAL(updateData(PaintingModel*)),this,SLOT(updateData(PaintingModel*)));
	}
	endInsertRows();
}

void PaintingListModel::removeData(int index)
{
	beginRemoveRows(QModelIndex(),index,index);
	PaintingModel *m=list.at(index);
	if(m==globalModel){
		globalModel=NULL;
	}else{
		globalModel->removeItem(m);//TODO !多屏幕情况下，可能会有泄漏
	}
	list.removeAt(index);
	delete m;
	endRemoveRows();
}

PaintingModel *PaintingListModel::getData(int index)
{
	return list.at(index);
}

bool PaintingListModel::getSceneRect(qreal &x, qreal &y, qreal &w, qreal &h)
{
	if(globalModel!=NULL){
		globalModel->getSceneRect(x,y,w,h);
		return true;
	}
	return false;
}

void PaintingListModel::updateData(PaintingModel *paintingModel)
{
	int row=list.indexOf(paintingModel);
	emit dataChanged(index(row,0),index(row,0));
}





