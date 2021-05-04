#include <QtGui>
#include <QtNetwork>

#include <stdlib.h>

#include "server.h"
#include <qlocalserver.h>
#include <qlocalsocket.h>

Server::Server(QWidget *parent)
    : QDialog(parent),sharedMemory("shareMemory")
{
    statusLabel = new QLabel;
    quitButton = new QPushButton(tr("退出"));
    quitButton->setAutoDefault(false);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    createLocalServer();
    createShareMemory();

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

}

void Server::createLocalServer()
{
    if (!imageSocket.load(":/files/monkey_on.png"))
    {
        statusLabel->setText(tr("無法打開文件"));
        return;
    }
        server = new QLocalServer(this);
        if (!server->listen("image")) {
                QMessageBox::critical(this, tr("image local server"),
                                                          tr("無法�ㄟ呇曭A器 : %1.")
                                                          .arg(server->errorString()));
                close();
                return;
        }
        statusLabel->setText(tr("服務已�ㄟ佢n"
                                                        "可運行客戶端！"));
        connect(server, SIGNAL(newConnection()), this, SLOT(sendImage()));
}


void Server::createShareMemory()
{
//    if (sharedMemory.isAttached())
//        detach();

    if (!imageMemory.load(":/files/monkey_off.png"))
    {
        statusLabel->setText(tr("無法打開文件"));
        return;
    }

    // load into shared memory
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << imageMemory;
    int size = buffer.size();

    if (!sharedMemory.create(size))
    {
        statusLabel->setText(tr("無法建立共享區。"));
        return;
    }
    sharedMemory.lock();
    char *to = (char*)sharedMemory.data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(sharedMemory.size(), size));
    sharedMemory.unlock();
}


void Server::sendImage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << imageSocket;

    QLocalSocket *clientConnection = server->nextPendingConnection();
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    clientConnection->write(block);
    clientConnection->flush();
    clientConnection->disconnectFromServer();
}

//void Server::detach()
//{
//    if (!sharedMemory.detach())
//    	statusLabel->setText(tr("無法分離共享記憶體。"));
//}

