

#include <QtGui>
#include <QtXmlPatterns>
#include "querymainwindow.h"


//! [0]
QueryMainWindow::QueryMainWindow()
{
    setupUi(this);
	displayDefaultQuery();
    loadInputFile();
    connect(queryPB, SIGNAL(clicked()), this,SLOT(displayQuery()));


}
//! [0]

void QueryMainWindow::displayQuery()
{
	const QString query = queryTextEdit->toPlainText ();
	evaluate(query);

}


//! [1]
void QueryMainWindow::displayDefaultQuery()
{
    QFile queryFile(QString(":files/allCDs.xq"));
    queryFile.open(QIODevice::ReadOnly);
    const QString query(QString::fromLocal8Bit(queryFile.readAll()));
    queryTextEdit->setPlainText(query);

    evaluate(query);
}
//! [1]


void QueryMainWindow::loadInputFile()
{
    QFile forView;
    forView.setFileName(":/files/cdcatalog.xml");
    if (!forView.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this,
            tr("Unable to open file"), forView.errorString());
        return;
    }

    QTextStream in(&forView);
    QString inputDocument = in.readAll();
    inputTextEdit->setPlainText(inputDocument);
}


//! [2]
void QueryMainWindow::evaluate(const QString &str)
{
    QFile sourceDocument;
    sourceDocument.setFileName(":/files/cdcatalog.xml");
    sourceDocument.open(QIODevice::ReadOnly);

    QByteArray outArray;
    QBuffer buffer(&outArray);
    buffer.open(QIODevice::ReadWrite);

    QXmlQuery query;
    query.bindVariable("inputDocument", &sourceDocument);
    query.setQuery(str);
    if (!query.isValid())
        return;

    QXmlFormatter formatter(query, &buffer);
    if (!query.evaluateTo(&formatter))
        return;

    buffer.close();
    outputTextEdit->setText(QString::fromUtf8(outArray.constData()));

}
//! [2]

