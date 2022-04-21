#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class Bullet:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(int check=0,QGraphicsItem* parent=0);
public slots:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};

#endif // BULLET_H
