#ifndef UIREADER_H
#define UIREADER_H

#include <QtGui>
#include <QXmlStreamReader>

class UiReader : public QXmlStreamReader
{
public:
    UiReader(QTextEdit *textEdit, QString fileName);

	bool read(QIODevice *device);

private:
	QString macroName;
	QString propName;
	QString classAttr;
	QString	nameAttr;
	QString currentText;
	QString topWidget;
	QString currentWidget;
	QString constructorText;
    QString errorStr;
	QString xTag;	
	QString yTag;	
	QString wTag;
	QString hTag;	

        short	level;	// 記錄Widget的層次關係
	QTextEdit *txtEdit;
	QTextCursor cursor;
	
	void readUi();
	void readWidget();
	void readProperty();
	void readRect();
};

#endif
