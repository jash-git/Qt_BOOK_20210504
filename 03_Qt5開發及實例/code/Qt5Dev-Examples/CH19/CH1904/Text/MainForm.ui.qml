import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Text {                                          //普通纯文本
            x:60
            y:100
            color:"green"							//设置颜色
            font.family: "Helvetica"				//设置字体
            font.pointSize: 24						//设置字号
            text: "Hello Qt Quick!"					//输出文字内容
        }
        Text {										//富文本
            x:60
            y:140
            color:"green"
            font.family: "Helvetica"
            font.pointSize: 24
            text: "<b>Hello</b> <i>Qt Quick!</i>"	//(a)
        }
        Text {										//带样式的文本
            x:60
            y:180
            color:"green"
            font.family: "Helvetica"
            font.pointSize: 24
            style: Text.Outline;styleColor:"blue"	//(b)
            text: "Hello Qt Quick!"
        }
        Text {										//带省略的文本
            width:200								//限制文本宽度
            color:"green"
            font.family: "Helvetica"
            font.pointSize: 24
            horizontalAlignment:Text.AlignLeft		//在窗口中左对齐
            verticalAlignment:Text.AlignTop			//在窗口中顶端对齐
            elide:Text.ElideRight					//(c)
            text: "Hello Qt Quick!"
        }
        Text {										//换行的文本
            width:200								//限制文本宽度
            y:30
            color:"green"
            font.family: "Helvetica"
            font.pointSize: 24
            horizontalAlignment:Text.AlignLeft
            wrapMode:Text.WrapAnywhere				//(d)
            text: "Hello Qt Quick!"
        }
}
