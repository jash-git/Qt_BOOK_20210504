#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "basewindow.h"
namespace Ui {
class LoginWindow;
}
typedef enum
{
    ONLINE = 1,
    ACtIVE,
    AWAY,
    BUSY,
    NOT_DISTURB,
    HIDE,
    OFFLINE
}LoginState;
class LoginWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    QPushButton *m_keyboardButton;
private:
    void initMyTitle();
    void initWindow();
};

#endif // LOGINWINDOW_H
