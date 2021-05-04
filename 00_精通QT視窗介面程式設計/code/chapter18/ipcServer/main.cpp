

#include <QApplication>
#include <QtCore>
#include <stdlib.h>
#include "server.h"

int main(int argc, char *argv[])
{

	Q_INIT_RESOURCE(ipcServer);
    QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    Server server;
    server.show();
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return server.exec();
}
