#include "health.h"
#include <QFont>
#include "game.h"
extern Game* game;
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText(QString("       ")+ QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
}

void Health::decrease()
{
    if(game->lost==false){
    health--;
    setPlainText(QString("       ")+ QString::number(health));
    if (health == 0)
        game->lose();
    }
}

int Health::getHealth()
{
    return health;
}
