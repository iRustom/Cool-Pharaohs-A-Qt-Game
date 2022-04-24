#ifndef MAP_H
#define MAP_H
#include "enemy.h"
#include <QGraphicsItem>
#include <QString>
#include <QFile>
#include <QTextStream>
class Map
{
public:
    Map();
    void readMap(QString );
    int objectCords[20][20];
    void  drawMap();
    QGraphicsPixmapItem* objects[20][20];
    QVector<Enemy*> enemyVec;
};

#endif // MAP_H
