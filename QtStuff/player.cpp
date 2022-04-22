#include "player.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "game.h"
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
    setPixmap(QPixmap(":/images/mainCharacterUp.png").scaled(100,100));
    setTransformOriginPoint(pixmap().width()/2,pixmap().height()/2);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        if(pos().y()>0)
        setPos(x(),y()-10);
        setRotation(0);
    }
    else if(event->key()==Qt::Key_Down)
    {
        if(pos().y()+pixmap().height()<600)
        setPos(x(),y()+10);
        setRotation(180);
    }
    else if(event->key()==Qt::Key_Left)
    {
        if(pos().x()>0)
        setPos(x()-10,y());
        setRotation(270);
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x()+pixmap().width()<600)
        setPos(x()+10,y());
        setRotation(90);
    }else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet(rotation());
        if (rotation() == 0)
        {
        bullet->setPos(x()+(pixmap().width()/2)-(bullet->pixmap().width()/2),y()-(bullet->pixmap().height()+1));
        scene()->addItem(bullet);
        }
        else if (rotation() == 180)
        {
        bullet->setPos(x()+(pixmap().width()/2)-(bullet->pixmap().width()/2),y()+(pixmap().height()+1));
        scene()->addItem(bullet);
        }
        else if (rotation() == 270)
        {
        bullet->setPos(x()-bullet->pixmap().width()-1,y()+pixmap().height()/2-bullet->pixmap().height()/2);
        scene()->addItem(bullet);
        }
        else if (rotation() == 90)
        {
        bullet->setPos(x()+pixmap().width()+1,y()+pixmap().height()/2-bullet->pixmap().height()/2);
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
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
