#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //实例 QTabWidget
    tabWidget = new QTabWidget(this);
    tabWidget->setGeometry(QRect(30,30,340,140));
    tabWidget->addTab(new tabA,"A 栏目");
    tabWidget->addTab(new tabB,"B 栏目");
}
tabA::tabA(QWidget *parent):QWidget(parent)
{
QPushButton *buttonA = new QPushButton(this);
buttonA->setText("页面 A");
}
tabB::tabB(QWidget *parent):QWidget(parent)
{
QPushButton *buttonB = new QPushButton(this);
buttonB->setText("页面 B");
}
MainWindow::~MainWindow()
{
    delete ui;
}
