import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea
    /* 定义属性别名 */							//(a)
    property alias chgRect1: changingRect1	//矩形changingRect1属性别名
    property alias chgRect2: changingRect2	//矩形changingRect2属性别名
    property alias rRect: redRect			//红矩形redRect属性别名
    width: 360
    height: 360
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    /* 使用Anchor对三个矩形元素进行横向布局 */    //(b)
    BlueRectangle {							//蓝矩形
        id:blueRect
        anchors.left: parent.left			//与窗口左锚线锚定
        anchors.top: parent.top				//与窗口顶锚线锚定
        anchors.leftMargin: 25				//左锚边距（即与窗口左边距）
        anchors.topMargin: 25				//顶锚边距（即与窗口顶边距）
    }
    GreenRectangle {						//绿矩形
        id:greenRect
        anchors.left: blueRect.right		//绿矩形左锚线与蓝矩形的右锚线锚定
        anchors.top: blueRect.top           //绿矩形顶锚线与蓝矩形的顶锚线锚定
        anchors.leftMargin: 40              //左锚边距（即与蓝矩形的间距）
    }
    RedRectangle {					    	//红矩形
        id:redRect
        anchors.left: greenRect.right       //红矩形左锚线与绿矩形的右锚线锚定
        anchors.top: greenRect.top          //红矩形顶锚线与绿矩形的顶锚线锚定
        anchors.leftMargin: 40              //左锚边距（即与绿矩形的间距）
    }
    /* 对比测试Anchor的性质 */                 //(c)
    RedRectangle {
        id:changingRect1
        anchors.left: parent.left           //矩形changingRect1初始与窗体左锚线锚定
        anchors.top: blueRect.bottom
        anchors.leftMargin: 25
        anchors.topMargin: 25
    }
    RedRectangle {
        id:changingRect2
        anchors.left: parent.left           //changingRect2与changingRect1左对齐
        anchors.top: changingRect1.bottom
        anchors.leftMargin: 25
        anchors.topMargin: 20
    }
    /* 复用按钮 */
    Button {
        width:95;height:35					//(d)
        anchors.right: redRect.right
        anchors.top: changingRect2.bottom
        anchors.topMargin: 10
    }
}

