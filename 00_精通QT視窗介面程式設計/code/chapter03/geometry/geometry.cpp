#include <QtGui>
#include <QDebug>

#include "ctrlform.h"

int main(int argc, char *argv[])
{
 	QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
	
	CCtrlForm form;
	form.show();
	return app.exec();
}
