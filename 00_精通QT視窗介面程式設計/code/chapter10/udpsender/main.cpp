#include <QtCore>
#include <QObject>
#include "sender.h"
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
        QTextCodec::setCodecForTr( QTextCodec::codecForName("big5"));
	Sender sender;
	sender.start();
    return app.exec();
}
