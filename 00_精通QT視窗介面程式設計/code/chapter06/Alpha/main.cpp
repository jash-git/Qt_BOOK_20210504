#include <QApplication>
#include <QtGui>
#include <QTextCodec>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
protected:
        void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private:
    int x,y;
    QPixmap pixmap;
    QPixmap background;
};
// 在構造函數中裝入背景圖
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
        resize(800,600);
        pixmap = QPixmap(100,50);
        background = QPixmap(":/alpha/background.jpg");
        x = -1;
        y = -1;
}
// 鼠標移動時形成一個pixmap
void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
        x = event->x();
        y = event->y();
        pixmap.fill(QColor(255,255,255,127));
        QPainter painter(&pixmap);
        painter.setPen(QColor(255,0,0));
        painter.drawText(20, 40, QString("%1").arg(x) + "," +
                QString("%1").arg(y));
        update();
}
// 繪制背景圖和透明的pixmap
void MyWidget::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);
        painter.drawPixmap(0, 0, background);
        painter.drawPixmap(x, y, pixmap);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    MyWidget widget;
    widget.setMouseTracking(true);
    widget.show();
    return app.exec();
}
