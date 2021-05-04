#ifndef _STYLEMAINWINDOW_H
#define _STYLEMAINWINDOW_H

#include <QMainWindow>

#include "ui_StyleMainWindow.h"

class CStyleMainWindow :	public QMainWindow,
							public Ui_StyleMainWindow
{
	Q_OBJECT
public:
	CStyleMainWindow(QWidget* = 0);
	virtual ~CStyleMainWindow (){}
private slots:
	void onRadioBtnToggled(QAbstractButton* );
};

#endif
