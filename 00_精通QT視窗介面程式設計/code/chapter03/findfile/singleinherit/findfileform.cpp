// findfileform.cpp
#include <QtGui>
#include "findfileform.h"

CFindFileForm::CFindFileForm(QWidget* parent)
 :	QWidget(parent)
 {
 	ui.setupUi(this);	
        ui.statusLabel->setText(tr("�N��"));
        ui.resultLabel->setText(tr("���0�Ӥ��"));
	ui.nameComboBox->setEditText("*");
	ui.dirComboBox->setEditText(QDir::currentPath());
	ui.dirComboBox->addItem(QDir::currentPath());
	ui.sensitiveCheckBox->setEnabled(false);
	ui.stopPushBtn->setEnabled(false);
 
 }
