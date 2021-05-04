#include "ftplogin.h"

FtpLogin::FtpLogin(QObject *parent)
        : QObject(parent)
{
        connect(&ftp,SIGNAL(done(bool)),this,SLOT(ftpDone(bool)));
        connect(&ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpcommandStarted(int)));
        connect(&ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(ftpcommandFinished(int,bool)));
}

FtpLogin::~FtpLogin()
{

}

bool FtpLogin::logIn(const QUrl &url)
{
        if(!url.isValid()){
                qDebug()<<tr("錯誤:無效 URL")<<endl;
                return false;
        }
        if(url.scheme() !="ftp"){
                qDebug()<<tr("錯誤: URL 必須以 'ftp:'開始")<<endl;
                return false;
        }

        connectId = ftp.connectToHost(url.host(),url.port(21));
        loginId = ftp.login();
        closeId = ftp.close();
        return true;
}

void FtpLogin::ftpcommandStarted(int id)
{
        if(id == connectId){
                qDebug()<<QObject::tr("連接中....")<<endl;
        }else if(id == loginId){
                qDebug()<<QObject::tr("登陸中...")<<endl;
        }else if(id == closeId){
                qDebug()<<QObject::tr("關閉中...")<<endl;
        }
}

void FtpLogin::ftpcommandFinished(int id,bool error)
{
        if(error){
                qDebug()<<QObject::tr("操作錯誤，程序退出！");
                return;
        }

        if(id == connectId){
                qDebug()<<QObject::tr("已連接")<<endl;
        }else if(id == loginId){
                qDebug()<<QObject::tr("已登陸")<<endl;
        }else if(id == closeId){
                qDebug()<<QObject::tr("已關閉")<<endl;
        }
}
void FtpLogin::ftpDone(bool error)
{
        if(error){
                qDebug()<<tr("錯誤:")<<qPrintable(ftp.errorString())<<endl;
        }
        emit done();
}
