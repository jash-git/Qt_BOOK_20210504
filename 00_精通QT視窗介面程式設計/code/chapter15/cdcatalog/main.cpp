
#include <QtGui>
#include "querymainwindow.h"

//! [0]
int main(int argc, char* argv[])
{
    Q_INIT_RESOURCE(cdcatalog);
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    QueryMainWindow* const queryWindow = new QueryMainWindow;
    queryWindow->show();
    return app.exec();
}
//! [0]
