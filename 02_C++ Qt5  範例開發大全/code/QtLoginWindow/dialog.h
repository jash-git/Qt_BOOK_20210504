#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QLineEdit *usrLineEdit;
    QLineEdit *pwdLineEdit;
    QLabel *usrLabel;
    QLabel *pwdLabel;
    QGridLayout *gridlayout;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QVBoxLayout *vboxLayout;
public slots:
    virtual void accept();
};

#endif // DIALOG_H
