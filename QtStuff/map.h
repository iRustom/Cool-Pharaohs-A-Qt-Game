#ifndef MAP_H
#define MAP_H
#include <QGraphicsItem>
#include <QString>
#include <QFile>
#include <QTextStream>
class Map
{
public:
    Map();
    void readMap(QString );
    int objectCords[10][20];
    void  drawMap();
    QGraphicsPixmapItem* objects[10][20];
};

#endif // MAP_H
