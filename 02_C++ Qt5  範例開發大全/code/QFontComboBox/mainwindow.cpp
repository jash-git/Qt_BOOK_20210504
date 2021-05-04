#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fontCombox = new QFontComboBox(this);
    button = new QPushButton(this);
    label = new QLabel(this);
    label ->setGeometry(QRect(50,150,300,25));
    button->setText("button");
    button->move(180,50);
    connect(button,SIGNAL(released()),this,SLOT(txtButton()));

}
void MainWindow::txtButton()
{
    label->setText("choose font:"+fontCombox->currentText());
}
MainWindow::~MainWindow()
{
    delete ui;
}
