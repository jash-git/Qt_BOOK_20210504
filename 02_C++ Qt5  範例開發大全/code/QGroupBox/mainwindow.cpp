#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    box = new QGroupBox(this);
    box->setGeometry(QRect(30,30,340,100));
    box->setTitle("yuyinlanmu");

    button = new QPushButton();
    button->setText("button");

    vbox = new QVBoxLayout;
    vbox->addWidget(button);

    box->setLayout(vbox);
}

MainWindow::~MainWindow()
{
    delete ui;
}
