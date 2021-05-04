import QtQuick 2.0

import "myscript.js" as Logic					//导入JS文件
Rectangle {
    id: rect
    width: 60
    height: 60
    gradient: Gradient {						//渐变色增强旋转的视觉效果
        GradientStop { position: 0.0; color: "yellow" }
        GradientStop { position: 0.33; color: "blue" }
        GradientStop { position: 1.0; color: "aqua" }
    }
    Behavior on rotation {                      //行为动画
        RotationAnimation {
            direction: RotationAnimation.Clockwise
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: rect.rotation = Logic.getRandomNumber();	//使用导入JS文件中定义的JavaScript函数
    }
}

