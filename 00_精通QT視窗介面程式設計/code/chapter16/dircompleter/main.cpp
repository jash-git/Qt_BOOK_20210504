#include <QApplication>
#include "DirWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

    DirWidget dirWidget;
    dirWidget.show();
    
    return app.exec();
}
