

#ifndef QUERYMAINWINDOW_H
#define QUERYMAINWINDOW_H

#include <QMainWindow>

#include "ui_querywidget.h"

//! [0]
class QueryMainWindow : public QMainWindow,
                        private Ui::QueryWidget
{
    Q_OBJECT

  public:
    QueryMainWindow();

  public slots:
    void displayDefaultQuery();
    void displayQuery();

  private:
    //QComboBox* ui_defaultQueries;

    void evaluate(const QString &str);
    void loadInputFile();
};
//! [0]
#endif
