#include "map.h"
#include "door.h"
#include "game.h"
#include "enemy.h"
#include "wall.h"
#include <QDebug>
extern Game* game;

Map::Map()
{

}

void Map::readMap(QString fileName)
{
    qDebug()<< "reading file";
    QFile file(fileName);
    if(!file.isOpen()){
        qDebug("file is open");
    }
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString temp;

    for(int i = 0;i<20;i++)
        for(int j=0;j<20;j++){
            stream>>temp;
            objectCords[i][j] =  temp.toInt();
        }


}
//empty = 0; bedrock wall =1;normal wall =2 ;door = 3 ; enemy type 1= 4;enemy type 2=5;boss =6; pudlle =7 ;skull =  8
void Map::drawMap()
{
    Wall * wall;Enemy * enemy;Door* door;//Skull * skull
    for(int i = 0;i<20;i++)
        for(int j=0;j<20;j++){
            if(objectCords[i][j]==1){
                wall = new Wall(0,game->player);//player set as parent
                wall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= wall;
                game->scene->addItem(wall);
                qDebug()<<"Added wall";
            }else if(objectCords[i][j]==2){
                wall = new Wall(1,game->player);//player set as parent
                wall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= wall;
                game->scene->addItem(wall);
                qDebug()<<"Added wall";
            }else if(objectCords[i][j]==3){
                door = new Door();
                door->setPos(game->scene->sceneRect().x()+j*60 ,game->scene->sceneRect().y()+i*60);
                objects[i][j]= door;
                game->scene->addItem(door);
                qDebug("added door");
            }else if(objectCords[i][j]==4){
                enemy = new Enemy(0,game->player);
                enemy->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= enemy;
                game->scene->addItem(enemy);

                qDebug()<<"Added enemy";

            }else if(objectCords[i][j]==5){
                enemy = new Enemy(1,game->player);
                enemy->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= enemy;
                game->scene->addItem(enemy);

                qDebug()<<"Added enemy";

            }else if(objectCords[i][j]==6){
                //boss

            }else if(objectCords[i][j]==7){
                //puddle
            }
            else if(objectCords[i][j]==7){
                 //skull
            }

        }
}
