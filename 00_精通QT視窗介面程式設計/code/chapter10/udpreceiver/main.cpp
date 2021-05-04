#include <QtCore>
#include <QObject>
#include "receiver.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
        QTextCodec::setCodecForTr( QTextCodec::codecForName("big5"));
	Receiver receiver;
	return app.exec();
}
