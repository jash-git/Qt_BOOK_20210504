#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>
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
    QGroupBox *box;
    QPushButton *button;
    QVBoxLayout *vbox;
};

#endif // MAINWINDOW_H
