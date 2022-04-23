#include "door.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
extern Game* game;
Door::Door(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    if(count == 0){
        nextDestination = QPointF(661,121);
        endRoomNum = 2;
        setPixmap(QPixmap(":/images/portal1.png").scaled(60,60));
    }else if(count == 1){
        nextDestination = QPointF(479,121);
        endRoomNum=1;
        setPixmap(QPixmap(":/images/portal2.png").scaled(60,60));

    }else if(count ==2){
        nextDestination = QPointF(1019,660);
        endRoomNum=3;
        setPixmap(QPixmap(":/images/portal3.png").scaled(60,60));

    }else if(count ==3){
        nextDestination = QPointF(959,479);
        endRoomNum=2;
        setPixmap(QPixmap(":/images/portal2.png").scaled(60,60));

    }else if(count==4){
        nextDestination = QPointF(660,900);
        endRoomNum = 3;
        setPixmap(QPixmap(":/images/portal4.png").scaled(60,60));

    }else if(count==5){
        nextDestination = QPointF(480,900);
        endRoomNum = 4;
        setPixmap(QPixmap(":/images/portal1.png").scaled(60,60));

        //boss dialog would go here
    }
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(checkCollison()));
    timer->start(1000);

    count++;
}

void Door::teleportPlayer()
{
    game->player->setPos(nextDestination);
    moveScene();
}

void Door::moveScene()
{
    if(endRoomNum == 1){
        game->setSceneRect(0,0,1200,1200);
    }else if(endRoomNum==2){
        game->setSceneRect(600,0,1200,1200);
    }else if(endRoomNum==3){
        game->setSceneRect(600,600,1200,1200);
    }else if(endRoomNum==4){
        game->setSceneRect(0,600,1200,1200);
    }
}

void Door::checkCollison()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(Player)){
            teleportPlayer();
        }
    }
}
