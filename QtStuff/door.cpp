#include "door.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
extern Game* game;
Door::Door(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    if(count%6 == 0){
        nextDestination = QPointF(661,121);
        endRoomNum = 2;
        setPixmap(QPixmap(":/images/portal1.png").scaled(40,40));
    }else if(count%6 == 1){
        nextDestination = QPointF(479,121);
        endRoomNum=1;
        setPixmap(QPixmap(":/images/portal2.png").scaled(40,40));

    }else if(count%6 ==2){
        nextDestination = QPointF(969,661);
        endRoomNum=3;
        setPixmap(QPixmap(":/images/portal3.png").scaled(40,40));

    }else if(count%6 ==3){
        nextDestination = QPointF(969,491);
        endRoomNum=2;
        setPixmap(QPixmap(":/images/portal2.png").scaled(40,40));

    }else if(count%6==4){
        nextDestination = QPointF(660,900);
        endRoomNum = 3;
        setPixmap(QPixmap(":/images/portal4.png").scaled(40,40));

    }else if(count%6==5){
        nextDestination = QPointF(480,900);
        endRoomNum = 4;
        setPixmap(QPixmap(":/images/portal1.png").scaled(40,40));

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
    for(int i=0;i<game->map->enemyVec.size();i++)
    {
        game->map->enemyVec.at(i)->active=false;
     }

    if(endRoomNum == 1){
        game->setSceneRect(0,0,600,600);
        game->xOff = 0;
        game->yOff = 0;
        game->score->setPos(0,0);


    }else if(endRoomNum==2){
        game->setSceneRect(600,0,600,600);
        game->score->setPos(600,0);
        game->xOff = 600;
        game->yOff = 0;


    }else if(endRoomNum==3){
        game->setSceneRect(600,600,600,600);
        game->score->setPos(600,600);
        game->xOff = 600;
        game->yOff = 600;


    }else if(endRoomNum==4){
        game->setSceneRect(0,600,600,600);
        game->score->setPos(0,600);
        game->xOff = 0;
        game->yOff = 600;


    }

}

void Door::checkCollison()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(Player)){
            if(endRoomNum==1){
                teleportPlayer();
            }else if(endRoomNum==2 &&game->score->getScore()>=5){
                teleportPlayer();
            }else if(endRoomNum==3 &&game->score->getScore()>=10){
                teleportPlayer();
            }else if(endRoomNum==4 &&game->score->getScore()>=20){
                teleportPlayer();
            }

        }
    }
}
