#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "map.h"
#include "player.h"
#include "plsboss.h"
#include "score.h"
#include "health.h"
#include "log_in.h"
#include "button.h"
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent =0);
    void mainMenu();
    QGraphicsScene * scene;
    Player * player;
    plsBoss* boss;
    Score * score;
    Health * health;
    Map * map;
    void lose();
    void win();
    bool lost;
public slots:
    void start();
    void display_login();
    void mainMenu2();
    void purchase();
    void resume();
public:
    QGraphicsRectItem*panel;
    QGraphicsTextItem* shop_title;
    QGraphicsTextItem* coin_amount;
    QGraphicsTextItem* health_amount;
    Button* buy_health;
    Button* back;
    int volume;
    void display_shop();
    void display_coins();

private slots:
    void toggleVol();
private:
private:
    class log_in *log;
    void draw(int x,int y, int width, int height, QColor colour, double opacity);

};

#endif // GAME_H
