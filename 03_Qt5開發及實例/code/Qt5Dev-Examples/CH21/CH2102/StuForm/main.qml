import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("学生信息表单")
    width: 500
    height: 320
    visible: true
    MainForm {
        anchors.fill: parent
        submit.onClicked: {				//单击“提交”按钮所要执行的代码
            var hobbyText = "";			//变量用于存放学生兴趣爱好的内容
            for(var i = 0; i < 7; i++) {	//遍历“爱好”组框中的复选框
               /* 生成学生兴趣爱好文本 */
                hobbyText += hobby.children[i].checked ? (hobby.children[i].text + "、") : "";		//(a)
            }
            if(hobby.children[7].checked) {	//若“其他”复选框选中
                hobbyText += "...";
            }
            /* 最终生成的完整学生信息 */
            details.text = "我的名字叫" + name.text + "，是个" + age.text + "岁" +
                    sex.current.text + "生，所学专业是" + spec.currentText +
                    "，业余喜欢" + hobbyText;
        }
    }
}

