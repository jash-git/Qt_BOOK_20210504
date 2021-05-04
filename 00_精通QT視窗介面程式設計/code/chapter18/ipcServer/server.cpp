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
    quitButton = new QPushButton(tr("�h�X"));
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
        statusLabel->setText(tr("�L�k���}���"));
        return;
    }
        server = new QLocalServer(this);
        if (!server->listen("image")) {
                QMessageBox::critical(this, tr("image local server"),
                                                          tr("�L�k���ʦ��A�� : %1.")
                                                          .arg(server->errorString()));
                close();
                return;
        }
        statusLabel->setText(tr("�A�Ȥw����\n"
                                                        "�i�B��Ȥ�ݡI"));
        connect(server, SIGNAL(newConnection()), this, SLOT(sendImage()));
}


void Server::createShareMemory()
{
//    if (sharedMemory.isAttached())
//        detach();

    if (!imageMemory.load(":/files/monkey_off.png"))
    {
        statusLabel->setText(tr("�L�k���}���"));
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
        statusLabel->setText(tr("�L�k�إߦ@�ɰϡC"));
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
//    	statusLabel->setText(tr("�L�k�����@�ɰO����C"));
//}

