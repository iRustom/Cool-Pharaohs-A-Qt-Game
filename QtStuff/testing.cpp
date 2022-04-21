#include "testing.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
Testing::Testing()
{
    bulletSound = new QMediaPlayer();
    bulletoutput = new QAudioOutput();

    bulletSound-> setAudioOutput(bulletoutput);
    bulletSound->setSource(QUrl("qrc:/sfx/arrow.mp3"));
    bulletoutput->setVolume(100);

    check = 1;
}

void Testing::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        if(pos().y()>0)
        setPos(x(),y()-10);
        check = 1;
    }
    else if(event->key()==Qt::Key_Down)
    {
        if(pos().y()+rect().height()<600)
        setPos(x(),y()+10);
        check = 2;
    }
    else if(event->key()==Qt::Key_Left)
    {
        if(pos().x()>0)
        setPos(x()-10,y());
        check = 3;
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x()+rect().width()<600)
        setPos(x()+10,y());
        check = 4;
    }else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet(check);
        if (check == 1)
        {
        bullet->setPos(x()+(rect().width()/2)-(bullet->rect().width()/2),y()-(bullet->rect().height()+1));
        scene()->addItem(bullet);
        }
        else if (check == 2)
        {
        bullet->setPos(x()+(rect().width()/2)-(bullet->rect().width()/2),y()+(rect().height()+1));
        scene()->addItem(bullet);
        }
        else if (check == 3)
        {
        bullet->setPos(x()-bullet->rect().width()-1,y()+rect().height()/2-bullet->rect().height()/2);
        scene()->addItem(bullet);
        }
        else if (check == 4)
        {
        bullet->setPos(x()+rect().width()+1,y()+rect().height()/2-bullet->rect().height()/2);
        scene()->addItem(bullet);
        }
        if(bulletSound->playbackState()==QMediaPlayer::PlayingState){
            bulletSound -> setPosition(0);
        }else if(bulletSound->playbackState()==QMediaPlayer::StoppedState){
            bulletSound->play();
        }
    }
}

void Testing::spawn()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
