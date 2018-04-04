#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QStringListModel>
#include "model\rectmodel.h"
#include "listModel/paintinglistmodel.h"
#include "listModel/datalistmodel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
private slots:
	void receiveMouseMove(QMouseEvent *event);
	void statusTextNeedUpdate();
	void cellChanged(int row, int column);
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_listView_indexesMoved(const QModelIndexList &indexes);
	void on_listView_2_indexesMoved(const QModelIndexList &indexes);
private:
	Ui::MainWindow *ui;
	PaintingListModel *model=NULL;
	DataListModel *dataModel=NULL;
	QPointF mousePoint;
};

#endif // MAINWINDOW_H
