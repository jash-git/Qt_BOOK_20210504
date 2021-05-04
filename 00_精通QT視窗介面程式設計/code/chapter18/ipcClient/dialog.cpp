#include "dialog.h"
#include <QFileDialog>
#include <QBuffer>
#include <QtCore/QDebug>


Dialog::Dialog(QWidget *parent)
  : QDialog(parent), sharedMemory("shareMemory")
{
    ui.setupUi(this);
        socket = new QLocalSocket(this);
        connect(socket, SIGNAL(readyRead()), this, SLOT(loadFromSocket()));
        connect(socket, SIGNAL(error(QLocalSocket::LocalSocketError)),
                this, SLOT(displayError(QLocalSocket::LocalSocketError)));
    connect(ui.localSockPB, SIGNAL(clicked()), SLOT(connectToSocket()));
    connect(ui.shareMemPB,SIGNAL(clicked()),SLOT(loadFromMemory()));

}

void Dialog::connectToSocket()
{
        socket->abort();
        socket->connectToServer("image");

}

void Dialog::loadFromSocket()
{
        QDataStream in(socket);
        QImage image;
        in >> image;
        ui.imageLabel->setPixmap(QPixmap::fromImage(image));

}

void Dialog::loadFromMemory()
{
    if (!sharedMemory.attach())
    {
        ui.imageLabel->setText(tr("�L�k���[��@�ɰO����"));
        return;
    }

    QBuffer buffer;
    QDataStream in(&buffer);
    QImage image;

    sharedMemory.lock();
    buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
    buffer.open(QBuffer::ReadOnly);
    in >> image;
    sharedMemory.unlock();

    detach();
    ui.imageLabel->setPixmap(QPixmap::fromImage(image));
}

void Dialog::detach()
{
    if (!sharedMemory.detach())
        ui.imageLabel->setText(tr("�L�k�����@�ɰO����C"));
}

void Dialog::displayError(QLocalSocket::LocalSocketError socketError)
{
        switch (socketError)
        {
                case QLocalSocket::ConnectionRefusedError:
                        ui.imageLabel->setText(tr("�s���Q�ڵ��ζW�ɡC"));
                        break;
                case QLocalSocket::PeerClosedError:
                        ui.imageLabel->setText(tr("���A��socket�s�������C"));
                        break;
                case QLocalSocket::ServerNotFoundError:
                        ui.imageLabel->setText(tr("�����W��image��local socket�C"));
                        break;
                case QLocalSocket::SocketAccessError:
                        ui.imageLabel->setText(tr("local socket�X�ݿ��~�C"));
                        break;
                case QLocalSocket::SocketResourceError:
                        ui.imageLabel->setText(tr("�D���귽�ӺɡC"));
                        break;
                case QLocalSocket::SocketTimeoutError:
                        ui.imageLabel->setText(tr("socket�W�ɡC"));
                        break;
                case QLocalSocket::DatagramTooLargeError:
                        ui.imageLabel->setText(tr("����W���C"));
                        break;
                case QLocalSocket::ConnectionError:
                        ui.imageLabel->setText(tr("�s�����ѡC"));
                        break;
                case QLocalSocket::UnsupportedSocketOperationError:
                        ui.imageLabel->setText(tr("local socket�D�k�ާ@�C"));
                        break;
                case QLocalSocket::UnknownSocketError:
                        ui.imageLabel->setText(tr("���~���������C"));
                        break;
                default:
                        ui.imageLabel->setText(tr("local socket���~%1.")	.arg(socket->errorString()));
        }

}
