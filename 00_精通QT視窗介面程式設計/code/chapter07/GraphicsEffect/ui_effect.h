/********************************************************************************
** Form generated from reading UI file 'effectJL1105.ui'
**
** Created: Wed May 4 21:29:27 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EFFECTJL1105_H
#define EFFECTJL1105_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_effect
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QToolBox *toolBox;
    QWidget *toolBoxPage1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *radiusSpin;
    QWidget *page_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *redRadio;
    QRadioButton *greenRadio;
    QRadioButton *blueRadio;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *strengthSpin;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *shadowRedRadio;
    QRadioButton *shadowGreenRadio;
    QRadioButton *shadowBlueRadio;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *shadowRSpin;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *xOffsetSpin;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDoubleSpinBox *yOffsetSpin;
    QWidget *toolBoxPage2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDoubleSpinBox *opacitySpin;

    void setupUi(QWidget *effect)
    {
        if (effect->objectName().isEmpty())
            effect->setObjectName(QString::fromUtf8("effect"));
        effect->resize(568, 350);
        effect->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));
        horizontalLayout = new QHBoxLayout(effect);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(effect);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));

        horizontalLayout->addWidget(graphicsView);

        toolBox = new QToolBox(effect);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy1);
        toolBoxPage1 = new QWidget();
        toolBoxPage1->setObjectName(QString::fromUtf8("toolBoxPage1"));
        toolBoxPage1->setGeometry(QRect(0, 0, 120, 175));
        horizontalLayout_2 = new QHBoxLayout(toolBoxPage1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(toolBoxPage1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        radiusSpin = new QSpinBox(toolBoxPage1);
        radiusSpin->setObjectName(QString::fromUtf8("radiusSpin"));
        radiusSpin->setMinimum(0);
        radiusSpin->setMaximum(50);
        radiusSpin->setValue(5);

        horizontalLayout_2->addWidget(radiusSpin);

        toolBox->addItem(toolBoxPage1, QString::fromUtf8("\346\250\241\347\263\212\346\225\210\346\236\234"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 117, 113));
        verticalLayout = new QVBoxLayout(page_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        redRadio = new QRadioButton(page_2);
        redRadio->setObjectName(QString::fromUtf8("redRadio"));

        verticalLayout->addWidget(redRadio);

        greenRadio = new QRadioButton(page_2);
        greenRadio->setObjectName(QString::fromUtf8("greenRadio"));

        verticalLayout->addWidget(greenRadio);

        blueRadio = new QRadioButton(page_2);
        blueRadio->setObjectName(QString::fromUtf8("blueRadio"));
        blueRadio->setChecked(true);

        verticalLayout->addWidget(blueRadio);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        strengthSpin = new QDoubleSpinBox(page_2);
        strengthSpin->setObjectName(QString::fromUtf8("strengthSpin"));
        strengthSpin->setDecimals(1);
        strengthSpin->setMaximum(1);
        strengthSpin->setSingleStep(0.1);
        strengthSpin->setValue(1);

        horizontalLayout_3->addWidget(strengthSpin);


        verticalLayout->addLayout(horizontalLayout_3);

        toolBox->addItem(page_2, QString::fromUtf8("\350\221\227\350\211\262\346\225\210\346\236\234"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 126, 187));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        shadowRedRadio = new QRadioButton(page);
        shadowRedRadio->setObjectName(QString::fromUtf8("shadowRedRadio"));

        verticalLayout_2->addWidget(shadowRedRadio);

        shadowGreenRadio = new QRadioButton(page);
        shadowGreenRadio->setObjectName(QString::fromUtf8("shadowGreenRadio"));

        verticalLayout_2->addWidget(shadowGreenRadio);

        shadowBlueRadio = new QRadioButton(page);
        shadowBlueRadio->setObjectName(QString::fromUtf8("shadowBlueRadio"));
        shadowBlueRadio->setChecked(true);

        verticalLayout_2->addWidget(shadowBlueRadio);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        shadowRSpin = new QDoubleSpinBox(page);
        shadowRSpin->setObjectName(QString::fromUtf8("shadowRSpin"));
        shadowRSpin->setDecimals(1);
        shadowRSpin->setMaximum(10);
        shadowRSpin->setSingleStep(0.1);
        shadowRSpin->setValue(1);

        horizontalLayout_4->addWidget(shadowRSpin);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        xOffsetSpin = new QDoubleSpinBox(page);
        xOffsetSpin->setObjectName(QString::fromUtf8("xOffsetSpin"));
        xOffsetSpin->setDecimals(1);
        xOffsetSpin->setMaximum(50);
        xOffsetSpin->setSingleStep(1);
        xOffsetSpin->setValue(8);

        horizontalLayout_5->addWidget(xOffsetSpin);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        yOffsetSpin = new QDoubleSpinBox(page);
        yOffsetSpin->setObjectName(QString::fromUtf8("yOffsetSpin"));
        yOffsetSpin->setDecimals(1);
        yOffsetSpin->setMaximum(50);
        yOffsetSpin->setSingleStep(1);
        yOffsetSpin->setValue(8);

        horizontalLayout_6->addWidget(yOffsetSpin);


        verticalLayout_2->addLayout(horizontalLayout_6);

        toolBox->addItem(page, QString::fromUtf8("\351\231\260\345\275\261\346\225\210\346\236\234"));
        toolBoxPage2 = new QWidget();
        toolBoxPage2->setObjectName(QString::fromUtf8("toolBoxPage2"));
        toolBoxPage2->setGeometry(QRect(0, 0, 130, 51));
        verticalLayout_3 = new QVBoxLayout(toolBoxPage2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(toolBoxPage2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        opacitySpin = new QDoubleSpinBox(toolBoxPage2);
        opacitySpin->setObjectName(QString::fromUtf8("opacitySpin"));
        opacitySpin->setMaximum(1);
        opacitySpin->setSingleStep(0.1);
        opacitySpin->setValue(0.7);

        horizontalLayout_7->addWidget(opacitySpin);


        verticalLayout_3->addLayout(horizontalLayout_7);

        toolBox->addItem(toolBoxPage2, QString::fromUtf8("\351\200\217\346\230\216\346\225\210\346\236\234"));

        horizontalLayout->addWidget(toolBox);


        retranslateUi(effect);

        QMetaObject::connectSlotsByName(effect);
    } // setupUi

    void retranslateUi(QWidget *effect)
    {
        effect->setWindowTitle(QApplication::translate("effect", "\345\234\226\345\236\213\346\225\210\346\236\234DEMO", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("effect", "\345\215\212\345\276\221:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage1), QApplication::translate("effect", "\346\250\241\347\263\212\346\225\210\346\236\234", 0, QApplication::UnicodeUTF8));
        redRadio->setText(QApplication::translate("effect", "\347\264\205\350\211\262", 0, QApplication::UnicodeUTF8));
        greenRadio->setText(QApplication::translate("effect", "\347\266\240\350\211\262", 0, QApplication::UnicodeUTF8));
        blueRadio->setText(QApplication::translate("effect", "\350\227\215\350\211\262", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("effect", "\346\277\203\345\272\246", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("effect", "\350\221\227\350\211\262\346\225\210\346\236\234", 0, QApplication::UnicodeUTF8));
        shadowRedRadio->setText(QApplication::translate("effect", "\347\264\205\350\211\262", 0, QApplication::UnicodeUTF8));
        shadowGreenRadio->setText(QApplication::translate("effect", "\347\266\240\350\211\262", 0, QApplication::UnicodeUTF8));
        shadowBlueRadio->setText(QApplication::translate("effect", "\350\227\215\350\211\262", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("effect", "\345\215\212\345\276\221", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("effect", "X\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("effect", "Y\345\201\217\347\247\273", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("effect", "\351\231\260\345\275\261\346\225\210\346\236\234", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("effect", "\351\200\217\346\230\216\345\272\246", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage2), QApplication::translate("effect", "\351\200\217\346\230\216\346\225\210\346\236\234", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class effect: public Ui_effect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EFFECTJL1105_H
