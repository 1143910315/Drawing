#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>
#include "voidmodel.h"
//#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//QString str="在我右边";
	QStringList current_cloud_id_list;
	//current_cloud_id_list.push_back(str);
	model = new PaintingListModel();
	model->insertData(0,new VoidModel());
	ui->listView->setModel(model);
	ui->statusBar->showMessage("横坐标:0  纵坐标:0  缩放:1  宽度:0  高度:0  鼠标横坐标:0  鼠标纵坐标:0");
	MainWindow::setMouseTracking(true);
	ui->centralWidget->setMouseTracking(true);
	ui->graphicsView->setMouseTracking(true);
	QObject::connect(ui->graphicsView,SIGNAL(mouserMove(QMouseEvent*)),this,SLOT(receiveMouseMove(QMouseEvent*)));
}

MainWindow::~MainWindow()
{
	delete ui;
}
/*
void ::mouseMoveEvent(QMouseEvent *event)
{
	ui->statusBar->showMessage(QString::asprintf("%d %d %d %d",event->globalX(), event->globalY(), event->x(), event->y()));
	QMainWindow::mouseMoveEvent(event);
}
*/
void MainWindow::on_pushButton_clicked()
{
	model->insertData(0,new VoidModel());
	/*
	int rowCount=model->rowCount();
	model->insertRow(rowCount);
	model->setData(model->index(rowCount),ui->lineEdit->text());
*/
	/*
	QStringListModel *model=(QStringListModel *)ui->listView->model();
	QStringList string_list=model->stringList();
	string_list.push_back(ui->lineEdit->text());
	model->setStringList(string_list);
*/
}

void MainWindow::on_pushButton_2_clicked()
{
	int index=ui->lineEdit_2->text().toInt();
	model->removeData(index);
	/*
	int index=ui->lineEdit_2->text().toInt();
	model->removeRows(index,1);
*/
	/*
	QStringListModel *model=(QStringListModel *)ui->listView->model();
	QStringList string_list=model->stringList();
	int index=ui->lineEdit_2->text().toInt();
	string_list.removeAt(index);
	model->setStringList(string_list);
*/
}

void MainWindow::receiveMouseMove(QMouseEvent *event)
{
	//qDebug("Test2");
	ui->statusBar->showMessage(QString::asprintf("%d %d %d %d",event->globalX(), event->globalY(), event->x(), event->y()));
	QMainWindow::mouseMoveEvent(event);
}
