#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "testing.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent =0);
    QGraphicsScene * scene;
    Testing * player;
};

#endif // GAME_H
