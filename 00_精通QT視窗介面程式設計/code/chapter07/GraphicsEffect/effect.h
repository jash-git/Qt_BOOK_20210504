#ifndef EFFECT_H
#define EFFECT_H

#include <QtGui>
#include "ui_effect.h"

class EffectWidget : public QWidget, private Ui_effect
{
    Q_OBJECT

public:
    EffectWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    void setupScene();

private slots:
	void on_radiusSpin_valueChanged(int i);
	void on_strengthSpin_valueChanged(double i);
	void on_shadowRSpin_valueChanged(double i);
	void on_xOffsetSpin_valueChanged(double i);
	void on_yOffsetSpin_valueChanged(double i);
	void on_opacitySpin_valueChanged(double i);
	void setColor(int i);
	void setShadowColor(int i);


private:
	QGraphicsScene m_scene;
	QGraphicsPixmapItem* m_item;
	QButtonGroup* m_colorButtons;
	QButtonGroup* m_shadowColorButtons;
	QColor m_color;			// 着色效果
	QColor m_shadowColor;	// 阴影效果
};

#endif // Effect_H
