#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class EnemyBullet:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    EnemyBullet(int check=0,QGraphicsItem* parent=0);
public slots:
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};
#endif // ENEMYBULLET_H
