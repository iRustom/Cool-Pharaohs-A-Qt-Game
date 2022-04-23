#include "wall.h"

Wall::Wall(QGraphicsItem *parent): QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/sandStone.jpg").scaled(60,60));
}
