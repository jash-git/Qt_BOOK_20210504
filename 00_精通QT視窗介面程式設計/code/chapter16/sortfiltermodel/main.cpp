#include <QtGui>

#include "score.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    Score scoreWin;
    scoreWin.show();
    return app.exec();
}
