#ifndef SELECTABLELISTVIEW_H
#define SELECTABLELISTVIEW_H

#include <QListView>

class SelectableListView : public QListView
{
public:
	explicit SelectableListView(QWidget *parent = Q_NULLPTR);
	explicit SelectableListView(QListViewPrivate &v,QWidget *parent = Q_NULLPTR);

	// QAbstractItemView interface
protected slots:
	void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
	//void rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end);
};

#endif // SELECTABLELISTVIEW_H
