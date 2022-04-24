#include "player.h"
#include "bedrockwall.h"
#include "door.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "game.h"
#include "wall.h"
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
    setPixmap(QPixmap(":/images/mainCharacterUp.png").scaled(30,30));
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

        if(!stopUp&&!stopDown){
        setPos(x(),y()-10);
        }
        if(stopDown&&!stopUp){
            setPos(x(),y()-11);
        }
        setRotation(0);
        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){
            if(game->lost==false)
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*colliding_items[i])==typeid(BedrockWall)){
                stopUp= true;
            }
            if(game->lost==false)
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                delete (colliding_items[i]);
                game->score->increase();
                game->health->decrease();

            }
        }
        if(stopDown==true){
            stopDown=false;
        }
    }
    else if(event->key()==Qt::Key_Down)
    {
        if(!stopDown&&!stopUp){
        setPos(x(),y()+10);
        }
        if(stopUp&&!stopDown){
            setPos(x(),y()+11);
        }
        setRotation(180);
        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){
            if(game->lost==false)
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*colliding_items[i])==typeid(BedrockWall)){
                stopDown= true;
            }
            if(game->lost==false)
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                delete (colliding_items[i]);
                game->score->increase();
                game->health->decrease();

            }
        }
        if(stopUp==true){
            stopUp = false;
        }
    }
    else if(event->key()==Qt::Key_Left)
    {
        if(!stopLeft&&!stopRight){
            setPos(x()-10,y());
        }
        if(stopRight&&!stopLeft){
            setPos(x()-11,y());
        }
        setRotation(270);
        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){
            if(game->lost==false)
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*colliding_items[i])==typeid(BedrockWall)){
                stopLeft= true;
            }
            if(game->lost==false)
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                 delete (colliding_items[i]);
                game->score->increase();
                game->health->decrease();

            }

        }
        if(stopRight == true){
            stopRight = false;
        }
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(!stopRight&&!stopLeft){
        setPos(x()+10,y());
        }
        if(!stopRight&&stopLeft){
            setPos(x()+11,y());
        }
        setRotation(90);
        colliding_items = collidingItems();
        if(game->lost==false)
        for(int i =0;i<colliding_items.size();i++){
            if(game->lost==false)
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*colliding_items[i])==typeid(BedrockWall)){
                stopRight= true;
            }
            if(game->lost==false)
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                delete (colliding_items[i]);
                game->score->increase();
                game->health->decrease();

            }
        }
        if(stopLeft == true){
            stopLeft = false;
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
