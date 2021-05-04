#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableview = new QTableView(this);
    tableview->setGeometry(QRect(50,50,310,200));
    model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0,new QStandardItem("数学"));
    model->setHorizontalHeaderItem(1,new QStandardItem("语文"));
    model->setHorizontalHeaderItem(2,new QStandardItem("外语"));

    //行数据 0 行,0 列
    model->setItem(0,0,new QStandardItem("数学 A"));
    model->setItem(0,1,new QStandardItem("语文 A"));
    model->setItem(0,2,new QStandardItem("外语 A"));
    model->setItem(1,0,new QStandardItem("数学 B"));
    model->setItem(1,1,new QStandardItem("语文 B"));
    model->setItem(1,2,new QStandardItem("外语 B"));
    //将数据模型绑定控件
    tableview->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}
