#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Qt5.10.1 Windows Applications");
    this->setMaximumSize(300,300);
    this->setMinimumSize(300,300);
    this->move(100,100);
    this->setStyleSheet("background:red");
}

MainWindow::~MainWindow()
{
    delete ui;
}
