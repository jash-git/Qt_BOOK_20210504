import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.3			//导入Qt Quick控件样式库
Item {										//QML通用的根元素
    id: window
    width: 600
    height: 240
    property int columnWidth: window.width/5
//公共属性columnWidth用于设置控件列宽
    GridLayout {								//网格布局
        rowSpacing: 12						//行距
        columnSpacing: 30					//列距
        anchors.top: parent.top				//与主窗体顶端对齐
        anchors.horizontalCenter: parent.horizontalCenter
//在主窗体居中
        anchors.margins: 30					//锚距30
        Button {								/* 标准Button控件 */
            text: "标准按钮"
            implicitWidth: columnWidth		//(a)
        }
        Button {						/* 设置样式属性的Button控件 */
            text: "样式属性"
            style: ButtonStyle {				//样式属性
                background: BorderImage {		//(b)
                    source: control.pressed ? "images/button-pressed.png":
"images/button.png"
                    border.left: 4 ; border.right: 4 ; border.top: 4 ; border.bottom: 4
                }
            }
            implicitWidth: columnWidth
        }
        Button {							/* 应用样式代理的Button控件 */
            text: "样式代理"
            style: buttonStyle			//buttonStyle为样式代理名
            implicitWidth: columnWidth
        }
        TextField {						/* 标准TextField控件 */
            Layout.row: 1		//指定在GridLayout中的行号为1（第2行）
            implicitWidth: columnWidth
        }
        TextField {						/* 设置样式属性的TextField控件 */
            style: TextFieldStyle {		//样式属性
                background: BorderImage {
//设置背景图片为textfield.png
                    source: "images/textfield.png"
                    border.left: 4 ; border.right: 4 ; border.top: 4 ; border.bottom: 4
                }
            }
            implicitWidth: columnWidth
        }
        TextField {			  		/* 应用样式代理的TextField控件 */
            style: textFieldStyle	//textFieldStyle为样式代理名
            implicitWidth: columnWidth
        }
        Slider {						/* 标准Slider控件 */
            id: slider1
            Layout.row: 2				//指定在GridLayout中的行号为2（第3行）
            value: 0.5				//初始值
            implicitWidth: columnWidth
        }
        Slider {						/* 设置样式属性的Slider控件 */
            id: slider2
            value: 0.5
            implicitWidth: columnWidth
            style: SliderStyle {		//样式属性
                groove: BorderImage {		//(c)
                    height: 6
                    border.top: 1
                    border.bottom: 1
                    source: "images/progress-background.png"
                    border.left: 6
                    border.right: 6
                    BorderImage {
                        anchors.verticalCenter: parent.verticalCenter
                        source: "images/progress-fill.png"
                        border.left: 5 ; border.top: 1
                        border.right: 5 ; border.bottom: 1
                        width: styleData.handlePosition
//宽度至手柄（滑块）的位置
                        height: parent.height
                    }
                }
                handle: Item {			 //(d)
                    width: 13
                    height: 13
                    Image {
                        anchors.centerIn: parent
                        source: "images/slider-handle.png"
                    }
                }
            }
        }
        Slider {								/* 应用样式代理的Slider控件 */
            id: slider3
            value: 0.5
            implicitWidth: columnWidth
            style: sliderStyle				//sliderStyle为样式代理名
        }
        ProgressBar {						/* 标准ProgressBar控件 */
            Layout.row: 3		//指定在GridLayout中的行号为3（第4行）
            value: slider1.value				//进度值设为与滑动条同步
            implicitWidth: columnWidth
        }
        /* 以下两个为应用不同样式代理的ProgressBar控件 */
        ProgressBar {
            value: slider2.value
            implicitWidth: columnWidth
            style: progressBarStyle	//应用样式代理progressBarStyle
        }
        ProgressBar {
            value: slider3.value
            implicitWidth: columnWidth
            style: progressBarStyle2 //应用样式代理progressBarStyle2
        }
    }
    /* 以下为定义各样式代理的代码 */
    property Component buttonStyle: ButtonStyle {
/* Button控件所使用的样式代理 */
        background: Rectangle {				//按钮背景为矩形
            implicitHeight: 22
            implicitWidth: columnWidth
          //按钮被按下或获得焦点时变色
            color: control.pressed ? "darkGray" : control.activeFocus ? "#cdd" : "#ccc"
            antialiasing: true				//平滑边缘反锯齿
            border.color: "gray"				//灰色边框
            radius: height/2					//圆角形
            Rectangle {			  //该矩形为按钮自然状态（未被按下）的背景
                anchors.fill: parent
                anchors.margins: 1
                color: "transparent"			//透明色
                antialiasing: true
                visible: !control.pressed		//在按钮未被按下时可见
                border.color: "#aaffffff"
                radius: height/2
            }
        }
    }
    property Component textFieldStyle: TextFieldStyle {
/* TextField控件所使用的样式代理 */
        background: Rectangle {				//文本框背景为矩形
            implicitWidth: columnWidth
            color: "#f0f0f0"
            antialiasing: true
            border.color: "gray"
            radius: height/2
            Rectangle {
                anchors.fill: parent
                anchors.margins: 1
                color: "transparent"
                antialiasing: true
                border.color: "#aaffffff"
                radius: height/2
            }
        }
    }
    property Component sliderStyle: SliderStyle {
/* Slider控件所使用的样式代理 */
        handle: Rectangle {						//定义矩形作为滑块
            width: 18
            height: 18
            color: control.pressed ? "darkGray" : "lightGray"
//按下时灰度改变
            border.color: "gray"
            antialiasing: true
            radius: height/2						//滑块呈圆形
            Rectangle {
                anchors.fill: parent
                anchors.margins: 1
                color: "transparent"
                antialiasing: true
                border.color: "#eee"
                radius: height/2
            }
        }
        groove: Rectangle {						//定义滑动条的横槽
            height: 8
            implicitWidth: columnWidth
            implicitHeight: 22
            antialiasing: true
            color: "#ccc"
            border.color: "#777"
            radius: height/2		//使得滑动条横槽两端有弧度（外观显平滑）
            Rectangle {
                anchors.fill: parent
                anchors.margins: 1
                color: "transparent"
                antialiasing: true
                border.color: "#66ffffff"
                radius: height/2
            }
        }
    }
    property Component progressBarStyle: ProgressBarStyle {	/* ProgressBar控件所使用的样式代理1 */
        background: BorderImage {					//样式背景图片
            source: "images/progress-background.png"
            border.left: 2 ; border.right: 2 ; border.top: 2 ; border.bottom: 2
        }
        progress: Item {								//(e)
            clip: true
            BorderImage {
                anchors.fill: parent
                anchors.rightMargin: (control.value < control.maximumValue) ? -4 : 0
                source: "images/progress-fill.png"
                border.left: 10 ; border.right: 10
                Rectangle {
                    width: 1
                    color: "#a70"
                    opacity: 0.8
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 1
                    anchors.right: parent.right
                    visible: control.value < control.maximumValue												//进度值未到头时始终可见
                    anchors.rightMargin: -parent.anchors.rightMargin											//两者锚定互补达到进度效果
                }
            }
        }
    }
    property Component progressBarStyle2: ProgressBarStyle
{/* ProgressBar控件所使用的样式代理2 */
        background: Rectangle {
            implicitWidth: columnWidth
            implicitHeight: 24
            color: "#f0f0f0"
            border.color: "gray"
        }
        progress: Rectangle {
            color: "#ccc"
            border.color: "gray"
            Rectangle {
                color: "transparent"
                border.color: "#44ffffff"
                anchors.fill: parent
                anchors.margins: 1
            }
        }
    }
}

