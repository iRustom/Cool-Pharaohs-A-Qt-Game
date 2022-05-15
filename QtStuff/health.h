#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsItem>

class Health:public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent = 0);
    void decrease();
    void increase();
    int getHealth();
public:
    int health;
};


#endif // HEALTH_H
