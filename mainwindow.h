#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();

private:
	Ui::MainWindow *ui;
	PaintingListModel *model;
};

#endif // MAINWINDOW_H
