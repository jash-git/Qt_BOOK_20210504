#include <QtGui>

#include "arrowwidget.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
	resize(800,600);
        arrowWidget = new ArrowWidget(this);
        setCentralWidget(arrowWidget);
}

