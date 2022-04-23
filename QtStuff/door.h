#ifndef DOOR_H
#define DOOR_H
#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QObject>

class Door :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Door(QGraphicsItem * parent=0);

    QPointF nextDestination;
    int endRoomNum;
    static int count;
public slots:
    void teleportPlayer();
    void moveScene();
    void checkCollison();
};

#endif // DOOR_H
