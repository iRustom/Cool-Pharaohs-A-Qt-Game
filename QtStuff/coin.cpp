#include "coin.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Coin::Coin(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/coin.png").scaled(30,30));
    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this,SLOT(del()));

    timer->start(10000);
}

void Coin::del()
{
    delete this;
}
