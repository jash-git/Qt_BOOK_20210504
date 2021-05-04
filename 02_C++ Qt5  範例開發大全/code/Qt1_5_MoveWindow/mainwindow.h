#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QPushButton>
#include <QMainWindow>

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
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QPushButton *btClose;
    QPoint last;
};

#endif // MAINWINDOW_H
