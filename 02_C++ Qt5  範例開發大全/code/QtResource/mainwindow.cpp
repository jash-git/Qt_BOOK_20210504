#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QtICOApplication");
    this->setWindowIcon(QIcon(":/new/prefix1/ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
