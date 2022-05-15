#include "bosshealth.h"
#include "game.h"
extern Game * game;
bossHealth::bossHealth()
{
    health = 20;
    setPlainText(QString("       ")+ QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
}
void bossHealth::decrease(){
    if(game->lost==false){
    health--;
    setPlainText(QString("       ")+ QString::number(health));
    if (health == 0)
        game->win();
    }
}
