import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Grid {										//Grid定位器
        x:25;y:25
        spacing: 4
        //用重复器为Grid添加元素成员
        Repeater {								//(a)
            model: 16							//要创建元素成员的个数
            Rectangle {							//成员皆为矩形元素
                width: 48; height: 48
                color:"aqua"
                Text {							//显示矩形编号
                    anchors.centerIn: parent
                    color: "black"
                    font.pointSize: 20
                    text: index					//(b)
                }
            }
        }
    }
}
