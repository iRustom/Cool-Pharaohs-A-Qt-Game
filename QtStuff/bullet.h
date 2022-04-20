#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>


class Bullet:  public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(int check);
public slots:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};

#endif // BULLET_H
