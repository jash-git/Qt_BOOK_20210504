#include <QtGui>

#include "delegate.h"

void populateData(QTableWidget& table)
{
    table.setItem(0, 0, new QTableWidgetItem(QObject::tr("林黛玉")));
    table.setItem(1, 0, new QTableWidgetItem(QObject::tr("史湘雲")));
    table.setItem(2, 0, new QTableWidgetItem(QObject::tr("薛寶釵")));
    table.setItem(3, 0, new QTableWidgetItem(QObject::tr("賈元春")));

    table.setItem(0, 1, new QTableWidgetItem(QObject::tr("1980/2/3")));
    table.setItem(1, 1, new QTableWidgetItem(QObject::tr("1981/10/24")));
    table.setItem(2, 1, new QTableWidgetItem(QObject::tr("1978/5/15")));
    table.setItem(3, 1, new QTableWidgetItem(QObject::tr("1979/8/29")));

    table.setItem(0, 2, new QTableWidgetItem(QObject::tr("165")));
    table.setItem(1, 2, new QTableWidgetItem(QObject::tr("168")));
    table.setItem(2, 2, new QTableWidgetItem(QObject::tr("162")));
    table.setItem(3, 2, new QTableWidgetItem(QObject::tr("163")));

    table.setItem(0, 3, new QTableWidgetItem(QObject::tr("台北")));
    table.setItem(1, 3, new QTableWidgetItem(QObject::tr("台中")));
    table.setItem(2, 3, new QTableWidgetItem(QObject::tr("台南")));
    table.setItem(3, 3, new QTableWidgetItem(QObject::tr("台東")));
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

    QTableWidget table(3,4);
    QStringList labels;
    labels << QObject::tr("姓名") << QObject::tr("出生日期") << QObject::tr("身高") << QObject::tr("出生地");
    table.setHorizontalHeaderLabels(labels);

    EditorDelegate delegate;
    table.setItemDelegate(&delegate);

    populateData(table);

    table.setWindowTitle(QObject::tr("代理範例"));
    table.resize(640,480);
    table.show();
    return app.exec();
}
