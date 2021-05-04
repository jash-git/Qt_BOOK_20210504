#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTabWidget *tabWidget;
};
class tabA:public QWidget
{
    Q_OBJECT
 public:
    tabA(QWidget *parent=0);
};
class tabB:public QWidget
{
    Q_OBJECT
 public:
    tabB(QWidget *parent=0);
};

#endif // MAINWINDOW_H
