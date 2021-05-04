#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button = new QPushButton(this);
    button -> setGeometry(QRect(50,50,100,25));
    button->setText("button");
    connect(button,SIGNAL(clicked(bool)),this,SLOT(showMainWindow2()));
}
void MainWindow::showMainWindow2()
{
    w2.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
