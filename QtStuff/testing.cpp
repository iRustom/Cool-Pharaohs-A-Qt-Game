#include "testing.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
Testing::Testing()
{

}

void Testing::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        if(pos().y()>0)
        setPos(x(),y()-10);
    }
    else if(event->key()==Qt::Key_Down)
    {
        if(pos().y()+rect().height()<600)
        setPos(x(),y()+10);
    }
    else if(event->key()==Qt::Key_Left)
    {
        if(pos().x()>0)
        setPos(x()-10,y());
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x()+rect().width()<600)
        setPos(x()+10,y());
    }else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void Testing::spawn()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
