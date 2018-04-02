#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVariant>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//QString str="在我右边";
	QStringList current_cloud_id_list;
	//current_cloud_id_list.push_back(str);
	model = new QStringListModel(this);
	model->setStringList(current_cloud_id_list);
	ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{

	int rowCount=model->rowCount();
	model->insertRow(rowCount);
	model->setData(model->index(rowCount),ui->lineEdit->text());
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
	model->removeRows(index,1);
/*
	QStringListModel *model=(QStringListModel *)ui->listView->model();
	QStringList string_list=model->stringList();
	int index=ui->lineEdit_2->text().toInt();
	string_list.removeAt(index);
	model->setStringList(string_list);
*/
}
