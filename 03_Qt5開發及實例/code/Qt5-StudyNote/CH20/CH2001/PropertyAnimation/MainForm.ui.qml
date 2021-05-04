import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit
    property alias rect4: rect4         //属性别名，为能在main.qml中引用Rect4

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    TextEdit {
        id: textEdit
        visible: false
    }

    Column {								//初始时以列布局排列各矩形
        x:50; y:30
        spacing: 5
        Rect1 { }							//“属性值源”矩形
        Rect2 { }							//“信号处理”矩形
        Rect3 { }							//“独立元素”矩形
        Rect4 {id: rect4 }					//“改变行为”矩形
    }
}
