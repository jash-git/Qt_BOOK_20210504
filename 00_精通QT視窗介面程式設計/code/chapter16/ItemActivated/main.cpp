#include <QtGui>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

    MyWidget myWidget;
    myWidget.show();
    
    return app.exec();
}
