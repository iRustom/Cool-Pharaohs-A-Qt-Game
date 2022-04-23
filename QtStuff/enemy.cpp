#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"
#include <qDebug>

extern Game* game;

Enemy::Enemy(int type, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem() //this should probably be changed to a new abstract class that all of our objects inherit from
{
    //setPos(rand()%600,0);

    setPixmap(QPixmap(":/images/mainCharacterDown.png").scaled(60,60));
    setTransformOriginPoint(pixmap().width()/2,pixmap().height()/2);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(rand()%2000+1000);
    Type = type;
}

void Enemy::move()
{
    QVector<QPoint> notOcc;
    int currentX = pos().x();
    int currentY = pos().y();
    bool moveCheck = false;     //was testing, just in case

    notOcc.push_back(QPoint(currentX, currentY));
    if(game->map.objectCords[currentY/60 - 1][currentX/60] == 0) //up
    {
    notOcc.push_back(QPoint(currentX, currentY - 60));
    moveCheck = true;
    }

    if(game->map.objectCords[currentY/60][currentX/60 + 1] == 0) //right
    {
    notOcc.push_back(QPoint(currentX + 60, currentY));
    moveCheck = true;
    }

    if(game->map.objectCords[currentY/60 + 1][currentX/60] == 0) //down
    {
    notOcc.push_back(QPoint(currentX, currentY + 60));
    moveCheck = true;
    }

    if(game->map.objectCords[currentY/60][currentX/60 - 1] == 0)  //left
    {
    notOcc.push_back(QPoint(currentX - 60, currentY));
    moveCheck = true;
    }
    if (moveCheck == true)
    {
    int rando;
    rando = rand()%notOcc.size();
    qDebug() << "moving from" << QString::number(currentX) << ", " << QString::number(currentY) << "to "<< QString::number(notOcc[rando].x()) << QString::number(notOcc[rando].y());
    setPos(notOcc[rando]);
    }

    //setPos(x(),y()+5);
    //if(pos().y()+pixmap().height()<600){

    //}
}
