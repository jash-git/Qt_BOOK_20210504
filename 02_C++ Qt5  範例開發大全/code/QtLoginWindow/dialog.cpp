#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //窗体最小宽度高度
    setMinimumSize(280,150);
    //窗体最大宽度高度
    setMaximumSize(280,150);
    //实例用户名密码控件
    usrLabel = new QLabel(tr("用户名："));
    pwdLabel = new QLabel(tr("密 码："));
    usrLineEdit = new QLineEdit;

    pwdLineEdit = new QLineEdit;
    //密码*号输入
    pwdLineEdit->setEchoMode(QLineEdit::Password);
    //限制输入 12 位
    usrLineEdit->setMaxLength(12);
    pwdLineEdit->setMaxLength(12);
    //实例网格布局控件
    gridlayout = new QGridLayout;
    //添加布局 0,0,1,1 行 列 行间距 列间距
    gridlayout->addWidget(usrLabel,0,0,1,1);
    gridlayout->addWidget(usrLineEdit,0,1,1,1);
    //间隔
    gridlayout->setSpacing(20);
    gridlayout->addWidget(pwdLabel,1,0,1,1);
    gridlayout->addWidget(pwdLineEdit,1,1,1,1);
    //实例按钮控件
    okBtn = new QPushButton(tr("确定"));
    cancelBtn = new QPushButton(tr("取消"));
    connect(okBtn,SIGNAL(clicked()),this,SLOT(accept()));
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
    QHBoxLayout *hboxLayout = new QHBoxLayout;
    hboxLayout->setSpacing(60);
    //横向布局填充控件
    hboxLayout->addWidget(okBtn);
    hboxLayout->addWidget(cancelBtn);
    //实例纵向布局填充刚刚实例的两个布局
    vboxLayout = new QVBoxLayout;
    vboxLayout->addLayout(gridlayout);
    vboxLayout->addLayout(hboxLayout);
    //显示内容
    this->setLayout(vboxLayout);
}
//确定方法
void Dialog::accept()
{
if(usrLineEdit->text().trimmed() == "admin" && pwdLineEdit->text().trimmed() == "admin")
{
QDialog::accept();
}else
{
QMessageBox::warning(this,"警告","用户名或密码错误!!!",
QMessageBox::Yes);
usrLineEdit->setFocus();
}
}
Dialog::~Dialog()
{
    delete ui;
}
