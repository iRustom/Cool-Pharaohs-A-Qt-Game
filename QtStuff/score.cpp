#include "score.h"
#include "game.h"
#include <QFont>
extern Game* game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    if(score>=22){
        game->win();
        return;
    }
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
    if(score>=22){
        game->win();
        return;
    }
    if(score ==5){
        scene()->removeItem(game->map->objects[2][9]);
        delete game->map->objects[2][9];
    }
    if(score ==10){
        scene()->removeItem(game->map->objects[2][10]);
        scene()->removeItem(game->map->objects[9][16]);
        delete game->map->objects[2][10];
        delete game->map->objects[9][16];

    }
    if(score == 20){
        scene()->removeItem(game->map->objects[10][16]);
        scene()->removeItem(game->map->objects[15][10]);
        delete game->map->objects[10][16];
        delete game->map->objects[15][10];
    }
    if(score ==22){
        scene()->removeItem(game->map->objects[15][9]);
        delete game->map->objects[15][9];
    }

}

int Score::getScore()
{
    return score;
}
