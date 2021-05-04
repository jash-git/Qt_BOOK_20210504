

#include <QtGui>
#include "imageshow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    ImagesWgt imageView;
    imageView.show();
    return app.exec();
}

