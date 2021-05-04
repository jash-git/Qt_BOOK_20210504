#include <QtGui>

#include "StyleMainWindow.h"

CStyleMainWindow::CStyleMainWindow(QWidget* parent)
:	QMainWindow(parent)
{
	setupUi(this);

	QButtonGroup* pBtnGroup = new QButtonGroup(this);
	pBtnGroup->addButton(fineRadioBtn);
	pBtnGroup->addButton(faultRadioBtn);
	pBtnGroup->addButton(unknownRadioBtn);
	pBtnGroup->addButton(closedRadioBtn);
	connect(pBtnGroup, SIGNAL(buttonClicked(QAbstractButton*)), 
		this, SLOT(onRadioBtnToggled(QAbstractButton*)));

	closedRadioBtn->click();
}

void CStyleMainWindow::onRadioBtnToggled(QAbstractButton* btn)
{
	if(btn == fineRadioBtn)
	{
		statPushBtn->setUIState(CRoundPushBtn::StatFine);
	}
	else if(btn == faultRadioBtn)
	{
		statPushBtn->setUIState(CRoundPushBtn::StatFault);
	}
	else if(btn == unknownRadioBtn)
	{
		statPushBtn->setUIState(CRoundPushBtn::StatUnknown);
	}
	else if(btn == closedRadioBtn)
	{
		statPushBtn->setUIState(CRoundPushBtn::StatClosed);
	}


}

