
#include <QApplication>
#include <QtCore>
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
        QTextCodec::setCodecForTr( QTextCodec::codecForName("big5"));
    Client client;
    client.show();
    return client.exec();
}
