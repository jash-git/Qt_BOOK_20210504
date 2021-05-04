#include "Msg.h"

Msg::Msg()
{
        QFont font;
        font.setPointSize(24);
        setFont(font);
        QStringList args = qApp->arguments();
        QString path;
        if (args.count() > 1)
                path = args[1];
        else
                path = QDir::currentPath();
        label = new QLabel();
        label->setText(tr("監視的目錄：") + path);
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(label);
        setLayout(layout);

        fsWatcher.addPath(path);
        connect(&fsWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(directoryChanged(QString)));
        connect(&fsWatcher, SIGNAL(fileChanged(QString)), this, SLOT(fileChanged(QString)));
}

void Msg::directoryChanged(QString path)
{
        QMessageBox::information(NULL, tr("目錄有變化"), path);
}

void Msg::fileChanged(QString path)
{
        QMessageBox::information(NULL, tr("文件有變化"), path);
}

