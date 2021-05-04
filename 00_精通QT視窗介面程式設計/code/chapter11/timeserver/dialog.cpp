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
    quitButton = new QPushButton(tr("�h�X"));
    quitButton->setAutoDefault(false);

    if (!server->listen()) {
        QMessageBox::critical(this, tr("�h������ɶ����A��"),
                              tr("�L�k���ʦ��A��: %1.")
                              .arg(server->errorString()));
        close();
        return;
    }

    statusLabel->setText(tr("�ɶ����A���B��b��G %1.\n")
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

    setWindowTitle(tr("�h������ɶ����A��"));
}
void Dialog::showResult()
{
          reqStatusLable->setText(tr("��%1���ШD����.\n").arg(++count));

}
