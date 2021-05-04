
#include <QApplication>
#include <QtCore>
#include "digitdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
        QTextCodec::setCodecForTr( QTextCodec::codecForName("big5"));
    Digital digit;
    digit.show();
    return app.exec();
}
