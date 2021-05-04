#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
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
    QSystemTrayIcon *myTrayIcon;
    QMenu *myMenu;
    QAction *restoreWinAction;
    QAction *quitAction;
    void createMenu();
private slots:
    void showjj();
};

#endif // MAINWINDOW_H
