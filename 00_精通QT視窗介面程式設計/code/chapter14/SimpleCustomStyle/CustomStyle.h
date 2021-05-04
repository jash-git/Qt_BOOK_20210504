#ifndef _CUSTOMSTYLE_H
#define _CUSTOMSTYLE_H

#include <QWindowsStyle>

class CCustomStyle : public QWindowsStyle
{
	Q_OBJECT

public:
	CCustomStyle() {}
	virtual ~CCustomStyle() {}

    void polish(QPalette &palette);
};

#endif 
