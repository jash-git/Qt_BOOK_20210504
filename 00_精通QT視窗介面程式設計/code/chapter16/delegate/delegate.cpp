#include <QtGui>

#include "delegate.h"

EditorDelegate::EditorDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

QWidget *EditorDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem& option,
    const QModelIndex& index) const
{
        if(index.column() == 1)		// birthday
        {
        QDateTimeEdit *editor = new QDateTimeEdit(parent);
        editor->setDisplayFormat("yyyy/M/dd");
        editor->setCalendarPopup(true);
        return editor;
        }
        else if(index.column() == 2)	// height
        {
                QSpinBox *editor = new QSpinBox(parent);
                editor->setMinimum(140);
                editor->setMaximum(200);
                return editor;
        }
        else if(index.column() == 3)	// city
        {
                QComboBox *editor = new QComboBox(parent);
                editor->addItem(tr("基隆"));
                editor->addItem(tr("台東"));
                editor->addItem(tr("花蓮"));
                editor->addItem(tr("台北"));
                editor->addItem(tr("台中"));
                editor->addItem(tr("台南"));
                editor->addItem(tr("高雄"));
                editor->addItem(tr("屏東"));
                editor->addItem(tr("宜蘭"));
                return editor;
        }
        else
                return QItemDelegate::createEditor(parent, option, index);
}

void EditorDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex& index) const
{
        if(index.column() == 1)		// birthday
        {
        QDateTimeEdit *dateEditor = qobject_cast<QDateTimeEdit *>(editor);
        if (dateEditor) {
            dateEditor->setDate(QDate::fromString(index.model()->data(index, Qt::EditRole).toString(), "yyyy/M/d"));
        }
        }
        else if(index.column() == 2)	// height
        {
                QSpinBox *spinEditor = qobject_cast<QSpinBox *>(editor);
                if(spinEditor)
                        spinEditor->setValue(index.model()->data(index, Qt::EditRole).toInt());
        }
        else if(index.column() == 3)	// city
        {
                QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
                if(comboBox)
                {
                        int i = comboBox->findText(index.model()->data(index, Qt::EditRole).toString());
                        comboBox->setCurrentIndex(i);
                }
        }
        else
                return QItemDelegate::setEditorData(editor, index);
}

void EditorDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex& index) const
{
        if(index.column() == 1)		// birthday
        {
        QDateTimeEdit *dateEditor = qobject_cast<QDateTimeEdit *>(editor);
        if (dateEditor) {
            model->setData(index, dateEditor->date().toString("yyyy/M/d"));
        }
    }
        else if(index.column() == 2)	// height
        {
                QSpinBox *spinEditor = qobject_cast<QSpinBox *>(editor);
                if(spinEditor)
                        model->setData(index, QString("%1").arg(spinEditor->value()));
        }
        else if(index.column() == 3)	// city
        {
                QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
                if(comboBox)
                {
                        model->setData(index, comboBox->currentText());
                }
        }
        else
                return QItemDelegate::setModelData(editor, model, index);
}

void EditorDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
