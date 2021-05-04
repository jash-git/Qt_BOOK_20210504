import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Row {                                       //所有图标成一行横向排列
        x:50;y:50
        spacing:30
        Rectangle {                             //第一个矩形元素（“音乐”图标）
            id: music
            width: 100; height: 100
            radius: 6
            color: focus ? "red" : "lightgray"  //被选中（获得焦点）时显示红色，否则变灰
            scale: focus ? 1 : 0.8              //被选中（获得焦点）时图标变大
            focus: true                         //初始时选中“音乐”图标
            KeyNavigation.tab: play             //(a)
            /* 移动图标位置 */                    //(b)
            Keys.onUpPressed: music.y -= 10     //上移
            Keys.onDownPressed: music.y += 10	//下移
            Keys.onLeftPressed: music.x -= 10	//左移
            Keys.onRightPressed: music.x += 10	//右移
            Text {								//图标上显示的文本
                anchors.centerIn: parent
                color: parent.focus ? "black" : "gray"  //被选中（获得焦点）时显黑字，否则变灰
                font.pointSize: 20				//字体大小
                text: "音乐"						//文字内容为“音乐”
            }
        }
        Rectangle {                             //第二个矩形元素（“游戏”图标）
            id: play
            width: 100; height: 100
            radius: 6
            color: focus ? "green" : "lightgray"
            scale: focus ? 1 : 0.8
            KeyNavigation.tab: movie				//焦点转移到“影视”图标
            Keys.onUpPressed: play.y -= 10
            Keys.onDownPressed: play.y += 10
            Keys.onLeftPressed: play.x -= 10
            Keys.onRightPressed: play.x += 10
            Text {
                anchors.centerIn: parent
                color: parent.focus ? "black" : "gray"
                font.pointSize: 20
                text: "游戏"
            }
        }
        Rectangle {                             //第三个矩形元素（“影视”图标）
            id: movie
            width: 100; height: 100
            radius: 6
            color: focus ? "blue" : "lightgray"
            scale: focus ? 1 : 0.8
            KeyNavigation.tab: music			//焦点转移到“音乐”图标
            Keys.onUpPressed: movie.y -= 10
            Keys.onDownPressed: movie.y += 10
            Keys.onLeftPressed: movie.x -= 10
            Keys.onRightPressed: movie.x += 10
            Text {
                anchors.centerIn: parent
                color: parent.focus ? "black" : "gray"
                font.pointSize: 20
                text: "影视"
            }
        }
    }
}
