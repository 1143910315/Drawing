#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
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

private:
	Ui::MainWindow *ui;
	PaintingListModel *model;
	QGraphicsScene graphicsScene;
	RectModel* confine;
	//QGraphicsItem confine;
};

#endif // MAINWINDOW_H
