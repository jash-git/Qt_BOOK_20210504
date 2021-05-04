#include <QtGui/QtGui>
#include "logindlg.h"
int main(int argc, char* argv[])
{
        QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

        QTranslator translator;
        {
                QStringList environment = QProcess::systemEnvironment();
                QString str;
                bool bFinded = false;
                foreach(str, environment) {
                        if(str.startsWith("QTDIR="))
                        {
                                bFinded = true;
                                break;
                        }
                }

                if(bFinded)
                {
                        str = str.mid(6);
                        bFinded = translator.load("qt_" + QLocale::system().name(),
                                                        str.append("/translations/"));
                        if(bFinded)
                                qApp->installTranslator(&translator);
                        else
                                qDebug() << QObject::tr("沒有支援中文的Qt國際化翻譯檔！");
                }
                else {
                        qDebug() << QObject::tr("必須設定 QTDIR 環境變數！");
                        exit(1);
                }
        }
    CLoginDlg dlg;
        return dlg.exec();
}

