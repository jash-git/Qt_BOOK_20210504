
#include <QtGui>
#include <QtDBus>
#include "loadform.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    LoadForm loadForm;
    loadForm.show();
    return app.exec();
}
