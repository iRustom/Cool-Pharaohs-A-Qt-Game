#include "map.h"
#include "door.h"
#include "game.h"
#include "enemy.h"
#include "puddle.h"
#include "wall.h"
#include "bedrockwall.h"

extern Game* game;

Map::Map()
{
    //Enemy* enemy = new Enemy(0);
    //enemyVec.push_back(enemy);

}

void Map::readMap(QString fileName)
{
    QFile file(fileName);

    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString temp;

    for(int i = 0;i<20;i++)
        for(int j=0;j<20;j++){
            stream>>temp;
            objectCords[i][j] =  temp.toInt();
        }


}
//empty = 0; bedrock wall =1;normal wall =2 ;door = 3 ; enemy type 1= 4;enemy type 2=5;boss =6; pudlle =7 ;skull =  8; player =9;
void Map::drawMap()
{
    Wall * wall;Enemy * enemy;Door* door; BedrockWall* bedrockWall;Puddle* puddle;//Skull * skull
    for(int i = 0;i<20;i++)
        for(int j=0;j<20;j++){
            if(objectCords[i][j]==1){
                bedrockWall = new BedrockWall();//player set as parent
                bedrockWall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= bedrockWall;
                game->scene->addItem(bedrockWall);
            }else if(objectCords[i][j]==2){
                wall = new Wall();//player set as parent
                wall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= wall;
                game->scene->addItem(wall);
            }else if(objectCords[i][j]==3){
                door = new Door();
                door->setPos(game->scene->sceneRect().x()+j*60 +20,game->scene->sceneRect().y()+i*60+10);
                objects[i][j]= door;
                game->scene->addItem(door);
                wall = new Wall();//player set as parent
                wall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                wall->setZValue(99);
                objects[i][j]= wall;
                game->scene->addItem(wall);
            }else if(objectCords[i][j]==4){
                enemy = new Enemy(0);
                enemy->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= enemy;
                enemyVec.push_back(enemy);
                enemy->setZValue(99);
                game->scene->addItem(enemy);
            }else if(objectCords[i][j]==5){
                enemy = new Enemy(1);
                enemy->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= enemy;
                enemy->setZValue(99);
                enemyVec.push_back(enemy);
                game->scene->addItem(enemy);


            }else if(objectCords[i][j]==6){
                //boss

            }else if(objectCords[i][j]==7){
                puddle = new Puddle();
                puddle->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j] = puddle;
                game->scene->addItem(puddle);


            }
            else if(objectCords[i][j]==8){
                 //skull
            }
            /*QLine * line;
            line = new QLine(600,120,600,180);
            game->scene->addItem(line);
            line = new QLine(960,600,1020,600);
            line = new QLine(600,960,600,1020);
            */


        }
}
