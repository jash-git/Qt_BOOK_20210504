#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsItem>
#include <QObject>

class Target : public QGraphicsItem
{
public:
    Target();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

public:
    qreal course;
    qreal speed;
    short type; 		// surface, underwater, air
    short attribute; 	// friend, foe, unknown
    QColor color;
    
protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
};

#endif
