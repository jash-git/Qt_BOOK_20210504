import QtQuick 2.0

FocusScope {									//(a)
    property alias label: label.text			//(b)
    property alias text: input.text				//(c)
    Row {										//(d)
        spacing: 5
        Text {									//输入提示文本
            id: label
            text: "标签"
        }
        Rectangle{								//(e)
            width: 100
            height: 20
            color: "white"						//白底色
            border.color: "gray"				//灰色边框
            TextInput {							//(f)
                id: input
                anchors.fill: parent			//充满矩形
                anchors.margins: 4
                focus: true						//捕捉焦点
                text: "请输入内容..."				//初始文本
            }
        }
    }
}

