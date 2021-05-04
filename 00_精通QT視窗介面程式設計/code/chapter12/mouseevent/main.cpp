

#include <QApplication>
#include <QtCore>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr( QTextCodec::codecForName("big5"));
    MainWindow window;
    window.show();
    return app.exec();
}
