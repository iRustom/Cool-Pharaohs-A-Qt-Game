#ifndef COIN_H
#define COIN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Coin: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Coin(QGraphicsItem* parent=0);
private:

public slots:
    void del();

};

#endif // COIN_H
