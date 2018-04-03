#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QStringListModel>
#include "rectmodel.h"
#include "paintinglistmodel.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
protected:
	//void mouseMoveEvent(QMouseEvent *event);
private slots:
	void receiveMouseMove(QMouseEvent *event);
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();

	//void on_listView_clicked(const QModelIndex &index);

	//void on_listView_indexesMoved(const QModelIndexList &indexes);

	//void on_listView_2_indexesMoved(const QModelIndexList &indexes);

	//void on_listView_pressed(const QModelIndex &index);


	void on_listView_indexesMoved(const QModelIndexList &indexes);

private:
	Ui::MainWindow *ui;
	PaintingListModel *model;
	QGraphicsScene graphicsScene;
	RectModel* confine;
	//QGraphicsItem confine;

	// QWidget interface
protected:
	//void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
