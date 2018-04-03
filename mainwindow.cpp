#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>
#include <QItemSelectionModel>
#include "voidmodel.h"
#include <qdebug.h>

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
	//connect(ui->listView->selectionMode(),SIGNAL(s));
	//ui->listView_2->setSelectionMode();
	//ui->listView->setSelectionModel(new QItemSelectionModel());
	//ui->listView_2->setSelectionModel(new QItemSelectionModel());
	//connect(ui->listView,SIGNAL());


	ui->listView_2->setModel(new QStringListModel());
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
	//ui->listWidget->insertItem(1,QList);
}



/*void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{
	qDebug("Test3");
	int row=indexes.first().row();
	PaintingModel* p=model->getData(row);
	QStringListModel * m=(QStringListModel*)ui->listView_2->model();
	m->setStringList(p->getData());
}
*/
/*
void MainWindow::on_listView_clicked(const QModelIndex &index)
{
	qDebug("Test4");
	int row=index.row();
	PaintingModel* p=model->getData(row);
	QStringListModel * m=(QStringListModel*)ui->listView_2->model();
	m->setStringList(p->getData());
}
*/

void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{
	/*
	QString string;
	for(int i=0;i<indexes.count();i++){
		string.append(QString::number(indexes.at(i).row())+"  ");
	}
	char*  ch;
	QByteArray ba = string.toLatin1(); // must
	ch=ba.data();
	qDebug(ch);
	*/

	/*
	QString string;
	string.append("debug4   ");
	QModelIndexList list=ui->listView->selectionModel()->selectedIndexes();
	for(int i=0;i<list.count();i++){
		string.append(QString::number(list.at(i).row())+"  ");
	}
	char*  ch;
	QByteArray ba = string.toLatin1(); // must
	ch=ba.data();
	qDebug(ch);
	*/

	if(indexes.isEmpty()==false){
		int row=indexes.first().row();
		PaintingModel* p=model->getData(row);
		QStringListModel * m=(QStringListModel*)ui->listView_2->model();
		m->setStringList(p->getData());
	}
}

/*
void MainWindow::on_listView_2_indexesMoved(const QModelIndexList &indexes)
{
	qDebug("Test6");
}
*/
/*
void MainWindow::on_listView_pressed(const QModelIndex &index)
{
	//qDebug("Test5");
	int row=index.row();
	PaintingModel* p=model->getData(row);
	QStringListModel * m=(QStringListModel*)ui->listView_2->model();
	m->setStringList(p->getData());
}
*/
/*
void MainWindow::keyPressEvent(QKeyEvent *event)
{
	qDebug("Test8");
}
*/
/*
void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
	qDebug("Test7");
}
*/

