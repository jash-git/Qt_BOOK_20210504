#include <QtGui>

#include "weaponmodel.h"

WeaponModel::WeaponModel(QObject *parent)
        : QAbstractTableModel(parent)
{
        armyMap[1] = tr("�ŭx");
        armyMap[2] = tr("���x");
        armyMap[3] = tr("���x");
        armyMap[4] = tr("���x���Զ�");

        weaponMap[1] = tr("�F����");
        weaponMap[2] = tr("�԰���");
        weaponMap[3] = tr("��ť�ĥ");
        weaponMap[4] = tr("�X�vĥ");
        weaponMap[5] = tr("���ɾ�");
        weaponMap[6] = tr("�Z�J");
        weaponMap[7] = tr("��ϧ���ĥ");
        weaponMap[8] = tr("��ϾԨ�");

        populateModel();
}

void WeaponModel::populateModel()
{
        header << tr("�x��") << tr("����") << tr("�Z��");
        army << 1 << 2 << 3 << 4 << 2 << 4 << 3 << 1;
        weapon << 1 << 3 << 5 << 7 << 4 << 8 << 6 << 2;
        type << tr("B-2") << tr("���̯���") << tr("�����_") << tr("������")
                << tr("���Q�B�J��") << tr("AAAV") << tr("M1A1") << tr("F-22") ;
}

int WeaponModel::columnCount(const QModelIndex& parent) const
{
        return 3;
}

int WeaponModel::rowCount(const QModelIndex& parent) const
{
        return army.size();
}

QVariant WeaponModel::data(const QModelIndex &index, int role) const
{
        if(!index.isValid())
                return QVariant();
        qDebug() << index;
        if(role == Qt::DisplayRole)
        {
                switch(index.column())
                {
                case 0:
                        return armyMap[army[index.row()]];
                        break;
                case 1:
                        return weaponMap[weapon[index.row()]];
                        break;
                case 2:
                        return type[index.row()];
                default:
                        return QVariant();
                }
        }
        return QVariant();
}

QVariant WeaponModel::headerData(int section, Qt::Orientation orientation, int role) const
{
        if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
                return header[section];
        return QAbstractTableModel::headerData(section, orientation, role);
}

