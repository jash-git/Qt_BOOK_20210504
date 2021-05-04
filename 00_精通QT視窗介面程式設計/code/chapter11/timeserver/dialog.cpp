#include <QtGui>
#include <QtNetwork>
#include "dialog.h"
#include "timeserver.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),count(0)
{
    server = new TimeServer(this);
                statusLabel = new QLabel;
                reqStatusLable = new QLabel;
    quitButton = new QPushButton(tr("退出"));
    quitButton->setAutoDefault(false);

    if (!server->listen()) {
        QMessageBox::critical(this, tr("多執行緒時間伺服器"),
                              tr("無法�ㄟ呇曭A器: %1.")
                              .arg(server->errorString()));
        close();
        return;
    }

    statusLabel->setText(tr("時間伺服器運行在埠： %1.\n")
                         .arg(server->serverPort()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
                mainLayout->addWidget(reqStatusLable);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("多執行緒時間伺服器"));
}
void Dialog::showResult()
{
          reqStatusLable->setText(tr("第%1次請求完畢.\n").arg(++count));

}
