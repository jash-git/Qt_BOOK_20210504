#include <QDebug>
#include <QtGui>
#include <QtCore>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);	
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
	
	QObject* obj = new QLabel;
	const QMetaObject* mo = obj->metaObject();
        qDebug() << QObject::tr("���O�W�١G%1").arg(mo->className());
        qDebug() << QObject::tr("�O�_�~�Ӧ�QWidget�G%1")
                        .arg(obj->inherits("QWidget") ? QObject::tr("�O") : QObject::tr("�_") );
    return 0;
}
