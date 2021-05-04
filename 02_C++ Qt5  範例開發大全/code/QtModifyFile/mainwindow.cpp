#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edit = new QTextEdit(this);
    edit->setGeometry(QRect(50,50,240,26));

    browseBt = new QPushButton(this);
    browseBt->setGeometry(QRect(290,50,80,25));
    browseBt->setText("浏览文件");

    connect(browseBt,SIGNAL(clicked(bool)),this,SLOT(browseFile()));

    //显示文件内容
    content = new QTextEdit(this);
    content->setGeometry(QRect(50,80,320,150));
    //修改完毕后，保存文件
    saveBt = new QPushButton(this);
    saveBt->setGeometry(QRect(290,240,80,25));

    saveBt->setText("保存");
    connect(saveBt,SIGNAL(clicked()),this,SLOT(saveFile()));

}
//浏览文件
void MainWindow::browseFile()
{
//定义变量 str 接收 QFileDialog 对话框获取的文件路径
QString str = QFileDialog::getOpenFileName(this,"open file","/","textfile(*.txt);;C file(*.cpp);;All file(*.*)");
//将变量绑定 QTextEdit 控件
edit->setText(str.toUtf8());
//判断是否选择文件
if(edit->toPlainText().isEmpty())
{
return;
}
QFile file(edit->toPlainText());
//判断文件是否打开成功
if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
{
QMessageBox::warning(this,"打开文件","打开文件失败！");
return;
}
QTextStream ts(&file);
//循环文档数据至结尾
while(!ts.atEnd())
{
//将全部数据绑定至 content 控件
content->setPlainText(ts.readAll());
}
//关闭文档
file.close();
}
//保存文件
void MainWindow::saveFile()
{
QFile file(edit->toPlainText());
file.open(QIODevice::ReadWrite | QIODevice::Text);
//写入内容,这里需要转码，否则报错。
QByteArray str = content->toPlainText().toUtf8();
//写入 QByteArray 格式字符串
file.write(str);
//提示成功
QMessageBox::warning(this,"修改文件","文件修改成功！");
file.close();

}
MainWindow::~MainWindow()
{
    delete ui;
}
