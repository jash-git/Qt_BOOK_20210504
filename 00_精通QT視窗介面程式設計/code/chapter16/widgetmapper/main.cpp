#include <QApplication>

#include "mapwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    MapWidget mapWidget;
    mapWidget.show();
    return app.exec();
}
