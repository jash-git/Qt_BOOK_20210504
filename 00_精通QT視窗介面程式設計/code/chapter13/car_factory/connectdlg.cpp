#include "connectdlg.h"
#include "ui_connectdlg.h"

#include <QSqlDatabase>
#include <QtSql>
ConnDlg::ConnDlg(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    QStringList drivers = QSqlDatabase::drivers();
    ui.comboDriver->addItems(drivers);
    connect(ui.comboDriver,SIGNAL(currentIndexChanged( const QString & )),this,SLOT(driverChanged(const QString &)));
                ui.status_label->setText(tr("準備連接資料庫！"));
}

ConnDlg::~ConnDlg()
{
}

QString ConnDlg::driverName() const
{
    return ui.comboDriver->currentText();
}

QString ConnDlg::databaseName() const
{
    return ui.editDatabase->text();
}

QString ConnDlg::userName() const
{
    return ui.editUsername->text();
}

QString ConnDlg::password() const
{
    return ui.editPassword->text();
}

QString ConnDlg::hostName() const
{
    return ui.editHostname->text();
}

int ConnDlg::port() const
{
    return ui.portSpinBox->value();
}


void ConnDlg::on_okButton_clicked()
{
    if (ui.comboDriver->currentText().isEmpty()) {
                ui.status_label->setText(tr("請選擇一個資料庫驅動！"));
                ui.comboDriver->setFocus();
    } else if(ui.comboDriver->currentText() =="QSQLITE"){
                addSqliteConnection();
//創建資料庫表，如以存在則無須執行。
        creatDB();
                accept();
    }else{
    QSqlError err = addConnection(driverName(), databaseName(), hostName(),
                           userName(), password(), port());
    if (err.type() != QSqlError::NoError)
                        ui.status_label->setText(err.text());
                else
                        ui.status_label->setText(tr("完成資料庫連接！"));
//創建資料庫表，如以存在則無須執行。
                        creatDB();
                        accept();
    }
}

QSqlError ConnDlg::addConnection(const QString &driver, const QString &dbName, const QString &host,const QString &user, const QString &passwd, int port)
{

    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if (!db.open(user, passwd)) {
        err = db.lastError();
    }
    return err;
}

void ConnDlg::driverChanged(const QString & text)
{
        if(text =="QSQLITE")
        {
                ui.editDatabase->setEnabled(false);
                ui.editUsername->setEnabled(false);
                ui.editPassword->setEnabled(false);
                ui.editHostname->setEnabled(false);
                ui.portSpinBox->setEnabled(false);
        }
        else{
                ui.editDatabase->setEnabled(true);
                ui.editUsername->setEnabled(true);
                ui.editPassword->setEnabled(true);
                ui.editHostname->setEnabled(true);
                ui.portSpinBox->setEnabled(true);
        }
}

void ConnDlg::addSqliteConnection()
{
                QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
                db.setDatabaseName("databasefile");
                if (!db.open())
                {
                                                ui.status_label->setText(db.lastError().text());
                        return;
                }

                ui.status_label->setText(tr("完成資料庫建立！"));

}

void ConnDlg::creatDB()
{
         QSqlQuery query;
   query.exec("create table factory (id int primary key, "
                                     "manufactory varchar(40), "
                                     "address varchar(40))");
    query.exec(QObject::tr("insert into factory values(1, '大眾汽車', '台北')"));
    query.exec(QObject::tr("insert into factory values(2, '大發汽車', '台中')"));
    query.exec(QObject::tr("insert into factory values(3, '寶馬汽車', '高雄')"));

// 		query.exec("create table cars (carid int primary key, "
// 																	"name varchar(50), "
// 																	"factoryid int, "
// 																	"year int)");

    query.exec("create table cars (carid int primary key, "
                                     "name varchar(50), "
                                     "factoryid int, "
                                     "year int, "
                                                                                                                                                 "foreign key(factoryid) references factory)");
    query.exec(QObject::tr("insert into cars values(1, 'AUDI A6', 1, 2005)"));
    query.exec(QObject::tr("insert into cars values(2, 'Jetta', 1, 1993)"));
    query.exec(QObject::tr("insert into cars values(3, 'POLA', 1, 2000)"));
    query.exec(QObject::tr("insert into cars values(4, 'PICASSO', 2, 1999)"));
    query.exec(QObject::tr("insert into cars values(5, 'FORD', 2, 2004)"));
    query.exec(QObject::tr("insert into cars values(6, 'PEUGEOT 307', 2, 2001)"));
    query.exec(QObject::tr("insert into cars values(7, 'SANTANA', 3, 1995)"));
    query.exec(QObject::tr("insert into cars values(8, 'PASSAT', 3, 2000)"));
}
