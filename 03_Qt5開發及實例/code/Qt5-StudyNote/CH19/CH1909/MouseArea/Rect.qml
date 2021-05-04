import QtQuick 2.0

Rectangle {							//定义一个矩形元素
    width: 50; height: 50			//宽高都是50
    color: "teal"					//初始为蓝绿色
    MouseArea {						//定义MouseArea元素处理鼠标事件
        anchors.fill: parent		//事件响应区充满整个矩形
        /* 拖曳属性设置 */				//(a)
        drag.target: parent
        drag.axis: Drag.XAxis
        drag.minimumX: 0
        drag.maximumX: 360 - parent.width
        acceptedButtons:  Qt.LeftButton|Qt.RightButton	//(b)
        onClicked: {					//处理鼠标事件的代码
            if (mouse.button == Qt.RightButton) {		//(c)
                /* 设置矩形为蓝色并缩小尺寸 */
                parent.color = "blue";
                parent.width -= 5;
                parent.height -= 5;
            }else if((mouse.button == Qt.LeftButton)&&(mouse.modifiers & Qt.ShiftModifier)) {	//(d)
                /* 把矩形重新设为蓝绿色并恢复原来的大小 */
                parent.color = "teal";
                parent.width = 50;
                parent.height = 50;
            }else {
                /* 设置矩形为绿色并增大尺寸 */
                parent.color = "green";
                parent.width += 5;
                parent.height += 5;
            }
        }
    }
}

