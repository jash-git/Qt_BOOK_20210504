////////////////////////////////////////////////////////////
/// LampPushBtn.cpp
///
/// Created on: 2005-10-23
///      Author: lcf_2
///////////////////////////////////////////////////////////

#include <QtGui/QtGui>

#include "RoundPushBtn.h"


/// �c�y���
CRoundPushBtn::CRoundPushBtn(QWidget* parent)
 :	QPushButton(parent),
        m_Stat(StatUnknown)
{
        ini();
}


void CRoundPushBtn::ini()
{

        /// �]�m���s�j�p
        int nLampSz = 28;
        setMinimumSize(nLampSz, nLampSz);
        setMaximumSize(nLampSz, nLampSz);


        /// �]�m�~�[
        setCheckable(true);
        setChecked(true);
        setFlat(true);
        setEnabled(false);
}

/// �]�m�O�����A
void CRoundPushBtn::setUIState(IndnStat nState)
{
        m_Stat	= nState;
        update();
}
