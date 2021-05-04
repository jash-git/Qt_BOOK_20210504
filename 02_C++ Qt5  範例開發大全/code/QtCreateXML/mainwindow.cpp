#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QXmlStreamWriter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    explainL = new QLabel(this);
    explainL->setText("这里就不重复写类似 txt 读写的布局了，直接在代码\n中填写节点等操作.文件路径：testXML.xml \n根节点：Root");
    explainL->setGeometry(QRect(50,50,300,100));
    createBt = new QPushButton(this);
    createBt->setText("创建 XML 文件");
    createBt->setGeometry(QRect(50,180,100,25));
    connect(createBt,SIGNAL(clicked()),this,SLOT(createFile()));
}
void MainWindow::createFile()
{
    //absolute path
    //QString xmlPath = "/home/mxq/Codes/qtpro/QtCreateXML/testXML.xml";
    //realtive path . relative to build folder
    QString xmlPath = "./testXML.xml";
    QFile file(xmlPath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QXmlStreamWriter stream(&file);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartDocument("Root");
        stream.writeAttribute("href", "http://qt.nokia.com/");
        //节点内容
        stream.writeTextElement("title", "Qt Home");
        stream.writeEndElement();
        stream.writeEndDocument();
        //关闭文件
        file.close();

    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
