#include <QtGui>
#include <QtDebug>

#include "dndwidget.h"

DNDWidget::DNDWidget(QWidget * parent)
        : QTableWidget(parent)
{
        setDragEnabled(true);
        setAcceptDrops(true);
        setDropIndicatorShown(true);
        setDragDropMode(QAbstractItemView::InternalMove);
        setSelectionMode(QAbstractItemView::SingleSelection);
        setDragDropOverwriteMode(false);	// �ӿﶵ�S���ΡH

        populateTable();

        resize(800,600);
}

void DNDWidget::populateTable()
{
        setRowCount(5);
        setColumnCount(4);

    QTableWidgetItem *item = new QTableWidgetItem(tr("������"));
    setItem(0, 0, item);
    item = new QTableWidgetItem(tr("���ӯ�"));
    setItem(0, 1, item);
    item = new QTableWidgetItem(tr("�x�Z"));
    setItem(0, 2, item);
    item = new QTableWidgetItem(tr("1368"));
    setItem(0, 3, item);
    item = new QTableWidgetItem(tr("�����T"));
    setItem(1, 0, item);
    item = new QTableWidgetItem(tr("�f��"));
    setItem(1, 1, item);
    item = new QTableWidgetItem(tr("�ؤ�"));
    setItem(1, 2, item);
    item = new QTableWidgetItem(tr("1399"));
    setItem(1, 3, item);
    item = new QTableWidgetItem(tr("����"));
    setItem(2, 0, item);
    item = new QTableWidgetItem(tr("����"));
    setItem(2, 1, item);
    item = new QTableWidgetItem(tr("�ü�"));
    setItem(2, 2, item);
    item = new QTableWidgetItem(tr("1403"));
    setItem(2, 3, item);
}
