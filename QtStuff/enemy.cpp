#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

Enemy::Enemy(int type, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem() //this should probably be changed to a new abstract class that all of our objects inherit from
{
    //setPos(rand()%600,0);

    setPixmap(QPixmap(":/images/mainCharacterDown.png").scaled(60,60));
    setTransformOriginPoint(pixmap().width()/2,pixmap().height()/2);

    /*QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);*/
    Type = type;
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y()+pixmap().height()<600){

    }
}
