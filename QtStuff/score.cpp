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

}

int Score::getScore()
{
    return score;
}
