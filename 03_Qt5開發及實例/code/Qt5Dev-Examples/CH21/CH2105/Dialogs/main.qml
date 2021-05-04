import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {                             //主应用窗口
    title: qsTr("对话框示例")
    width: 320
    height: 280
    visible: true
    MainForm {									//主窗体
        id: main								//窗体标识
        anchors.fill: parent
        btnSelect.onClicked: dateDialog.open()	//打开“选择日期”对话框
        btnOpen.onClicked: fileDialog.open()	//打开文件标准对话框
        btnFont.onClicked: fontDialog.open()	//打开字体标准对话框
        btnColor.onClicked: colorDialog.open()	//打开颜色标准对话框
    }
    Dialog {									//(a)
        id: dateDialog
        title: "选择日期"
        width: 275
        height: 300
        standardButtons: StandardButton.Save | StandardButton.Cancel														//(b)
        onAccepted: main.date.text = calendar.selectedDate.toLocaleDateString()		//(c)
        Calendar {								//日历控件
            id: calendar
            //双击日历就等同于单击“Save”按钮
            onDoubleClicked: dateDialog.click(StandardButton.Save)
        }
    }
    FileDialog {								//文件标准对话框
        id: fileDialog
        title: "打开"
        nameFilters: [ "Text files (*.txt)", "Image files (*.jpg *.png)", "All files (*)" ]	//(d)
        onAccepted: main.file.text = fileDialog.fileUrl							//(e)
    }
    FontDialog {								//字体标准对话框
        id: fontDialog
        title: "字体"
        font: Qt.font({ family: "宋体", pointSize: 12, weight: Font.Normal })	//初始默认选中的字体
        modality: Qt.WindowModal				//(f)
        onAccepted: main.content.font = fontDialog.font	//设置字体
    }
    ColorDialog {								//颜色标准对话框
        id: colorDialog
        title: "颜色"
        modality: Qt.WindowModal
        onAccepted: main.content.textColor = colorDialog.color
                                                //设置文字色彩
    }
}

