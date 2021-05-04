#ifndef ROUNDPUSHBTN_H_
#define ROUNDPUSHBTN_H_

#include <QPushButton>

class CRoundPushBtn: public QPushButton
{
	Q_OBJECT
public:
	typedef enum										
	{
		StatFine			= 0,						
		StatFault			= 1,						
		StatClosed   		= 2,						
		StatUnknown 		= 3       						
	}IndnStat;

public:
	
	CRoundPushBtn(QWidget* = 0);
	virtual ~CRoundPushBtn(){}

	void setUIState(IndnStat );			
	int	 m_Stat;

private:
	void ini();
};

#endif
