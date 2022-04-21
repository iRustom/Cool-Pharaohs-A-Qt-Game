#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"
extern Game * game;

Bullet::Bullet(int check, QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    QTimer * timer = new QTimer();
    setPixmap(QPixmap(":/images/bullet.png").scaled(10,10));

    if(check == 1){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveUp()));
    }else if(check == 2){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveDown()));
    }else if(check == 3){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveLeft()));
    }else if(check == 4){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveRight()));
    }
    timer->start(50);

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
    if(pos().y()+pixmap().height()<0){
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
    if(pos().y()+pixmap().height()<0){
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
    if(pos().y()+pixmap().height()<0){
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
    if(pos().y()+pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
