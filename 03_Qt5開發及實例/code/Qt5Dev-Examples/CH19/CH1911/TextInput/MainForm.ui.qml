import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360
    color: "lightgray"					//背景设为亮灰色为突出文本框效果

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    /* 以下直接使用定义好的复合组件，生成所需文本框控件 */
    TextBox {							//“学号”文本框
        id: tBx1
        x:25; y:25
        focus: true						//初始焦点之所在
        label: "学号"					//设置提示标签文本为“学号”
        text: focus ? "" : "请输入内容..."	//获得焦点则清空提示文字，由用户输入内容
        KeyNavigation.tab: tBx2         //按【Tab】键焦点转移至“姓名”文本框
    }
    TextBox {							//“姓名”文本框
        id: tBx2
        x:25; y:60
        label: "姓名"
        text: focus ? "" : "请输入内容..."
        KeyNavigation.tab: tBx1         //按【Tab】键焦点又回到“学号”文本框
    }
}
