#include <QtGui>
#include <QtScript>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("big5"));

    QScriptEngine engine;

        // QTextBrowser
    QTextEdit textEdit;
    QScriptValue scriptWindow = engine.newQObject(&textEdit);
    engine.globalObject().setProperty("txtEdit", scriptWindow);

        QScriptValue text(&engine,  QObject::tr("<b><font color=#FF0000 size=5>�Ĥ@��QtScript�{��<font></b>"));
    scriptWindow.setProperty("html", text);
    engine.evaluate(QObject::tr("txtEdit.append('�l�[����r')"));
/*    engine.evaluate(QObject::tr("txtEdit.insertPlainText('���J����r')"));
    engine.evaluate(QObject::tr("txtEdit.insertPlainText('�ĤG��')"));*/
    engine.evaluate("txtEdit.show()");

    if(engine.hasUncaughtException()) {
        QScriptValue value = engine.uncaughtException();
        QMessageBox::information(NULL, QObject::tr("Exception"), value.toString());
    }

    return app.exec();
}
