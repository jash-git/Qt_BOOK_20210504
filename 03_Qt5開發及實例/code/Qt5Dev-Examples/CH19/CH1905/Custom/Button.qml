import QtQuick 2.0

Rectangle {								//将Rectangle自定义成按钮
    id:btn
    width: 100;height: 62				//按钮的尺寸
    color: "teal"						//按钮颜色
    border.color: "aqua"				//按钮边界色
    border.width: 3						//按钮边界宽度
    Text {								//Text元素作为按钮文本
        id: label
        anchors.centerIn: parent
        font.pointSize: 16
        text: "开始"
    }
    MouseArea {                         //MouseArea对象作为按钮单击事件响应区
        anchors.fill: parent
        onClicked: {					//响应单击事件代码
            label.text = "按钮已按下！"
            label.font.pointSize = 11	//改变按钮文本和字号
            btn.color = "aqua"			//改变按钮颜色
            btn.border.color = "teal"	//改变按钮边界色
        }
    }
}

