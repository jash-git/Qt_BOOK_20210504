#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <mainwindow2.h>

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
    QPushButton *button;
    MainWindow2 w2;
private slots:
    void showMainWindow2();
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
