#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"
extern Game * game;

Bullet::Bullet(int check)
{
    QTimer * timer = new QTimer();
    if(check == 1)
    {
    setRect(0,0,10,50);
    connect(timer, SIGNAL(timeout()),this,SLOT(moveUp()));
    timer->start(50);
    }
    if(check == 2)
    {
    setRect(0,0,10,50);
    connect(timer, SIGNAL(timeout()),this,SLOT(moveDown()));
    timer->start(50);
    }
    if(check == 3)
    {
    setRect(0,0,50,10);
    connect(timer, SIGNAL(timeout()),this,SLOT(moveLeft()));
    timer->start(50);
    }
    if(check == 4)
    {
    setRect(0,0,50,10);
    connect(timer, SIGNAL(timeout()),this,SLOT(moveRight()));
    timer->start(50);
    }
}

void Bullet::moveUp()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i<colliding_items.size();i++){
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Testing)){
            game->health->decrease();

            scene()-> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y()+rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveDown()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i<colliding_items.size();i++){
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Testing)){
            game->health->decrease();

            scene()-> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()+10);
    if(pos().y()+rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveRight()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i<colliding_items.size();i++){
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Testing)){
            game->health->decrease();

            scene()-> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x()+10,y());
    if(pos().y()+rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveLeft()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i =0;i<colliding_items.size();i++){
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){

            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Testing)){
            game->health->decrease();

            scene()-> removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x()-10,y());
    if(pos().y()+rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
