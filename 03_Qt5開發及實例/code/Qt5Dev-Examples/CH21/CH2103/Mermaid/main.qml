import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Mermaid")
    width: 890
    height: 460
    visible: true
    MainForm {
        anchors.fill: parent
        size.onValueChanged: {			//拖动滑块所要执行的代码
            var scale = size.value;		//变量获取缩放比率
            img.width = 614.4*scale;	//宽度缩放
            img.height = 384*scale;		//高度缩放
        }
        colourful.onCheckedChanged: {	//开关切换彩色/黑白
            desat.desaturation = colourful.checked ? 0.0 : 1.0													//(a)
        }
        btn.onClicked: {				//单击“灰度值>>”按钮所要执行的代码
            if(desat.desaturation < 0.9) {	//若灰度<0.9，则继续增加（变灰）
                desat.desaturation += 0.1;
            }else {						//重新变回彩色
                desat.desaturation = 0.0;
            }
            progreBar.value = desat.desaturation;//进度条的进度与灰度同步改变
        }
    }
}

