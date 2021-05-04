#include <QtGui>
#include <QtCore/QTextCodec>

#include "ui_findfileform.h"

 int main(int argc, char *argv[])
 {
	QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
	Q_INIT_RESOURCE(findfile);
	
	QWidget *pWidget = new QWidget;
	Ui::FindFileForm ui;
	ui.setupUi(pWidget);
	pWidget->show();
	
	return app.exec();
 }
