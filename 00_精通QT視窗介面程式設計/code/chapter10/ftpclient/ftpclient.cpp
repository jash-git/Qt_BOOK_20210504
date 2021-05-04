#include "ftpclient.h"
#include <QtNetwork>
#include <QtGui>

FtpClient::FtpClient(QObject *parent)
        : QObject(parent),ftp(NULL),file(NULL)
{
        progressDialog = new QProgressDialog((QWidget *)parent);
}

FtpClient::~FtpClient()
{

}

void FtpClient::ftpConnect()
{
        if (ftp ==NULL) {
                QApplication::setOverrideCursor(Qt::WaitCursor);
                ftp = new QFtp(this);
                connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelDownload()));
                connect(ftp, SIGNAL(commandFinished(int, bool)),
                        this, SLOT(ftpCommandFinished(int, bool)));
                connect(ftp, SIGNAL(listInfo(const QUrlInfo &)),
                        this, SLOT(addToList(const QUrlInfo &)));
                connect(ftp, SIGNAL(dataTransferProgress(qint64, qint64)),
                        this, SLOT(updateDataTransferProgress(qint64, qint64)));

                ftp->connectToHost(serverName,serverPort.toUShort());
                ftp->login(userName,passWord);
                ftp->list();
                ftpStatus = tr("連接FTP服務器 %1...")
                        .arg(serverName);
                emit cmdConncted(true);
        }
        else {
                ftp->abort();
                ftp->deleteLater();
                ftp = NULL;
                emit cmdConncted(false);
        }

}

void FtpClient::cancelDownload()
{
                ftp->abort();
}

void FtpClient::ftpCommandFinished(int /*commandId*/, bool error)
{

        if (ftp->currentCommand() == QFtp::Login) {
                if (error) {
                        QApplication::restoreOverrideCursor();
                        ftpStatus =tr("無法連接FTP服務器： "
                                "%1. 請檢查主機名、埠、用戶名和密碼是否正確 ")
                                .arg(serverName);
                        emit cmdConncted(false);
                        return;
                }
                ftpStatus =tr("已連接FTP服務器：%1。 ").arg(serverName);
                emit cmdConncted(true);
                return;
        }

        if (ftp->currentCommand() == QFtp::Get) {
                QApplication::restoreOverrideCursor();
                if (error) {
                        ftpStatus =tr("取消下載檔案%1.")
                                .arg(file->fileName());
                        file->close();
                        file->remove();
                        emit cmdGot(true);
                } else {
                        ftpStatus = tr("下載檔案 %1 到當前目錄")
                                .arg(file->fileName());
                        file->close();
                        emit cmdGot(false);
                }
                delete file;
        } else if (ftp->currentCommand() == QFtp::List) {
                QApplication::restoreOverrideCursor();
                if (isDirectory.isEmpty()) {
                        emit cmdList(true);
                }
        }
}

void FtpClient::addToList(const QUrlInfo &urlInfo)
{

        isDirectory[urlInfo.name()] = urlInfo.isDir();
        emit cmdChangeList(urlInfo);
}


void FtpClient::changeDir(const QString& dir)
{
        if(dir.isEmpty())//返回父目錄
        {
                QApplication::setOverrideCursor(Qt::WaitCursor);
                isDirectory.clear();
                currentPath = currentPath.left(currentPath.lastIndexOf('/'));
                if (currentPath.isEmpty()) {
                        ftp->cd("/");
                        emit cmdIsTopDir(true);
                } else {
                        ftp->cd(currentPath);
                }
                ftp->list();
        }
        else//進入子目錄
        {
                if (isDirectory.value(dir)) {
                        isDirectory.clear();
                        currentPath += "/" + dir;
                        ftp->cd(dir);
                        ftp->list();
                        emit cmdIsTopDir(false);
                        QApplication::setOverrideCursor(Qt::WaitCursor);
                }
        }
}

void FtpClient::getFile(const QString& fileName)
{
        if (QFile::exists(fileName)) {
                QMessageBox::information(0, tr("FTP"),
                        tr("%1檔案已存在。")
                        .arg(fileName));
                return;
        }

        file = new QFile(fileName);
        if (!file->open(QIODevice::WriteOnly)) {
                QMessageBox::information(0, tr("FTP"),
                        tr("無法儲存檔案 %1: %2.")
                        .arg(fileName).arg(file->errorString()));
                delete file;
                return;
        }

        ftp->get(fileName, file);

        progressDialog->setLabelText(tr("下載檔案%1...").arg(fileName));
        progressDialog->show();
        emit cmdDownloading();

}

void FtpClient::updateDataTransferProgress(qint64 readBytes,qint64 totalBytes)
{
        progressDialog->setMaximum(totalBytes);
        progressDialog->setValue(readBytes);

}
