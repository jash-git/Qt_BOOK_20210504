

#ifndef DIALOG_H
#define DIALOG_H

#include <qdialog.h>
#include <qsharedmemory.h>
#include <qlocalsocket.h>
#include "ui_ipcClient.h"

//! [0]
class Dialog : public QDialog
{
    Q_OBJECT

  public:
    Dialog(QWidget *parent = 0);

  public slots:
	void connectToSocket();
    void loadFromSocket();
    void loadFromMemory();
	void displayError(QLocalSocket::LocalSocketError socketError);
 private:
    void detach();

  private:
    Ui::Dialog ui;
    QSharedMemory sharedMemory;
	QLocalSocket *socket;
	int blockSize;
};
//! [0]

#endif

