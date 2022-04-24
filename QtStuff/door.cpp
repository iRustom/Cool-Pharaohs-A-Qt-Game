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
        nextDestination = QPointF(969,661);
        endRoomNum=3;
        setPixmap(QPixmap(":/images/portal3.png").scaled(60,60));

    }else if(count ==3){
        nextDestination = QPointF(969,491);
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
    qDebug()<<"Trying to move scene";
    for(int i=0;i<game->map->enemyVec.size();i++)
    {
        game->map->enemyVec[i]->active=false;
     }
    qDebug()<<"active set to false";
    if(endRoomNum == 1){
        game->setSceneRect(0,0,600,600);
        game->score->setPos(0,0);
        for(int i=0;i<game->map->enemyVec.size();i++)
        {
            if(game->map->enemyVec[i]->pos().x()<600 && game->map->enemyVec[i]->pos().y()<600)
                game->map->enemyVec[i]->active=true;
         }
        qDebug()<<"Room 1 set to active";
    }else if(endRoomNum==2){
        game->setSceneRect(600,0,600,600);
        game->score->setPos(600,0);
        qDebug()<<"ur mom"<<QString::number(game->map->enemyVec.size());
        for(int i=0;i<game->map->enemyVec.size()-1;i++)
        {
            qDebug()<<QString::number(i)<<" ur momzzz "<<QString::number(game->map->enemyVec[i]->Type);
            if(game->map->enemyVec[i]->pos().x()>600 && game->map->enemyVec[i]->pos().y()<600)
                game->map->enemyVec[i]->active=true;
         }
         qDebug()<<"Room one set to active";
    }else if(endRoomNum==3){
        game->setSceneRect(600,600,600,600);
        game->score->setPos(600,600);
        for(int i=0;i<game->map->enemyVec.size();i++)
        {
            if(game->map->enemyVec[i]->pos().x()>600 && game->map->enemyVec[i]->pos().y()>600)
                game->map->enemyVec[i]->active=true;
         }
    }else if(endRoomNum==4){
        game->setSceneRect(0,600,600,600);
        game->score->setPos(0,600);
        for(int i=0;i<game->map->enemyVec.size();i++)
        {
            if(game->map->enemyVec[i]->pos().x()<600 && game->map->enemyVec[i]->pos().y()>600)
                game->map->enemyVec[i]->active=true;
         }
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
