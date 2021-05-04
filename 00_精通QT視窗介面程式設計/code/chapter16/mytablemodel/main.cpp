#include <QtGui>

#include "weaponmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

    WeaponModel model;

    QTableView view;
    view.setModel(&model);
    view.setWindowTitle(QObject::tr("自定義模型"));
    view.resize(640,480);
    view.show();
    return app.exec();
}
