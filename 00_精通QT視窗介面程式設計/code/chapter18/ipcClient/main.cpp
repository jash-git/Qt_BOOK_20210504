
#include <QApplication>
#include <QtCore>
#include "dialog.h"

//! [0]
int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    Dialog dialog;
    dialog.show();
    return application.exec();
}
//! [0]

