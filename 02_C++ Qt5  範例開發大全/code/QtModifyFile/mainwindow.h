#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
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
    QPushButton *browseBt;
    QPushButton *saveBt;
    QTextEdit *edit;
    QTextEdit *content;
private slots:
    void saveFile();
    void browseFile();
};

#endif // MAINWINDOW_H
