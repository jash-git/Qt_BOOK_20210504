// chapter2/builtin/src/builtindlg.cpp.
#include <QtGui/QtGui>
#include "builtindlg.h"

CBuiltinDlg::CBuiltinDlg(QWidget* parent)
 :	QDialog(parent)
{
        displayTextEdit = new QTextEdit(tr("Qt的標準通用對話方塊"));

        QGridLayout* gridLayout = new QGridLayout;
        colorPushBtn 	= new QPushButton(tr("顏色對話方塊"));
        errorPushBtn 	= new QPushButton(tr("錯誤訊息方塊"));
        filePushBtn 	= new QPushButton(tr("文件對話方塊"));
        fontPushBtn 	= new QPushButton(tr("字體對話方塊"));
        inputPushBtn 	= new QPushButton(tr("輸入對話方塊"));
        pagePushBtn 	= new QPushButton(tr("頁面設置對話方塊"));
        progressPushBtn = new QPushButton(tr("進度對話方塊"));
        printPushBtn	= new QPushButton(tr("列印對話方塊"));
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
        setWindowTitle(tr("內建對話方塊"));
        resize(400, 300);
}
void CBuiltinDlg::doPushBtn()
{
        QPushButton* btn = qobject_cast<QPushButton*>(sender());
        if(btn == colorPushBtn)
        {// 顏色對話方塊.
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
        {// 錯誤訊息方塊.
                QErrorMessage box(this);
                box.setWindowTitle(tr("錯誤訊息方塊"));
                box.showMessage(tr("錯誤訊息方塊實例xx。"));
                box.showMessage(tr("錯誤訊息方塊實例xx。"));
                box.showMessage(tr("錯誤訊息方塊實例xx。"));
                box.showMessage(tr("錯誤訊息方塊實例yy。"));
                box.showMessage(tr("錯誤訊息方塊實例zz。"));

                box.exec();
        }
        else if(btn == filePushBtn)
        {// 文件對話方塊.
                QString fileName = QFileDialog::getOpenFileName(this,
                                                tr("打開文件"),
                                                "/home/czm",
                                                tr("任何文件(*.*)"
                                                ";;文字檔(*.txt)"
                                                ";;XML文件(*.xml)"));
                displayTextEdit->setText(fileName);
        }
        else if(btn == fontPushBtn)
        {// 字體對話方塊.
                bool ok;
                const QFont& font = QFontDialog::getFont(&ok,
                                         displayTextEdit->font(),
                                         this,
                                         tr("字體對話方塊"));
                if(ok)
                {// 如果<確定>,設置字體.
                    displayTextEdit->setFont(font);
                }
        }
        else if(btn == inputPushBtn)
        {//  輸入對話方塊.
                bool ok;
                QString text = QInputDialog::getText(this,
                                                tr("輸入對話方塊"),
                                                tr("輸入文字："),
                                                QLineEdit::Normal,
                                                QDir::home().dirName(),
                                                &ok);
     if (ok && !text.isEmpty())
         displayTextEdit->setText(text);
        }
        else if(btn == pagePushBtn)
        {// 頁面設置對話方塊.
                QPrinter printer;
                QPageSetupDialog dlg(&printer, this);
                dlg.setWindowTitle(tr("頁面設置對話方塊"));
                if (dlg.exec() == QDialog::Accepted)
                {
                        // 進行下一步的處理。
                }
        }
        else if(btn == progressPushBtn)
        {// 進度對話方塊.
                QProgressDialog progress(tr("正在複製檔..."), tr("取消"), 0, 10000, this);
                progress.setWindowModality(Qt::WindowModal);
                progress.setWindowTitle(tr("進度對話方塊"));
                progress.show();
                for (int i = 0; i < 10000; i++)
{
                        progress.setValue(i);
                        qApp->processEvents();
                        if (progress.wasCanceled())
                                break;
                        //... 複製檔處理
                        qDebug() << i;
                }
                progress.setValue(10000);
        }

        else if(btn == printPushBtn)
        {// 列印對話方塊.
                QPrinter printer;
                QPrintDialog dlg(&printer, this);
                dlg.setWindowTitle(tr("列印對話方塊"));
                if (dlg.exec() == QDialog::Accepted)
                {
                        // 進行下一步的處理
                }
        }
}
