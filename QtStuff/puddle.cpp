#include "puddle.h"

Puddle::Puddle(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":images/puddle.png").scaled(60,60));
}
