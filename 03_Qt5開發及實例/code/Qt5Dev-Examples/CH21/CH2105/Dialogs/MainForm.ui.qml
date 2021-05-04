import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3

Item {                                      //QML通用的根元素
    width: 320
    height: 280
    /* 定义属性别名，为在main.qml中引用各个控件 */
    property alias date: date				//“日期”文本框
    property alias btnSelect: btnSelect		//“选择...”按钮
    property alias file: file				//“文件”文本框
    property alias btnOpen: btnOpen			//“打开...”按钮
    property alias content: content			//文本区
    property alias btnFont: btnFont			//“字体...”按钮
    property alias btnColor: btnColor		//“颜色...”按钮
    ColumnLayout {							//列布局
        anchors.centerIn: parent
        RowLayout {							//该行提供日期选择功能
            Label {
                text: "日期："
            }
            TextField {
                id: date
            }
            Button {
                id: btnSelect
                text: qsTr("选择...")
            }
        }
        RowLayout {							//该行提供文件选择功能
            Label {
                text: "文件："
            }
            TextField {
                id: file
            }
            Button {
                id: btnOpen
                text: qsTr("打开...")
            }
        }
        TextArea {							//文本区
            id: content
            Layout.fillWidth: true			//将文本区拉伸至与上两栏等宽
            text: "我喜欢Qt Quick编程。"		//文本内容
            font.pixelSize: 14
        }
        RowLayout {							//该行提供字体、颜色选择功能
            Layout.alignment: Qt.AlignRight	//右对齐
            Button {
                id: btnFont
                text: qsTr("字体...")
            }
            Button {
                id: btnColor
                text: qsTr("颜色...")
            }
        }
    }
}

