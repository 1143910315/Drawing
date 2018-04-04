#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>
#include <QItemSelectionModel>
#include "model\voidmodel.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//QString str="在我右边";
	//QStringList current_cloud_id_list;
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
	QStringList header;
	header<<tr("属性")<<tr("值");
	ui->tableWidget->setHorizontalHeaderLabels(header);
	connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(cellChanged(int,int)));
	/*int rowCount=ui->tableWidget->rowCount();
	ui->tableWidget->insertRow(rowCount);
	ui->tableWidget->setItem(rowCount,0,new QTableWidgetItem("666"));
	ui->tableWidget->setItem(rowCount,1,new QTableWidgetItem("777"));
	rowCount=ui->tableWidget->rowCount();
	ui->tableWidget->insertRow(rowCount);
	ui->tableWidget->setItem(rowCount,0,new QTableWidgetItem("888"));
	ui->tableWidget->setItem(rowCount,1,new QTableWidgetItem("999"));
	*/
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

void MainWindow::cellChanged(int row, int column)
{
	if(column==1){
		int index=ui->listView->currentIndex().row();
		int dataIndex=ui->listView_2->currentIndex().row();
		PaintingModel *m=model->getData(index);
		m->setValue(dataIndex,row,ui->tableWidget->item(row,column)->text());//更新属性数据
		QStringList dataList=m->getData();//刷新列表数据
		QStringList valueList=m->getValue(dataIndex);//刷新表格数据
		for(int i=0;i<dataList.count();i++){
			ui->listView_2->model()->setData(ui->listView_2->model()->index(i,0),QVariant(dataList.at(i)));
		}
		//ui->listView_2->model()->setData(ui->listView_2->currentIndex(),QVariant(dataList.at(ui->listView_2->currentIndex().row())));
		disconnect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(cellChanged(int,int)));
		ui->tableWidget->setItem(row,1,new QTableWidgetItem(valueList.at(row)));
		connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(cellChanged(int,int)));
	}
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
	////这个槽用处不明，在本程序中重载了QListView的selectionChanged方法，发送信号到此槽
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




//void MainWindow::on_tableWidget_itemSelectionChanged()
//{
//	////排序会使QTableWidget的Item的row()变化
//	/*
//	QString string;
//	string.append(QString::asprintf("%d",ui->tableWidget->selectedItems().first()->row()));
//	char*  ch;
//	QByteArray ba = string.toLatin1(); // must
//	ch=ba.data();
//	qDebug(ch);
//	*/
//}

void MainWindow::on_listView_2_indexesMoved(const QModelIndexList &indexes)
{
	if(indexes.isEmpty()==false){
		int index=ui->listView->currentIndex().row();
		int dataIndex=indexes.first().row();
		PaintingModel *m=model->getData(index);
		QStringList attrList=m->getAttribute(dataIndex);
		QStringList valueList=m->getValue(dataIndex);
		disconnect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(cellChanged(int,int)));
		ui->tableWidget->clearContents();
		ui->tableWidget->setRowCount(attrList.count());
		for(int i=0;i<attrList.count();i++){
			QTableWidgetItem *item=new QTableWidgetItem(attrList.at(i));
			item->setFlags(Qt::ItemFlags::enum_type::ItemIsSelectable | Qt::ItemFlags::enum_type::ItemIsEnabled);
			ui->tableWidget->setItem(i,0,item);
			ui->tableWidget->setItem(i,1,new QTableWidgetItem(valueList.at(i)));
		}
		connect(ui->tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(cellChanged(int,int)));
	}
}
/*
void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
	QString string;
	string.append(QString::asprintf("%d %d",row,column));
	char*  ch;
	QByteArray ba = string.toLatin1(); // must
	ch=ba.data();
	qDebug(ch);
}

void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
	QString string;
	string.append(QString::asprintf("%d %d %d %d",currentRow,currentColumn,previousRow,previousColumn));
	char*  ch;
	QByteArray ba = string.toLatin1(); // must
	ch=ba.data();
	qDebug(ch);
}
*/
