#include "map.h"
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

    for(int i = 0;i<10;i++)
        for(int j=0;j<20;j++){
            stream>>temp;
            objectCords[i][j] =  temp.toInt();
        }


}
//empty = 0; bedrock wall =1;normal wall =2 ; skull =  3; enemy = 4; triggerBlock = 5
void Map::drawMap()
{
    Wall * wall;Enemy * enemy;//Skull * skull
    for(int i = 0;i<10;i++)
        for(int j=0;j<20;j++){
            if(objectCords[i][j]==1){
                wall = new Wall(0,game->player);//player set as parent
                wall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= wall;
                game->scene->addItem(wall);
                qDebug()<<"Added wal";
            }else if(objectCords[i][j]==2){
                wall = new Wall(1,game->player);//player set as parent
                wall->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= wall;
                game->scene->addItem(wall);
                qDebug()<<"Added wall";
            }else if(objectCords[i][j]==3){
                //skull code
            }else if(objectCords[i][j]==4){
                enemy = new Enemy(game->player);
                enemy->setPos(game->scene->sceneRect().x()+j*60,game->scene->sceneRect().y()+i*60);
                objects[i][j]= enemy;
                game->scene->addItem(enemy);

                qDebug()<<"Added enemy";

            }

        }
}
