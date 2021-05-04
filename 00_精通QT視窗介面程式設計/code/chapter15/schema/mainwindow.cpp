/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QtXmlPatterns>

#include "mainwindow.h"
#include "MsgHandler.h"

//! [4]

//! [4]

//! [0]
MainWindow::MainWindow()
{
    setupUi(this);
    connect(validateButton, SIGNAL(clicked()), this,SLOT(validate()));
//    connect(instanceEdit, SIGNAL(textChanged()), this,SLOT(textChanged()));
    connect(instanceSelection, SIGNAL(currentIndexChanged (int )),
                this,SLOT(instanceSelected(int)));
    validationStatus->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    schemaloaded();
    instanceSelected(0);
}
//! [0]

//! [1]
void MainWindow::schemaloaded()
{
    instanceSelection->clear();

        instanceSelection->addItem(tr("有效實例"));
        instanceSelection->addItem(tr("無效實例"));



    QFile schemaFile(QString(":/schema_0.xsd"));
    schemaFile.open(QIODevice::ReadOnly);
    const QString schemaText(QString::fromUtf8(schemaFile.readAll()));
    schemaView->setPlainText(schemaText);
//    textChanged();
    validate();
}
//! [1]

//! [2]
void MainWindow::instanceSelected(int index)
{
    QFile instanceFile(QString(":/instance_%1.xml").arg(index));
    instanceFile.open(QIODevice::ReadOnly);
    const QString instanceText(QString::fromUtf8(instanceFile.readAll()));
    instanceEdit->setPlainText(instanceText);

    validate();
}
//! [2]

//! [3]
void MainWindow::validate()
{
    const QByteArray schemaData = schemaView->toPlainText().toUtf8();
    const QByteArray instanceData = instanceEdit->toPlainText().toUtf8();

    MsgHandler messageHandler;

    QXmlSchema schema;
    schema.setMessageHandler(&messageHandler);

    schema.load(schemaData);

    bool errorOccurred = false;
    if (!schema.isValid()) {
        errorOccurred = true;
    } else {
        QXmlSchemaValidator validator(schema);
        if (!validator.validate(instanceData))
            errorOccurred = true;
    }

    if (errorOccurred) {
        validationStatus->setText(messageHandler.statusMessage());
        moveCursor(messageHandler.line(), messageHandler.column());
    } else {
        validationStatus->setText(tr("validation successful"));
    }

    const QString styleSheet = QString("QLabel {background: %1; padding: 3px}")
                                      .arg(errorOccurred ? QColor(Qt::red).lighter(160).name() :
                                                           QColor(Qt::green).lighter(160).name());
    validationStatus->setStyleSheet(styleSheet);
}
//! [3]

//void MainWindow::textChanged()
//{
////    instanceEdit->setExtraSelections(QList<QTextEdit::ExtraSelection>());
//}

void MainWindow::moveCursor(int line, int column)
{
    instanceEdit->moveCursor(QTextCursor::Start);
    for (int i = 1; i < line; ++i)
        instanceEdit->moveCursor(QTextCursor::Down);

    for (int i = 1; i < column; ++i)
        instanceEdit->moveCursor(QTextCursor::Right);

    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;

    const QColor lineColor = QColor(Qt::red).lighter(160);
    selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = instanceEdit->textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);

    instanceEdit->setExtraSelections(extraSelections);

    instanceEdit->setFocus();
}
