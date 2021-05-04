#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    treeView = new QTreeView(this);
    treeView ->setGeometry(QRect(50,50,200,200));
    model = new QStandardItemModel(3,2);
    model->setHeaderData(0,Qt::Horizontal,"diyilie");
    model->setHeaderData(1,Qt::Horizontal,"dierlie");
    //node
    QStandardItem *item1 = new QStandardItem("math");
    item1->setIcon(QIcon(":/new/prefix1/folder"));

    QStandardItem *item2 = new QStandardItem("Chinese");
    item2->setIcon(QIcon(":/new/prefix1/folder"));

    QStandardItem *item3 = new QStandardItem("English");
    item3->setIcon(QIcon(":/new/prefix1/folder"));

    QStandardItem *item4 = new QStandardItem("ChineseA");
    item4->setIcon(QIcon(":/new/prefix1/folder"));
    item2->appendRow(item4);

    model->setItem(0,0,item1);
    model->setItem(1,0,item2);
    model->setItem(2,0,item3);

    treeView->setModel(model);
}


MainWindow::~MainWindow()
{
    delete ui;
}
