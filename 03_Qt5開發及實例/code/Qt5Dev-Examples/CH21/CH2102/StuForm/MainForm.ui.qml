import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3

Item {									//QML通用的根元素
    width: 640
    height: 480
    /* 定义属性别名，为在main.qml中引用各个控件 */
    property alias name: name			//“姓名”文本框
    property alias age: age				//“年龄”文本框
    property alias sex: sexGroup		//“性别”互斥选项组
    property alias spec: speCBox		//“专业”组合框
    property alias hobby: hobbyGrid		//“爱好”GridLayout元素
    property alias submit: submit		//“提交”按钮
    property alias details: stuInfo		//“基本信息”文本区
    RowLayout {							//行布局
        x: 50; y: 35
        spacing: 10
        ColumnLayout {					//列布局
            spacing: 8
            RowLayout {
                spacing: 0
                Label {					/* 标签 */
                    text: "姓名 "
                }
                TextField {				/* 文本框 */
                    id: name
                    placeholderText: qsTr("请输入...")		//(a)
                    focus: true
                }
            }
            RowLayout {
                spacing: 0
                Label {
                    text: "年龄 "
                }
                TextField {
                    id: age
                    validator: IntValidator {bottom: 16; top: 26;}//(b)
                }
            }
            GroupBox {								/* 组框 */
                id: group1
                title: qsTr("性别")
                Layout.fillWidth: true				//(c)
                RowLayout {
                    ExclusiveGroup { id: sexGroup }	/* 互斥选项组*/
                    RadioButton {						/* 单选按钮 */
                        text: qsTr("男")
                        checked: true
                        exclusiveGroup: sexGroup	//(d)
                        Layout.minimumWidth: 65//设置控件所占最小宽度为65
                    }
                    RadioButton {
                        text: qsTr("女")
                        exclusiveGroup: sexGroup
                        Layout.minimumWidth: 65
                    }
                }
            }
            RowLayout {
                spacing: 0
                Label {
                    text: "专业 "
                }
                ComboBox {							/* 组合框 */
                    id: speCBox
                    Layout.fillWidth: true
                    currentIndex: 0		//初始选中项的索引为0（即“计算机”）
                    model: ListModel {					//(e)
                        ListElement { text: "计算机" }
                        ListElement { text: "通信工程" }
                        ListElement { text: "信息网络" }
                    }
                    width: 200
                }
            }
            GroupBox {
                id: group2
                title: qsTr("爱好")
                Layout.fillWidth: true
                GridLayout {						//网格布局
                    id: hobbyGrid
                    columns: 3
                    CheckBox {						/* 复选框 */
                        text: qsTr("旅游")
                        checked: true				//默认选中
                    }
                    CheckBox {
                        text: qsTr("游泳")
                        checked: true
                    }
                    CheckBox {
                        text: qsTr("篮球")
                    }
                    CheckBox {
                        text: qsTr("唱歌")
                    }
                    CheckBox {
                        text: qsTr("舞蹈")
                    }
                    CheckBox {
                        text: qsTr("网购")
                    }
                    CheckBox {
                        text: qsTr("看电视")
                        checked: true
                    }
                    CheckBox {
                        text: qsTr("其他")
                        checked: true
                    }
                }
            }
            Button {							/* 命令按钮 */
                id: submit
                anchors.right: group2.right	//与“爱好”组框右边框锚定
                text: "提交"
            }
        }
        ColumnLayout {
            Layout.alignment: Qt.AlignTop		//使“基本信息”文本区与表单的顶端对齐
            Label {
                text: "基本信息"
                font.pixelSize: 15
                font.bold: true
            }
            TextArea {
                id: stuInfo
                Layout.fillHeight: true	//将文本区拉伸至与表单等高
                width: 240
                text: "学生个人资料..."		//初始文字
                font.pixelSize: 14
            }
        }
    }
}

