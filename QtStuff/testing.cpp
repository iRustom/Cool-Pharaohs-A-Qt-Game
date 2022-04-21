#include "testing.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
Testing::Testing(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletoutput = new QAudioOutput();

    bulletSound-> setAudioOutput(bulletoutput);
    bulletSound->setSource(QUrl("qrc:/sfx/bulletsound.mp3"));
    bulletoutput->setVolume(100);

    setPixmap(QPixmap(":/images/mainCharacterUp.png").scaled(100,100));
    setTransformOriginPoint(pixmap().width()/2,pixmap().height()/2);

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
        if(pos().y()+pixmap().height()<600)
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
        if(pos().x()+pixmap().width()<600)
        setPos(x()+10,y());
        check = 4;
    }else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet(check);
        if (check == 1)
        {
        bullet->setPos(x()+(pixmap().width()/2)-(bullet->pixmap().width()/2),y()-(bullet->pixmap().height()+1));
        scene()->addItem(bullet);
        }
        else if (check == 2)
        {
        bullet->setPos(x()+(pixmap().width()/2)-(bullet->pixmap().width()/2),y()+(pixmap().height()+1));
        scene()->addItem(bullet);
        }
        else if (check == 3)
        {
        bullet->setPos(x()-bullet->pixmap().width()-1,y()+pixmap().height()/2-bullet->pixmap().height()/2);
        scene()->addItem(bullet);
        }
        else if (check == 4)
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

void Testing::spawn()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
