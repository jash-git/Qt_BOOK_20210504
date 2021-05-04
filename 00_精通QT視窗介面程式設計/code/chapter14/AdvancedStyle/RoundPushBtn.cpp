////////////////////////////////////////////////////////////
/// LampPushBtn.cpp
///
/// Created on: 2005-10-23
///      Author: lcf_2
///////////////////////////////////////////////////////////

#include <QtGui/QtGui>

#include "RoundPushBtn.h"


/// 構造函數
CRoundPushBtn::CRoundPushBtn(QWidget* parent)
 :	QPushButton(parent),
        m_Stat(StatUnknown)
{
        ini();
}


void CRoundPushBtn::ini()
{

        /// 設置按鈕大小
        int nLampSz = 28;
        setMinimumSize(nLampSz, nLampSz);
        setMaximumSize(nLampSz, nLampSz);


        /// 設置外觀
        setCheckable(true);
        setChecked(true);
        setFlat(true);
        setEnabled(false);
}

/// 設置燈的狀態
void CRoundPushBtn::setUIState(IndnStat nState)
{
        m_Stat	= nState;
        update();
}
