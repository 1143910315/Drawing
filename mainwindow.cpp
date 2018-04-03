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
	ui->graphicsView->setScene(&graphicsScene);
	graphicsScene.setSceneRect(-1,-1,201,201);
	//graphicsScene.addLine(0,0,200,200);
	confine=new RectModel(-1,-1,201,201);
	graphicsScene.addItem(confine);
	MainWindow::setMouseTracking(true);
	ui->centralWidget->setMouseTracking(true);
	ui->graphicsView->setMouseTracking(true);
	QObject::connect(ui->graphicsView,SIGNAL(mouserMove(QMouseEvent*)),this,SLOT(receiveMouseMove(QMouseEvent*)));
}

MainWindow::~MainWindow()
{
	delete ui;
	delete confine;
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
	QPointF point=ui->graphicsView->mapToScene(QPoint(event->x(),event->y()));
	QString showMessage=
			QString::asprintf("横坐标:0  ")+
			QString::asprintf("纵坐标:0  ")+
			QString::asprintf("缩放:1  ")+
			QString::asprintf("宽度:0  ")+
			QString::asprintf("高度:0  ")+
			QString::asprintf("鼠标横坐标:%0.2f  ",point.x())+
			QString::asprintf("鼠标纵坐标:%0.2f", point.y());
	//ui->graphicsView->rotate(10);

	//qDebug("Test2");
	ui->statusBar->showMessage(showMessage);
	//ui->statusBar->showMessage(QString::asprintf("%d %d", event->x(), event->y()));
	QMainWindow::mouseMoveEvent(event);
}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
	RectModel* rectmodel=new RectModel(0,0,50,50);
	graphicsScene.addItem(rectmodel);
	model->insertData(model->rowCount(),rectmodel);
}
