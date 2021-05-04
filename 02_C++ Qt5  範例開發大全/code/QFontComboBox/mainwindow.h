#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontComboBox>
#include <QPushButton>
#include <QLabel>
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
    QFontComboBox *fontCombox;
    QPushButton *button;
    QLabel *label;
private slots:
    void txtButton();
};

#endif // MAINWINDOW_H
