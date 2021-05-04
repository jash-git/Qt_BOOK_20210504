/********************************************************************************
** Form generated from reading UI file 'querywidget.ui'
**
** Created: Mon Aug 30 23:17:01 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYWIDGET_H
#define UI_QUERYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryWidget
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *inputGroupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *_2;
    QTextEdit *inputTextEdit;
    QGroupBox *queryGroupBox;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *queryTextEdit;
    QGroupBox *outputGroupBox;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *outputTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *queryPB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QueryWidget)
    {
        if (QueryWidget->objectName().isEmpty())
            QueryWidget->setObjectName(QString::fromUtf8("QueryWidget"));
        QueryWidget->resize(1128, 914);
        centralwidget = new QWidget(QueryWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        inputGroupBox = new QGroupBox(centralwidget);
        inputGroupBox->setObjectName(QString::fromUtf8("inputGroupBox"));
        inputGroupBox->setMinimumSize(QSize(550, 120));
        verticalLayout_4 = new QVBoxLayout(inputGroupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        _2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _2->setContentsMargins(0, 0, 0, 0);
#endif
        _2->setObjectName(QString::fromUtf8("_2"));
        inputTextEdit = new QTextEdit(inputGroupBox);
        inputTextEdit->setObjectName(QString::fromUtf8("inputTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(inputTextEdit->sizePolicy().hasHeightForWidth());
        inputTextEdit->setSizePolicy(sizePolicy);
        inputTextEdit->setMinimumSize(QSize(400, 60));
        inputTextEdit->setReadOnly(true);
        inputTextEdit->setAcceptRichText(false);

        _2->addWidget(inputTextEdit);


        verticalLayout_4->addLayout(_2);


        verticalLayout->addWidget(inputGroupBox);

        queryGroupBox = new QGroupBox(centralwidget);
        queryGroupBox->setObjectName(QString::fromUtf8("queryGroupBox"));
        queryGroupBox->setMinimumSize(QSize(550, 120));
        verticalLayout_5 = new QVBoxLayout(queryGroupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        queryTextEdit = new QTextEdit(queryGroupBox);
        queryTextEdit->setObjectName(QString::fromUtf8("queryTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(queryTextEdit->sizePolicy().hasHeightForWidth());
        queryTextEdit->setSizePolicy(sizePolicy1);
        queryTextEdit->setLineWidth(1);
        queryTextEdit->setAutoFormatting(QTextEdit::AutoAll);
        queryTextEdit->setReadOnly(false);

        verticalLayout_5->addWidget(queryTextEdit);


        verticalLayout->addWidget(queryGroupBox);


        horizontalLayout_2->addLayout(verticalLayout);

        outputGroupBox = new QGroupBox(centralwidget);
        outputGroupBox->setObjectName(QString::fromUtf8("outputGroupBox"));
        outputGroupBox->setMinimumSize(QSize(550, 120));
        horizontalLayout = new QHBoxLayout(outputGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        outputTextEdit = new QTextBrowser(outputGroupBox);
        outputTextEdit->setObjectName(QString::fromUtf8("outputTextEdit"));

        horizontalLayout->addWidget(outputTextEdit);


        horizontalLayout_2->addWidget(outputGroupBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        queryPB = new QPushButton(centralwidget);
        queryPB->setObjectName(QString::fromUtf8("queryPB"));

        horizontalLayout_3->addWidget(queryPB);


        verticalLayout_2->addLayout(horizontalLayout_3);

        QueryWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QueryWidget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1128, 20));
        QueryWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(QueryWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QueryWidget->setStatusBar(statusbar);

        retranslateUi(QueryWidget);

        QMetaObject::connectSlotsByName(QueryWidget);
    } // setupUi

    void retranslateUi(QMainWindow *QueryWidget)
        {
            QueryWidget->setWindowTitle(QApplication::translate("QueryWidget", "XQuery \347\244\272\344\276\213", 0, QApplication::UnicodeUTF8));
            inputGroupBox->setTitle(QApplication::translate("QueryWidget", "\350\274\270\345\205\245XML\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
            queryGroupBox->setTitle(QApplication::translate("QueryWidget", "\346\237\245\350\251\242\346\242\235\344\273\266\357\274\232", 0, QApplication::UnicodeUTF8));
            outputGroupBox->setTitle(QApplication::translate("QueryWidget", "\350\274\270\345\207\272\347\265\220\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
            queryPB->setText(QApplication::translate("QueryWidget", "\350\275\211\346\217\233", 0, QApplication::UnicodeUTF8));
        } // retranslateUi

};

namespace Ui {
    class QueryWidget: public Ui_QueryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYWIDGET_H
