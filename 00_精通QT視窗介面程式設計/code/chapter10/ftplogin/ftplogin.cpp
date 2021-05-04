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
                qDebug()<<tr("���~:�L�� URL")<<endl;
                return false;
        }
        if(url.scheme() !="ftp"){
                qDebug()<<tr("���~: URL �����H 'ftp:'�}�l")<<endl;
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
                qDebug()<<QObject::tr("�s����....")<<endl;
        }else if(id == loginId){
                qDebug()<<QObject::tr("�n����...")<<endl;
        }else if(id == closeId){
                qDebug()<<QObject::tr("������...")<<endl;
        }
}

void FtpLogin::ftpcommandFinished(int id,bool error)
{
        if(error){
                qDebug()<<QObject::tr("�ާ@���~�A�{�ǰh�X�I");
                return;
        }

        if(id == connectId){
                qDebug()<<QObject::tr("�w�s��")<<endl;
        }else if(id == loginId){
                qDebug()<<QObject::tr("�w�n��")<<endl;
        }else if(id == closeId){
                qDebug()<<QObject::tr("�w����")<<endl;
        }
}
void FtpLogin::ftpDone(bool error)
{
        if(error){
                qDebug()<<tr("���~:")<<qPrintable(ftp.errorString())<<endl;
        }
        emit done();
}
