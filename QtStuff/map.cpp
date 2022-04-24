#include "map.h"
#include "door.h"
#include "game.h"
#include "enemy.h"
#include "puddle.h"
#include "wall.h"
#include <QDebug>
#include "bedrockwall.h"

extern Game* game;

Map::Map()
{
    qDebug()<<"Map is being created";
    Enemy* enemy = new Enemy(0);
    enemyVec.push_back(enemy);
    qDebug()<<"Map is created";

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
    qDebug()<<"Drawing map";
    Wall * wall;Enemy * enemy;Door* door; BedrockWall* bedrockWall;Puddle* puddle;//Skull * skull
    for(int i = 0;i<20;i++)
        for(int j=0;j<20;j++){
            if(objectCords[i][j]==1){
                qDebug()<<"placeing bedrock";
                bedrockWall = new BedrockWall();//player set as parent
                bedrockWall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= bedrockWall;
                game->scene->addItem(bedrockWall);
                qDebug()<<"placed bedrock";
            }else if(objectCords[i][j]==2){
                qDebug()<<"placing wall";
                wall = new Wall();//player set as parent
                wall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= wall;
                game->scene->addItem(wall);
                qDebug()<<"wall placed";
            }else if(objectCords[i][j]==3){
                qDebug()<<"placing door";
                door = new Door();
                door->setPos(game->scene->sceneRect().x()+j*60 ,game->scene->sceneRect().y()+i*60);
                objects[i][j]= door;
                game->scene->addItem(door);
                qDebug()<<"placed door";
            }else if(objectCords[i][j]==4){
                qDebug()<<"placing enemy";
                enemy = new Enemy(0,game->player);
                qDebug()<<"222";
                enemy->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= enemy;
                enemyVec.push_back(enemy);
                enemy->setZValue(99);
                game->scene->addItem(enemy);
                qDebug()<<"placed enemy";
            }else if(objectCords[i][j]==5){
                qDebug()<<"placing enemy 2";
                enemy = new Enemy(1,game->player);
                enemy->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= enemy;
                enemy->setZValue(99);
                enemyVec.push_back(enemy);
                game->scene->addItem(enemy);

                qDebug()<<"placed enemy 2";

            }else if(objectCords[i][j]==6){
                //boss

            }else if(objectCords[i][j]==7){
                qDebug()<<"placing puddle";
                puddle = new Puddle();
                puddle->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j] = puddle;
                qDebug() << QString::number(game->scene->sceneRect().x()+j*60) << QString::number(game->scene->sceneRect().y()+i*60);
                game->scene->addItem(puddle);
                qDebug()<<"placed puddle";



            }
            else if(objectCords[i][j]==8){
                 //skull
            }

        }
    qDebug()<<"Map is drawn";
}
