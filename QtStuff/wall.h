#ifndef WALL_H
#define WALL_H

#include <QGraphicsPixmapItem>

class Wall: public QGraphicsPixmapItem
{
public:
    Wall(int type,QGraphicsItem * parent=0);
    int Type;//0 is bedrock, 1 is not
};

#endif // WALL_H
