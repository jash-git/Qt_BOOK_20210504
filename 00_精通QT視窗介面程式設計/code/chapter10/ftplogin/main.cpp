#include <QtCore>
#include <QObject>
#include "ftplogin.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
        QTextCodec::setCodecForTr( QTextCodec::codecForName("big5"));
        QStringList args = app.arguments();
        if (args.count() !=2){
                qDebug()<<QObject::tr("¥Îªk: ftplogin url")<<endl
                <<QObject::tr("¨Ò:")<<endl
                <<QObject::tr(" ftplogin ftp://ftp.ntu.edu.tw");
                return -1;
                }

        FtpLogin ftpClient;
        if (!ftpClient.logIn(QUrl(args[1])))
                return -1;
        QObject::connect(&ftpClient,SIGNAL(done()),&app,SLOT(quit()));
    return app.exec();
}
