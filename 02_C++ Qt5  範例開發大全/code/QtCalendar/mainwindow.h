#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QCalendarWidget>
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
    QLabel *label;
    QLineEdit *lineEdit;
    QCalendarWidget *calendarWidget;
private slots:
    void showTime();
    void setData();
};

#endif // MAINWINDOW_H
