#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timeEdit = new QTimeEdit(this);
    timeEdit->setGeometry(QRect(50,50,120,25));
    QDateTime sysTime = QDateTime::currentDateTime();
    QStringList list = sysTime.toString("hh:mm:ss").split(':');
    timeEdit->setTime(QTime(list[0].toInt(),list[1].toInt(),list[2].toInt()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
