#include "selectablelistview.h"

SelectableListView::SelectableListView(QWidget *parent):QListView(parent)
{

}

SelectableListView::SelectableListView(QListViewPrivate &v, QWidget *parent):QListView(v,parent)
{

}



void SelectableListView::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
	/*
	QString string;
	string.append("(");
	for(int i=0;i<selected.count();i++){
		string.append("(");
		for(int j=0;j<selected.at(i).indexes().count();j++){
			string.append(" "+QString::number(selected.at(i).indexes().at(j).row())+" ");
		}
		string.append(")");
	}
	string.append(")");
	string.append("(");
	for(int i=0;i<deselected.count();i++){
		string.append("(");
		for(int j=0;j<deselected.at(i).indexes().count();j++){
			string.append(" "+QString::number(deselected.at(i).indexes().at(j).row())+" ");
		}
		string.append(")");
	}
	string.append(")");
	char*  ch;
	QByteArray ba = string.toLatin1(); // must
	ch=ba.data();
	qDebug(ch);
*/

	/*
	QString string;
	string.append("debug1   ");
	QModelIndexList list=QListView::selectedIndexes();
	for(int i=0;i<list.count();i++){
		string.append(QString::number(list.at(i).row())+"  ");
	}
	char*  ch;
	QByteArray ba = string.toLatin1(); // must
	ch=ba.data();
	qDebug(ch);
*/

	emit indexesMoved(QListView::selectedIndexes());
	QListView::selectionChanged(selected,deselected);
}
/*
void SelectableListView::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end)
{

	QString string;
	string.append("debug2   ");
	QModelIndexList list=QListView::selectedIndexes();
	for(int i=0;i<list.count();i++){
		string.append(QString::number(list.at(i).row())+"  ");
	}
	char*  ch;
	QByteArray ba = string.toLatin1(); // must
	ch=ba.data();
	qDebug(ch);

	QListView::rowsAboutToBeRemoved(parent,start,end);

	QString string1;
	string1.append("debug3   ");
	QModelIndexList list1=QListView::selectedIndexes();
	for(int i=0;i<list1.count();i++){
		string1.append(QString::number(list1.at(i).row())+"  ");
	}
	char*  ch1;
	QByteArray ba1 = string1.toLatin1(); // must
	ch1=ba1.data();
	qDebug(ch1);
}
*/
