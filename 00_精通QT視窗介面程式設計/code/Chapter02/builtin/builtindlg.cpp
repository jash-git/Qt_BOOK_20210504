// chapter2/builtin/src/builtindlg.cpp.
#include <QtGui/QtGui>
#include "builtindlg.h"

CBuiltinDlg::CBuiltinDlg(QWidget* parent)
 :	QDialog(parent)
{
        displayTextEdit = new QTextEdit(tr("Qt���зǳq�ι�ܤ��"));

        QGridLayout* gridLayout = new QGridLayout;
        colorPushBtn 	= new QPushButton(tr("�C���ܤ��"));
        errorPushBtn 	= new QPushButton(tr("���~�T�����"));
        filePushBtn 	= new QPushButton(tr("����ܤ��"));
        fontPushBtn 	= new QPushButton(tr("�r���ܤ��"));
        inputPushBtn 	= new QPushButton(tr("��J��ܤ��"));
        pagePushBtn 	= new QPushButton(tr("�����]�m��ܤ��"));
        progressPushBtn = new QPushButton(tr("�i�׹�ܤ��"));
        printPushBtn	= new QPushButton(tr("�C�L��ܤ��"));
        gridLayout->addWidget(colorPushBtn, 0, 0, 1, 1);
        gridLayout->addWidget(errorPushBtn, 0, 1, 1, 1);
        gridLayout->addWidget(filePushBtn, 0, 2, 1, 1);
        gridLayout->addWidget(fontPushBtn, 1, 0, 1, 1);
        gridLayout->addWidget(inputPushBtn, 1, 1, 1, 1);
        gridLayout->addWidget(pagePushBtn, 1, 2, 1, 1);
        gridLayout->addWidget(progressPushBtn, 2, 0, 1, 1);
        gridLayout->addWidget(printPushBtn, 2, 1, 1, 1);
        gridLayout->addWidget(displayTextEdit, 3, 0, 3, 3);

        setLayout(gridLayout);

        connect(colorPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        connect(errorPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        connect(filePushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        connect(fontPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        connect(inputPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        connect(pagePushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        connect(progressPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        connect(printPushBtn, SIGNAL(clicked()), this, SLOT(doPushBtn()));
        setWindowTitle(tr("���ع�ܤ��"));
        resize(400, 300);
}
void CBuiltinDlg::doPushBtn()
{
        QPushButton* btn = qobject_cast<QPushButton*>(sender());
        if(btn == colorPushBtn)
        {// �C���ܤ��.
                QPalette palette = displayTextEdit->palette();
                const QColor& color
                        = QColorDialog::getColor(palette.color(QPalette::Base), this);
                if(color.isValid())
                {
                        palette.setColor(QPalette::Base, color);
                        displayTextEdit->setPalette(palette);
                }
        }
else if(btn == errorPushBtn)
        {// ���~�T�����.
                QErrorMessage box(this);
                box.setWindowTitle(tr("���~�T�����"));
                box.showMessage(tr("���~�T��������xx�C"));
                box.showMessage(tr("���~�T��������xx�C"));
                box.showMessage(tr("���~�T��������xx�C"));
                box.showMessage(tr("���~�T��������yy�C"));
                box.showMessage(tr("���~�T��������zz�C"));

                box.exec();
        }
        else if(btn == filePushBtn)
        {// ����ܤ��.
                QString fileName = QFileDialog::getOpenFileName(this,
                                                tr("���}���"),
                                                "/home/czm",
                                                tr("������(*.*)"
                                                ";;��r��(*.txt)"
                                                ";;XML���(*.xml)"));
                displayTextEdit->setText(fileName);
        }
        else if(btn == fontPushBtn)
        {// �r���ܤ��.
                bool ok;
                const QFont& font = QFontDialog::getFont(&ok,
                                         displayTextEdit->font(),
                                         this,
                                         tr("�r���ܤ��"));
                if(ok)
                {// �p�G<�T�w>,�]�m�r��.
                    displayTextEdit->setFont(font);
                }
        }
        else if(btn == inputPushBtn)
        {//  ��J��ܤ��.
                bool ok;
                QString text = QInputDialog::getText(this,
                                                tr("��J��ܤ��"),
                                                tr("��J��r�G"),
                                                QLineEdit::Normal,
                                                QDir::home().dirName(),
                                                &ok);
     if (ok && !text.isEmpty())
         displayTextEdit->setText(text);
        }
        else if(btn == pagePushBtn)
        {// �����]�m��ܤ��.
                QPrinter printer;
                QPageSetupDialog dlg(&printer, this);
                dlg.setWindowTitle(tr("�����]�m��ܤ��"));
                if (dlg.exec() == QDialog::Accepted)
                {
                        // �i��U�@�B���B�z�C
                }
        }
        else if(btn == progressPushBtn)
        {// �i�׹�ܤ��.
                QProgressDialog progress(tr("���b�ƻs��..."), tr("����"), 0, 10000, this);
                progress.setWindowModality(Qt::WindowModal);
                progress.setWindowTitle(tr("�i�׹�ܤ��"));
                progress.show();
                for (int i = 0; i < 10000; i++)
{
                        progress.setValue(i);
                        qApp->processEvents();
                        if (progress.wasCanceled())
                                break;
                        //... �ƻs�ɳB�z
                        qDebug() << i;
                }
                progress.setValue(10000);
        }

        else if(btn == printPushBtn)
        {// �C�L��ܤ��.
                QPrinter printer;
                QPrintDialog dlg(&printer, this);
                dlg.setWindowTitle(tr("�C�L��ܤ��"));
                if (dlg.exec() == QDialog::Accepted)
                {
                        // �i��U�@�B���B�z
                }
        }
}
