#include <QtDebug>

#include "effect.h"

EffectWidget::EffectWidget(QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	setupUi(this);

	m_colorButtons = new QButtonGroup(this);
	m_colorButtons->addButton(redRadio, Qt::red);
	m_colorButtons->addButton(greenRadio, Qt::green);
	m_colorButtons->addButton(blueRadio, Qt::blue);
	connect(m_colorButtons, SIGNAL(buttonClicked(int)), SLOT(setColor(int)));

	m_shadowColorButtons = new QButtonGroup(this);
	m_shadowColorButtons->addButton(shadowRedRadio, Qt::red);
	m_shadowColorButtons->addButton(shadowGreenRadio, Qt::green);
	m_shadowColorButtons->addButton(shadowBlueRadio, Qt::blue);
	connect(m_shadowColorButtons, SIGNAL(buttonClicked(int)), SLOT(setShadowColor(int)));

	graphicsView->setScene(&m_scene);

    setupScene();

	m_color = QColor(0,0,192);
	m_shadowColor = QColor(63, 63, 63, 180);

}

void EffectWidget::setupScene()
{
        m_scene.addPixmap(QPixmap(":/effect/gfs.jpg"));

        m_item = m_scene.addPixmap(QPixmap(":/effect/aircraft.png"));
	m_item->setOffset(100,100);
}


void EffectWidget::on_radiusSpin_valueChanged(int i)
{
	QGraphicsBlurEffect* be = new QGraphicsBlurEffect;
	be->setBlurRadius(i);
	m_item->setGraphicsEffect(be);
}

void EffectWidget::on_strengthSpin_valueChanged(double i)
{
	QGraphicsColorizeEffect* ce = new QGraphicsColorizeEffect;
	ce->setStrength(i);
	ce->setColor(m_color);
	m_item->setGraphicsEffect(ce);
}

void EffectWidget::setColor(int i)
{
	m_color = static_cast<Qt::GlobalColor>(i);
	QGraphicsColorizeEffect* ce = new QGraphicsColorizeEffect;
	ce->setStrength(strengthSpin->value());
	ce->setColor(m_color);
	m_item->setGraphicsEffect(ce);
}

void EffectWidget::setShadowColor(int i)
{
	m_shadowColor = static_cast<Qt::GlobalColor>(i);
	m_shadowColor.setAlpha(180);
	QGraphicsDropShadowEffect* de = new QGraphicsDropShadowEffect;
	de->setBlurRadius(shadowRSpin->value());
	de->setOffset(xOffsetSpin->value(),yOffsetSpin->value());
	de->setColor(m_shadowColor);
	m_item->setGraphicsEffect(de);
}

void EffectWidget::on_shadowRSpin_valueChanged(double i)
{
	QGraphicsDropShadowEffect* de = new QGraphicsDropShadowEffect;
	de->setBlurRadius(i);
	de->setOffset(xOffsetSpin->value(),yOffsetSpin->value());
	de->setColor(m_shadowColor);
	m_item->setGraphicsEffect(de);
}

void EffectWidget::on_xOffsetSpin_valueChanged(double i)
{
	QGraphicsDropShadowEffect* de = new QGraphicsDropShadowEffect;
	de->setBlurRadius(i);
	de->setOffset(i,yOffsetSpin->value());
	de->setColor(m_shadowColor);
	m_item->setGraphicsEffect(de);
}

void EffectWidget::on_yOffsetSpin_valueChanged(double i)
{
	QGraphicsDropShadowEffect* de = new QGraphicsDropShadowEffect;
	de->setBlurRadius(i);
	de->setOffset(xOffsetSpin->value(),i);
	de->setColor(m_shadowColor);
	m_item->setGraphicsEffect(de);
}

void EffectWidget::on_opacitySpin_valueChanged(double i)
{
	QGraphicsOpacityEffect* oe = new QGraphicsOpacityEffect;
	oe->setOpacity(i);
	m_item->setGraphicsEffect(oe);
}
