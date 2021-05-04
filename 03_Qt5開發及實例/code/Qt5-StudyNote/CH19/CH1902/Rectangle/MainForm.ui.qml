import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea
    property alias topRect: topRect				//定义属性别名
    width: 360
    height: 360
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    /* 添加定义两个Rectangle对象 */
    Rectangle {
        rotation: 45 							//旋转45度
        x: 40									//x方向的坐标
        y: 60									//y方向的坐标
        width: 100								//矩形宽度
        height: 100								//矩形高度
        color: "red"							//以纯色（红色）填充
    }
    Rectangle {
        id: topRect								//id标识符
        opacity: 0.6    						//设置透明度 60%
        scale: 0.8 								//缩小为原尺寸的 80%
        x: 135
        y: 60
        width: 100
        height: 100
        radius: 8 								//绘制圆角矩形
        gradient: Gradient { 					//(a)
            GradientStop { position: 0.0; color: "aqua" }
            GradientStop { position: 1.0; color: "teal" }
        }
        border { width: 3; color: "blue" }      //为矩形添加一个3像素宽的蓝色边框
    }
}

