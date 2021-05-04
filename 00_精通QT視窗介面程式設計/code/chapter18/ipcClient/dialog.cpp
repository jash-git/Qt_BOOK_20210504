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
        ui.imageLabel->setText(tr("無法附加到共享記憶體"));
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
        ui.imageLabel->setText(tr("無法分離共享記憶體。"));
}

void Dialog::displayError(QLocalSocket::LocalSocketError socketError)
{
        switch (socketError)
        {
                case QLocalSocket::ConnectionRefusedError:
                        ui.imageLabel->setText(tr("連接被拒絕或超時。"));
                        break;
                case QLocalSocket::PeerClosedError:
                        ui.imageLabel->setText(tr("伺服端socket連接關閉。"));
                        break;
                case QLocalSocket::ServerNotFoundError:
                        ui.imageLabel->setText(tr("未找到名為image的local socket。"));
                        break;
                case QLocalSocket::SocketAccessError:
                        ui.imageLabel->setText(tr("local socket訪問錯誤。"));
                        break;
                case QLocalSocket::SocketResourceError:
                        ui.imageLabel->setText(tr("主機資源耗盡。"));
                        break;
                case QLocalSocket::SocketTimeoutError:
                        ui.imageLabel->setText(tr("socket超時。"));
                        break;
                case QLocalSocket::DatagramTooLargeError:
                        ui.imageLabel->setText(tr("報文超長。"));
                        break;
                case QLocalSocket::ConnectionError:
                        ui.imageLabel->setText(tr("連接失敗。"));
                        break;
                case QLocalSocket::UnsupportedSocketOperationError:
                        ui.imageLabel->setText(tr("local socket非法操作。"));
                        break;
                case QLocalSocket::UnknownSocketError:
                        ui.imageLabel->setText(tr("錯誤類型不明。"));
                        break;
                default:
                        ui.imageLabel->setText(tr("local socket錯誤%1.")	.arg(socket->errorString()));
        }

}
