/********************************************************************************
** Form generated from reading UI file 'schema.ui'
**
** Created: Mon Aug 30 17:06:09 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEMA_H
#define UI_SCHEMA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SchemaMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *schemaLabel;
    QTextBrowser *schemaView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *instanceLabel;
    QComboBox *instanceSelection;
    QTextEdit *instanceEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *validationStatus;
    QPushButton *validateButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SchemaMainWindow)
    {
        if (SchemaMainWindow->objectName().isEmpty())
            SchemaMainWindow->setObjectName(QString::fromUtf8("SchemaMainWindow"));
        SchemaMainWindow->resize(861, 601);
        centralwidget = new QWidget(SchemaMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        schemaLabel = new QLabel(centralwidget);
        schemaLabel->setObjectName(QString::fromUtf8("schemaLabel"));

        verticalLayout->addWidget(schemaLabel);

        schemaView = new QTextBrowser(centralwidget);
        schemaView->setObjectName(QString::fromUtf8("schemaView"));
        schemaView->setReadOnly(false);

        verticalLayout->addWidget(schemaView);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        instanceLabel = new QLabel(centralwidget);
        instanceLabel->setObjectName(QString::fromUtf8("instanceLabel"));

        horizontalLayout->addWidget(instanceLabel);

        instanceSelection = new QComboBox(centralwidget);
        instanceSelection->setObjectName(QString::fromUtf8("instanceSelection"));

        horizontalLayout->addWidget(instanceSelection);


        verticalLayout_2->addLayout(horizontalLayout);

        instanceEdit = new QTextEdit(centralwidget);
        instanceEdit->setObjectName(QString::fromUtf8("instanceEdit"));
        instanceEdit->setMinimumSize(QSize(450, 0));

        verticalLayout_2->addWidget(instanceEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        validationStatus = new QLabel(centralwidget);
        validationStatus->setObjectName(QString::fromUtf8("validationStatus"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(validationStatus->sizePolicy().hasHeightForWidth());
        validationStatus->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(validationStatus);

        validateButton = new QPushButton(centralwidget);
        validateButton->setObjectName(QString::fromUtf8("validateButton"));

        horizontalLayout_3->addWidget(validateButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        SchemaMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SchemaMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SchemaMainWindow->setStatusBar(statusbar);

        retranslateUi(SchemaMainWindow);

        QMetaObject::connectSlotsByName(SchemaMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SchemaMainWindow)
       {
           SchemaMainWindow->setWindowTitle(QApplication::translate("SchemaMainWindow", "XML Schema \351\251\227\350\255\211", 0, QApplication::UnicodeUTF8));
           schemaLabel->setText(QApplication::translate("SchemaMainWindow", "XML Schema\357\274\232 ", 0, QApplication::UnicodeUTF8));
           instanceLabel->setText(QApplication::translate("SchemaMainWindow", "XML\357\274\232", 0, QApplication::UnicodeUTF8));
           label->setText(QApplication::translate("SchemaMainWindow", "\347\213\200\346\205\213\357\274\232", 0, QApplication::UnicodeUTF8));
           validationStatus->setText(QApplication::translate("SchemaMainWindow", "\346\234\252\351\251\227\350\255\211", 0, QApplication::UnicodeUTF8));
           validateButton->setText(QApplication::translate("SchemaMainWindow", "\351\251\227\350\255\211", 0, QApplication::UnicodeUTF8));
       } // retranslateUi

};

namespace Ui {
    class SchemaMainWindow: public Ui_SchemaMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEMA_H
