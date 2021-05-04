#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include <QtCore/QTextCodec>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
int main(int argc, char* argv[])
{
        QApplication app(argc, argv);
        QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));
        QWidget* pWidget = new QWidget;
        QLabel label(pWidget);
        label.setText(QObject::tr("�P�@�ӥ@�ɡA�P�@�ӹڷQ�I"));
        QPushButton* btn = new QPushButton(QObject::tr("�T�w"), pWidget);
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(&label);
        layout->addWidget(btn);
        pWidget->setLayout(layout);
        QObject::connect(btn, SIGNAL(clicked()), pWidget, SLOT(close()));
        pWidget->show();
        return app.exec();
}

