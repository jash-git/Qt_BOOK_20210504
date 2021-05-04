#ifndef _CUSTOMSTYLE_H
#define _CUSTOMSTYLE_H

#include <QWindowsStyle>

class CCustomStyle : public QWindowsStyle
{
	Q_OBJECT

public:
	CCustomStyle(const QString& = QString(), const QString& = QString()) ;
	virtual ~CCustomStyle(){}

	void polish(QPalette &palette);
	void polish(QWidget *widget);
	void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
		QPainter *painter, const QWidget *widget) const;
	void drawControl(ControlElement control, const QStyleOption *option,
		QPainter *painter, const QWidget *widget) const;
	/// º¯Êý
	void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
		QPainter *painter,
		const QWidget *widget) const;
private:
	QString		m_sBackgroundIcon;			
	QString		m_sButtonIcon;				

	static QPainterPath roundRectPath(const QRect &rect);
	void		changeTexture(QPalette&);	
	static void		setTexture(QPalette &palette, QPalette::ColorRole role,
					const QPixmap &pixmap);
};

#endif 
