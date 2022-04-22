#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>


class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(int type,QGraphicsItem * parent = 0);
    int Type;
public slots:
    void move();

};

#endif // ENEMY_H
