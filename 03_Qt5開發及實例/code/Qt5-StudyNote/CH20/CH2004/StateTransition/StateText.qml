import QtQuick 2.0

Text {								//这是一个具有状态改变能力的Text元素
    id: stext
    color: "grey"					//初始文字显示为灰色
    font.family: "Helvetica"		//字体
    font.pointSize: 12				//初始字号12
    font.bold: true					//加粗
    MouseArea {						//能接受鼠标单击
        id: mArea
        anchors.fill: parent
    }
    states: [						//(a)
        State {						//(b)
            name: "highlight"		//(c)
            when: mArea.pressed		//(d)
            PropertyChanges {		//(e)
                target: stext
                color: "red"		//单词变红
                font.pointSize: 25	//字号放大
                style: Text.Raised	//以艺术字呈现
                styleColor: "red"
            }
        }
    ]
    transitions: [					//(f)
        Transition {
            PropertyAnimation {
                duration: 1000
            }
        }
    ]
}

