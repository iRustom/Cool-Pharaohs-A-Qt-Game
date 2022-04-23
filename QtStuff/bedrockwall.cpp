#include "bedrockwall.h"

BedrockWall::BedrockWall(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/sandStone.jpg").scaled(60,60));
}
