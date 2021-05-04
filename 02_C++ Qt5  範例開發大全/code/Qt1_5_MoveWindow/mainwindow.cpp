#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Title
    this->setWindowTitle("Move NoEdge Window");
    //cut the TitleColumn
    this->setWindowFlag(Qt::FramelessWindowHint);
    btClose = new QPushButton(this);
    btClose->setText("Close");
    connect(btClose,SIGNAL(clicked()),this,SLOT(close()));

}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
    //printf("%d,%d",last.x(),last.y());
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();

    last = e->globalPos();
    //printf("%d,%d",dx,dy);
    //move(x()+dx,y()+dy);
    //move(100,100);
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx,y()+dy);

}
MainWindow::~MainWindow()
{
    delete ui;
}
