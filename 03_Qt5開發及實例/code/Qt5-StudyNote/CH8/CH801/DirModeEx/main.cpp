#include "mainwindow.h"
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDirModel model;											//(a)
    /* 新建三种不同的View对象，以便文件目录可以以三种不同的方式显示 */
    QTreeView tree;
    QListView list;
    QTableView table;
    tree.setModel(&model);										//(b)
    list.setModel(&model);
    table.setModel(&model);
    tree.setSelectionMode(QAbstractItemView::MultiSelection);	//(c)
    list.setSelectionModel(tree.selectionModel());				//(d)
    table.setSelectionModel(tree.selectionModel());				//(e)
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&list,
                           SLOT(setRootIndex(QModelIndex)));
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&table,
                           SLOT(setRootIndex(QModelIndex)));	//(f)
    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);
    splitter->setWindowTitle(QObject::tr("Model/View"));
    splitter->show();

    //MainWindow w;
    //w.show();

    return a.exec();
}
