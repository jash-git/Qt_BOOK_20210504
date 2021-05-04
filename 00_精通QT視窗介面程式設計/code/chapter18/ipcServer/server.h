
#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <qsharedmemory.h>

class QLabel;
class QPushButton;
class QLocalServer;


class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void sendImage();
private:
	void createLocalServer();
	void createShareMemory();
private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    QLocalServer *server;
    QSharedMemory sharedMemory;
    QImage imageMemory;
	QImage imageSocket;
};

#endif
