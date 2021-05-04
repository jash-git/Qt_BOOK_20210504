#include <QtGui/QApplication>
#include <QtCore/QTextCodec>

#include "findfileform.h"

int main(int argc, char* argv[])
{
        QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
        Q_INIT_RESOURCE(findfile);

        CFindFileForm form;
        form.show();

        return app.exec();
}
