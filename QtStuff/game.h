#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "map.h"
#include "player.h"
#include "score.h"
#include "health.h"

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent =0);
    void mainMenu();
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Map map;
public slots:
    void start();
public:
    int volume;
private slots:
    void toggleVol();

};

#endif // GAME_H
