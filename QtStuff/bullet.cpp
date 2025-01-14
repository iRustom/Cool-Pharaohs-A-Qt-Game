#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"
#include "wall.h"
#include "door.h"
#include "bedrockwall.h"
#include "coin.h"

extern Game * game;

Bullet::Bullet(int rotateCheck, QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
    QTimer * timer = new QTimer(this);
    setPixmap(QPixmap(":/images/bullet.png").scaled(10,10));

    if(rotateCheck == 0){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveUp()));
    }else if(rotateCheck == 180){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveDown()));
    }else if(rotateCheck == 270){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveLeft()));
    }else if(rotateCheck == 90){
    connect(timer, SIGNAL(timeout()),this,SLOT(moveRight()));
    }
    timer->start(3);
}

void Bullet::moveUp()
{
    if(game->lost!=true){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    if(game->lost!=true)
    for(int i =0;i<colliding_items.size();i++){
        if(game->lost!=true)
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){
            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            scene()->removeItem(colliding_items[i]);

            //bool removed = false;
            for(int j=0;j<game->map->enemyVec.size();j++){
                if(game->map->enemyVec[j]==colliding_items[i]){
                    game->map->enemyVec.erase(game->map->enemyVec.begin()+j);
                    //removed= true;
                }
            }

            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            game->score->increase();
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Player)){

            scene()-> removeItem(this);
            delete this;
            game->health->decrease();

            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Wall) || typeid(*(colliding_items[i]))==typeid(BedrockWall)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Door)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(plsBoss)){
            game->boss->health->decrease();
            int coin_no;
            coin_no = rand()%3 + 1;
            for(int i = 0; i < coin_no; i++){
            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            }
            if(!game->lost)
            delete this;
            return;
        }
    }
    setPos(x(),y()-2);
    if(pos().y()+pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
    }
}

void Bullet::moveDown()
{
    if(game->lost!=true){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    if(game->lost!=true)
    for(int i =0;i<colliding_items.size();i++){
        if(game->lost!=true)
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){
            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            scene()->removeItem(colliding_items[i]);

            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            game->score->increase();


            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Player)){
            scene()-> removeItem(this);
            delete this;
            game->health->decrease();

            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Wall) || typeid(*(colliding_items[i]))==typeid(BedrockWall)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Door)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(plsBoss)){
            game->boss->health->decrease();
            int coin_no;
            coin_no = rand()%3 + 1;
            for(int i = 0; i < coin_no; i++){
            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            }
            if(!game->lost)
            delete this;
            return;
        }
    }
    setPos(x(),y()+2);
    if(pos().y()+pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
    }
}
void Bullet::moveRight()
{
    if(game->lost!=true){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    if(game->lost!=true)
    for(int i =0;i<colliding_items.size();i++){
        if(game->lost!=true)
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){
            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            scene()->removeItem(colliding_items[i]);

            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            game->score->increase();

            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Player)){

            scene()-> removeItem(this);
            delete this;
            game->health->decrease();

            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Wall) || typeid(*(colliding_items[i]))==typeid(BedrockWall)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Door)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(plsBoss)){
            game->boss->health->decrease();
            int coin_no;
            coin_no = rand()%3 + 1;
            for(int i = 0; i < coin_no; i++){
            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            }
            if(!game->lost)
            delete this;
            return;
        }
    }
    setPos(x()+2,y());
    if(pos().y()+pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
    }
}
void Bullet::moveLeft()
{
    if(game->lost!=true){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    if(game->lost!=true)
    for(int i =0;i<colliding_items.size();i++){
        if(game->lost!=true)
        if(typeid(*(colliding_items[i]))==typeid (Enemy)){

            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            scene()->removeItem(colliding_items[i]);

            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            game->score->increase();

            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Player)){

            scene()-> removeItem(this);
            delete this;
            game->health->decrease();

            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Wall)  || typeid(*(colliding_items[i]))==typeid(BedrockWall)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(Door)){

            scene()-> removeItem(this);
            delete this;
            return;
        }else if(typeid(*(colliding_items[i]))==typeid(plsBoss)){
            game->boss->health->decrease();
            int coin_no;
            coin_no = rand()%3 + 1;
            for(int i = 0; i < coin_no; i++){
            Coin * coin = new Coin();
            coin->setPos(x(),y());
            scene()->addItem(coin);
            }
            if(!game->lost)
            delete this;
            return;
        }
    }
    setPos(x()-2,y());
    if(pos().y()+pixmap().height()<0){
        scene()->removeItem(this);
        delete this;
    }
    }
}
