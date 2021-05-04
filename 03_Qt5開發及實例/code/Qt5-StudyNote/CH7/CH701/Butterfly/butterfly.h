#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = 0);
    void timerEvent(QTimerEvent *);				//(a)
    QRectF boundingRect() const;				//(b)

signals:

public slots:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);									//重绘函数
private:
    bool up;									//(c)
    QPixmap pix_up;      						//用于表示两幅蝴蝶的图片
    QPixmap pix_down;
    qreal angle;
};

#endif // BUTTERFLY_H
