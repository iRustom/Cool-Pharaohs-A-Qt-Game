#include "wall.h"

Wall::Wall(int type,QGraphicsItem *parent): QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/sandStone.jpg").scaled(60,60));
    Type = type;
}
