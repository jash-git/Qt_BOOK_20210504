// findfileform.cpp
#include <QtGui>
#include "findfileform.h"

CFindFileForm::CFindFileForm(QWidget* parent)
 :	QWidget(parent)
 {
 	ui.setupUi(this);	
        ui.statusLabel->setText(tr("就緒"));
        ui.resultLabel->setText(tr("找到0個文件"));
	ui.nameComboBox->setEditText("*");
	ui.dirComboBox->setEditText(QDir::currentPath());
	ui.dirComboBox->addItem(QDir::currentPath());
	ui.sensitiveCheckBox->setEnabled(false);
	ui.stopPushBtn->setEnabled(false);
 
 }
