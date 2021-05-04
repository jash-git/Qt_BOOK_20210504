#include <QtGui>

#include "delegate.h"

void populateData(QTableWidget& table)
{
    table.setItem(0, 0, new QTableWidgetItem(QObject::tr("�L�L��")));
    table.setItem(1, 0, new QTableWidgetItem(QObject::tr("�v��")));
    table.setItem(2, 0, new QTableWidgetItem(QObject::tr("���_��")));
    table.setItem(3, 0, new QTableWidgetItem(QObject::tr("�뤸�K")));

    table.setItem(0, 1, new QTableWidgetItem(QObject::tr("1980/2/3")));
    table.setItem(1, 1, new QTableWidgetItem(QObject::tr("1981/10/24")));
    table.setItem(2, 1, new QTableWidgetItem(QObject::tr("1978/5/15")));
    table.setItem(3, 1, new QTableWidgetItem(QObject::tr("1979/8/29")));

    table.setItem(0, 2, new QTableWidgetItem(QObject::tr("165")));
    table.setItem(1, 2, new QTableWidgetItem(QObject::tr("168")));
    table.setItem(2, 2, new QTableWidgetItem(QObject::tr("162")));
    table.setItem(3, 2, new QTableWidgetItem(QObject::tr("163")));

    table.setItem(0, 3, new QTableWidgetItem(QObject::tr("�x�_")));
    table.setItem(1, 3, new QTableWidgetItem(QObject::tr("�x��")));
    table.setItem(2, 3, new QTableWidgetItem(QObject::tr("�x�n")));
    table.setItem(3, 3, new QTableWidgetItem(QObject::tr("�x�F")));
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

    QTableWidget table(3,4);
    QStringList labels;
    labels << QObject::tr("�m�W") << QObject::tr("�X�ͤ��") << QObject::tr("����") << QObject::tr("�X�ͦa");
    table.setHorizontalHeaderLabels(labels);

    EditorDelegate delegate;
    table.setItemDelegate(&delegate);

    populateData(table);

    table.setWindowTitle(QObject::tr("�N�z�d��"));
    table.resize(640,480);
    table.show();
    return app.exec();
}
