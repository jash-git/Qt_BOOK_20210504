
#include "qsqlconnectiondialog.h"
#include <QtCore>
#include <QtGui>
#include <QtSql>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
    ConnDlg dialog;
    if (dialog.exec() != QDialog::Accepted)
        return -1;

    return app.exec();
}
