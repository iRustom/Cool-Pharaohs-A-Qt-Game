#include "score.h"
#include "game.h"
#include <QFont>
extern Game* game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    coins = 0;
    setPlainText(QString("Score: ") + QString::number(score)+QString(" Coins: ")+QString::number(coins));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    if(score>=22){
        //game->win();
        return;
    }
    score++;
    setPlainText(QString("Score: ") + QString::number(score)+QString(" Coins: ")+QString::number(coins));
    if(score>=22){
        //game->win();
        return;
    }
    if(score ==5){
        scene()->removeItem(game->map->objects[2][9]);
        delete game->map->objects[2][9];
        game->map->objectCords[2][9] = 0;
    }
    if(score ==10){
        scene()->removeItem(game->map->objects[2][10]);
        scene()->removeItem(game->map->objects[9][16]);
        delete game->map->objects[2][10];
        game->map->objectCords[2][10] = 0;

        delete game->map->objects[9][16];
        game->map->objectCords[9][16] = 0;


    }
    if(score == 20){
        scene()->removeItem(game->map->objects[10][16]);
        scene()->removeItem(game->map->objects[15][10]);
        delete game->map->objects[10][16];
        game->map->objectCords[10][16] = 0;
        delete game->map->objects[15][10];
        game->map->objectCords[15][10] = 0;

    }
    if(score ==22){
        scene()->removeItem(game->map->objects[15][9]);
        delete game->map->objects[15][9];
        game->map->objectCords[15][9] = 0;

    }

}

int Score::getScore()
{
    return score;
}

void Score::increaseCoins()
{
    coins++;
    setPlainText(QString("Score: ") + QString::number(score)+QString(" Coins: ")+QString::number(coins));

}

void Score::decreaseCoins()
{
    coins--;
    setPlainText(QString("Score: ") + QString::number(score)+QString(" Coins: ")+QString::number(coins));

}

int Score::getCoins()
{
    return coins;
}
