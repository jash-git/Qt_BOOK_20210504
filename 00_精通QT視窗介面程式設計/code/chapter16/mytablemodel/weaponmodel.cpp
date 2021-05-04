#include <QtGui>

#include "weaponmodel.h"

WeaponModel::WeaponModel(QObject *parent)
        : QAbstractTableModel(parent)
{
        armyMap[1] = tr("空軍");
        armyMap[2] = tr("海軍");
        armyMap[3] = tr("陸軍");
        armyMap[4] = tr("海軍陸戰隊");

        weaponMap[1] = tr("轟炸機");
        weaponMap[2] = tr("戰鬥機");
        weaponMap[3] = tr("航空母艦");
        weaponMap[4] = tr("驅逐艦");
        weaponMap[5] = tr("直升機");
        weaponMap[6] = tr("坦克");
        weaponMap[7] = tr("兩棲攻擊艦");
        weaponMap[8] = tr("兩棲戰車");

        populateModel();
}

void WeaponModel::populateModel()
{
        header << tr("軍種") << tr("種類") << tr("武器");
        army << 1 << 2 << 3 << 4 << 2 << 4 << 3 << 1;
        weapon << 1 << 3 << 5 << 7 << 4 << 8 << 6 << 2;
        type << tr("B-2") << tr("尼米茲級") << tr("阿帕奇") << tr("黃蜂級")
                << tr("阿利伯克級") << tr("AAAV") << tr("M1A1") << tr("F-22") ;
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

