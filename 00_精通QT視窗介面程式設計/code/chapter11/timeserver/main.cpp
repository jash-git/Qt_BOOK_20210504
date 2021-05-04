
#include <QApplication>
#include <QtCore>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
                QTextCodec::setCodecForTr( QTextCodec::codecForName("big5"));
    Dialog dialog;
    dialog.show();
    return dialog.exec();
}
