#include <QDebug>
#include <QtGui>
#include <QtCore>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);	
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
	
	QObject* obj = new QLabel;
	const QMetaObject* mo = obj->metaObject();
        qDebug() << QObject::tr("類別名稱：%1").arg(mo->className());
        qDebug() << QObject::tr("是否繼承自QWidget：%1")
                        .arg(obj->inherits("QWidget") ? QObject::tr("是") : QObject::tr("否") );
    return 0;
}
