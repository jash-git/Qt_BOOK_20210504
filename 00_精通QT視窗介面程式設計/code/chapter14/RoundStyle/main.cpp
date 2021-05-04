#include <QtGui>
#include <QApplication>
#include <QTextCodec>

#include "StyleMainWindow.h"

#include "CustomStyle.h"
int main(int argc, char *argv[])
{
        QApplication app(argc, argv);

        // �]�mtr���r�Žs�X
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

        CCustomStyle* st = new CCustomStyle;
        app.setStyle(st);
        //CUIStyleDlg::instance()->iniUIStyle();

        /*app.setStyle(new QWindowsXPStyle);

        {
                // �զ�O
                QPalette palette = QPalette();//QColor(52, 52, 52));
                palette.setBrush(QPalette::BrightText, Qt::green);
                palette.setBrush(QPalette::Base, QColor(52, 52, 52));
                palette.setBrush(QPalette::Highlight, QColor(0, 60, 0));
                palette.setBrush(QPalette::Text, QColor(0, 255, 0));
                palette.setBrush(QPalette::ButtonText, QColor(0, 255, 0));
                palette.setBrush(QPalette::WindowText, QColor(0, 255, 0));

                /// �e��
                palette.setBrush(QPalette::Button, Qt::black);
                palette.setBrush(QPalette::Light, QColor(0, 85, 0));
                palette.setBrush(QPalette::Mid, Qt::black);
                palette.setBrush(QPalette::Midlight, Qt::black);
                palette.setBrush(QPalette::Dark,  QColor(0, 85, 0));
                palette.setBrush(QPalette::Shadow, Qt::black);
                palette.setBrush(QPalette::Window, Qt::black);

                QBrush brush = palette.base();

                // �]�m�զ�O
                palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
                palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
                palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);

                app.setPalette(palette);

        }*/

        CStyleMainWindow smw;
        smw.show();

        return app.exec();
}
