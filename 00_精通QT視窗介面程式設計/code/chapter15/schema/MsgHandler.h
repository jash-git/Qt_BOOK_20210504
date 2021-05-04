//----------------------------------*-C++-*------------------------------------
//      版權所有 (C) 作者獨立享有版權。
//      保留所有版權，未經授權，任何單位和個人不得擅自複製、使用本成果。
//-----------------------------------------------------------------------------
//      版本號 0.01
//-----------------------------------------------------------------------------
//	文件名: MsgHandler.h		類名：MsgHandler
//-----------------------------------------------------------------------------
//      編制說明  :
//-----------------------------------------------------------------------------
//	開發組:無名
//	創建人			創建時間
//	李立夏			2010-8-29
//-----------------------------------------------------------------------------
//	開發組:無名
//
//	修改人員			修改日期			修改內容
//
//
//-----------------------------------------------------------------------------


#ifndef MSGHANDLER_H_
#define MSGHANDLER_H_

#include <QAbstractMessageHandler>

class MsgHandler : public QAbstractMessageHandler
{
    public:
        MsgHandler()
            : QAbstractMessageHandler(0)
        {
        }

        QString statusMessage() const
        {
            return m_description;
        }

        int line() const
        {
            return m_sourceLocation.line();
        }

        int column() const
        {
            return m_sourceLocation.column();
        }

    protected:
        virtual void handleMessage(QtMsgType type, const QString &description,
                                   const QUrl &identifier, const QSourceLocation &sourceLocation)
        {
            Q_UNUSED(type);
            Q_UNUSED(identifier);

            m_description = description;
            m_sourceLocation = sourceLocation;
        }

    private:
        QString m_description;
        QSourceLocation m_sourceLocation;
};

#endif /* MSGHANDLER_H_ */
