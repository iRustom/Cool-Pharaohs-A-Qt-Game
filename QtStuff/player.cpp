#include "player.h"
#include "door.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "game.h"
#include "wall.h"
#include <QDebug>
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
        qDebug("not stop up");
        }
        if(stopDown&&!stopUp){
            setPos(x(),y()-11);
        }
        setRotation(0);
        colliding_items = collidingItems();
        for(int i =0;i<colliding_items.size();i++){
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*(colliding_items[i]))==typeid(Enemy)){
                stopUp= true;
                qDebug("stop up is true");
            }
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                game->health->decrease();
                delete (colliding_items[i]);
                qDebug("Hit enemy");
            }
        }
        if(stopDown==true){
            stopDown=false;
            qDebug("stop down set to false");
        }
    }
    else if(event->key()==Qt::Key_Down)
    {
        if(!stopDown&&!stopUp){
        setPos(x(),y()+10);
        qDebug("not stop down");
        }
        if(stopUp&&!stopDown){
            setPos(x(),y()+11);
        }
        setRotation(180);
        colliding_items = collidingItems();
        for(int i =0;i<colliding_items.size();i++){
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*colliding_items[i])==typeid(Enemy)){
                stopDown= true;
                qDebug(" stop down true");
            }
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                game->health->decrease();
                delete (colliding_items[i]);
                qDebug("Hit enemy");
            }
        }
        if(stopUp==true){
            stopUp = false;
            qDebug(" stop up set false");
        }
    }
    else if(event->key()==Qt::Key_Left)
    {
        if(!stopLeft&&!stopRight){
            setPos(x()-10,y());
            qDebug("Allowed to move left and right");
        }
        if(stopRight&&!stopLeft){
            setPos(x()-11,y());
            qDebug("allowed to move left but not right");
        }
        setRotation(270);
        colliding_items = collidingItems();
        for(int i =0;i<colliding_items.size();i++){
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*(colliding_items[i]))==typeid(Enemy)){
                stopLeft= true;
                qDebug("Stop left set to true");
            }
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                game->health->decrease();
                delete (colliding_items[i]);
                qDebug("Hit enemy");
            }

        }
        if(stopRight == true){
            stopRight = false;
            qDebug("Stop right set to false");
        }
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(!stopRight&&!stopLeft){
        setPos(x()+10,y());
        qDebug("allowed to move left and right");
        }
        if(!stopRight&&stopLeft){
            setPos(x()+11,y());
            qDebug("allowed to move right but not left so big step");
        }
        setRotation(90);
        colliding_items = collidingItems();
        for(int i =0;i<colliding_items.size();i++){
            if(typeid(*colliding_items[i])==typeid(Wall)||typeid(*(colliding_items[i]))==typeid(Enemy)){
                stopRight= true;
                qDebug("stop right set to true");
            }
            if(typeid(*(colliding_items[i]))==typeid(Enemy)){
                game->health->decrease();
                delete (colliding_items[i]);
                qDebug("Hit enemy");
            }
        }
        if(stopLeft == true){
            stopLeft = false;
            qDebug("Stop left set to false");
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

void Player::spawn()
{
    Enemy* enemy = new Enemy(0);
    scene()->addItem(enemy);
}
