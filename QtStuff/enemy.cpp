#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy(): QObject(), QGraphicsRectItem() //this should probably be changed to a new abstract class that all of our objects inherit from
{
    setPos(rand()%600,0);
    setRect(0,0,100,100);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y()+rect().height()<600){

    }
}
