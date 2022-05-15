#include "player.h"
#include "bedrockwall.h"
#include "door.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "game.h"
#include "wall.h"
#include "coin.h"

extern Game* game;
Player::Player(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletoutput = new QAudioOutput();

    bulletSound-> setAudioOutput(bulletoutput);
    bulletSound->setSource(QUrl("qrc:/sfx/bulletsound.mp3"));
    if(game->volume == 1){
        bulletoutput->setVolume(100);
    }else{
        bulletoutput->setVolume(0);
    }
    setPixmap(QPixmap(":/images/mainCharacterUp.png").scaled(60,60));
    setTransformOriginPoint(pixmap().width()/2,pixmap().height()/2);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(game->lost==false){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    /*bool stop = false;
    for(int i =0;i<colliding_items.size();i++){
        if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*(colliding_items[i]))==typeid(Enemy)){
            stop= true;
        }
    }*/

    if(event->key()==Qt::Key_Up)
    {
        setRotation(0);
        int currentX = pos().x();
        int currentY = pos().y();
        if(game->map->objectCords[currentY/60-1][currentX/60]!=1 && game->map->objectCords[currentY/60-1][currentX/60]!=2){
            setPos(QPoint(currentX, currentY - 60));
            game->map->objectCords[currentY/60][currentX/60] = 0; // might introduce errors
            game->map->objectCords[currentY/60 -1][currentX/60] = 9;
        }

        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){            
            if(game->lost==false)
                if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                    delete (colliding_items[i]);
                    game->score->increase();
                    game->health->decrease();
                }else if(typeid(*(colliding_items[i]))==typeid(Coin)){
                    delete (colliding_items[i]);
                    game->score->increaseCoins();
            }
        }


    }
     else if(event->key()==Qt::Key_Shift)
    {
        game->display_shop();
    }
    else if(event->key()==Qt::Key_Down)
    {

        setRotation(180);
        int currentX = pos().x();
        int currentY = pos().y();
        if(game->map->objectCords[currentY/60+1][currentX/60]!=1 && game->map->objectCords[currentY/60+1][currentX/60]!=2){
            setPos(QPoint(currentX, currentY + 60));
            game->map->objectCords[currentY/60][currentX/60] = 0; // might introduce errors
            game->map->objectCords[currentY/60 +1][currentX/60] = 9;
        }

        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){
            if(game->lost==false)
                if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                    delete (colliding_items[i]);
                    game->score->increase();
                    game->health->decrease();
                }else if(typeid(*(colliding_items[i]))==typeid(Coin)){
                    delete (colliding_items[i]);
                    game->score->increaseCoins();
            }
        }
    }
    else if(event->key()==Qt::Key_Left)
    {

        setRotation(270);
        int currentX = pos().x();
        int currentY = pos().y();
        if(game->map->objectCords[currentY/60][currentX/60-1]!=1 && game->map->objectCords[currentY/60][currentX/60-1]!=2){
            setPos(QPoint(currentX-60, currentY));
            game->map->objectCords[currentY/60][currentX/60] = 0; // might introduce errors
            game->map->objectCords[currentY/60][currentX/60-1] = 9;
        }

        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){
            if(game->lost==false)
                if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                    delete (colliding_items[i]);
                    game->score->increase();
                    game->health->decrease();
                }else if(typeid(*(colliding_items[i]))==typeid(Coin)){
                    delete (colliding_items[i]);
                    game->score->increaseCoins();
            }
        }

    }
    else if(event->key()==Qt::Key_Right)
    {

        setRotation(90);
        int currentX = pos().x();
        int currentY = pos().y();
        if(game->map->objectCords[currentY/60][currentX/60+1]!=1 && game->map->objectCords[currentY/60][currentX/60+1]!=2){
            setPos(QPoint(currentX+60, currentY));
            game->map->objectCords[currentY/60][currentX/60] = 0; // might introduce errors
            game->map->objectCords[currentY/60][currentX/60+1] = 9;
        }

        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){
            if(game->lost==false)
                if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                    delete (colliding_items[i]);
                    game->score->increase();
                    game->health->decrease();
                }else if(typeid(*(colliding_items[i]))==typeid(Coin)){
                    delete (colliding_items[i]);
                    game->score->increaseCoins();
            }
        }
    }else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet(rotation());
        if (rotation() == 0)
        {
        bullet->setPos(x()+(pixmap().width()/2)-(bullet->pixmap().width()/2),y()-(bullet->pixmap().height()+11));
        scene()->addItem(bullet);
        }
        else if (rotation() == 180)
        {
        bullet->setPos(x()+(pixmap().width()/2)-(bullet->pixmap().width()/2),y()+(pixmap().height()+11));
        scene()->addItem(bullet);
        }
        else if (rotation() == 270)
        {
        bullet->setPos(x()-bullet->pixmap().width()-11,y()+pixmap().height()/2-bullet->pixmap().height()/2);
        scene()->addItem(bullet);
        }
        else if (rotation() == 90)
        {
        bullet->setPos(x()+pixmap().width()+11,y()+pixmap().height()/2-bullet->pixmap().height()/2);
        scene()->addItem(bullet);
        }
        if(bulletSound->playbackState()==QMediaPlayer::PlayingState){
            bulletSound -> setPosition(0);
        }else if(bulletSound->playbackState()==QMediaPlayer::StoppedState){
            bulletSound->play();
        }
    }
}
}

void Player::spawn()
{
    Enemy* enemy = new Enemy(0);
    scene()->addItem(enemy);
}
