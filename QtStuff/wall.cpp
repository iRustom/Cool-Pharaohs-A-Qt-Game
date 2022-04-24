#include "wall.h"

Wall::Wall(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/sandStone.jpg").scaled(60,60));
}
