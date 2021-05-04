#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
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
    QMenu *fileMenu,*editMenu,*helpMenu;
    QToolBar *fileToolBar,*editToolBar;
    QAction *newAct,*cutAct,*copyAct,*pasteAct,*aboutQtAct;
private slots:
    void newFile();
};

#endif // MAINWINDOW_H
