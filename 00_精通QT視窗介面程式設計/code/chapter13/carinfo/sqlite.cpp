#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>
#include <iostream>
#include <QApplication>
#include <QTime>
#include <QVariant>
#include <QDebug>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
        QDateTime date= QDateTime::fromString(QString("21.5.1990"), QString("d.M.yyyy"));
        QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("無法打開資料庫！\n"),
                QObject::tr("退出請按Cancel鍵"),
                 QMessageBox::Cancel, QMessageBox::NoButton);
        return false;
    }
    QSqlQuery query;
    bool bSuccess = query.exec("CREATE TABLE automobil (id INT PRIMARY KEY, "
        "attribute VARCHAR, "
        "type VARCHAR, "
        "kind VARCHAR, "
        "nation INT, "
        "carnumber INT, "
        "elevaltor INT, "
        "distance INT, "
        "oil INT, "
        "temperature INT)");

        if(bSuccess)
                qDebug() << QObject::tr("完成資料庫表建立！\n");
        else
                qDebug() << QObject::tr("資料庫表建立失敗！\n");

        query.exec("SELECT * FROM automobil");
        QSqlRecord rec = query.record();
        qDebug() << QObject::tr("automobil表字段數：" )<< rec.count();

        QTime t;
        srand(1);
        t.start();

        query.prepare("INSERT INTO automobil "
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        long records = 10000;
        for(int i=0;i<records;i++) {
                query.bindValue(0, i);
                query.bindValue(1, "四輪");
                query.bindValue(2, "轎車");
                query.bindValue(3, "富康");
                query.bindValue(4, rand()%100);
                query.bindValue(5, rand()%10000);
                query.bindValue(6, rand()%300);
                query.bindValue(7, rand()%200000);
                query.bindValue(8, rand()%52);
                query.bindValue(9, rand()%100);

                bSuccess = query.exec();
                if(!bSuccess) {
                        QSqlError lastError = query.lastError();
                        qDebug() << lastError.driverText()<<QString(QObject::tr("插入失敗"));
                }
        }
        qDebug()<<QObject::tr("插入 %1條記錄, 耗時: %2 ms").arg(records).arg(t.elapsed());
        t.restart();
        bSuccess = query.exec("SELECT * FROM automobil ORDER BY id DESC");
        if(bSuccess)
                qDebug()<<QObject::tr("排序 %1 條記錄,  耗時: %2 ms").arg(records).arg(t.elapsed());
        else
                qDebug()<<QObject::tr("排序失敗！");


        t.restart();
        for(int i=0;i<records;i++) {
        query.clear();
        query.prepare(QString("UPDATE automobil SET "
                "attribute=?, type=?, kind=?, "
                "nation=?, carnumber=?, elevaltor=?, "
                "distance=?, oil=?, temperature=? "
                "WHERE id=%1").arg(i));

                query.bindValue(0, "四輪");
                query.bindValue(1, "轎車");
                query.bindValue(2, "富豪");
                query.bindValue(3, rand()%100);
                query.bindValue(4, rand()%10000);
                query.bindValue(5, rand()%300);
                query.bindValue(6, rand()%200000);
                query.bindValue(7, rand()%52);
                query.bindValue(8, rand()%100);

                bSuccess = query.exec();
                        if(!bSuccess) {
                        QSqlError lastError = query.lastError();
                        qDebug() << lastError.driverText()<<QString(QObject::tr("更新失敗"));
                }
        }
        qDebug()<<QObject::tr("更新 %1條記錄，耗時: %2 ms").arg(records).arg(t.elapsed());

        t.restart();
        query.exec("DELETE FROM automobil WHERE id=1500");
        qDebug()<<QObject::tr("刪除一條記錄，耗時： %1 ms").arg(t.elapsed());

  return 0;
}
#endif
