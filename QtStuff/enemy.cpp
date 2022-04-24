#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"
#include "enemybullet.h"

extern Game* game;

Enemy::Enemy(int type, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem() //this should probably be changed to a new abstract class that all of our objects inherit from
{
    qDebug()<<"Enemy is being created";
    active = false;
    //setPos(rand()%600,0);    
    enemyBulletSound = new QMediaPlayer();
    enemyBulletoutput = new QAudioOutput();

    enemyBulletSound->setAudioOutput(enemyBulletoutput);
    enemyBulletSound->setSource(QUrl("qrc:/sfx/bulletsound.mp3"));

    if(game!=nullptr){
        qDebug()<<"Fuck ur life";
    }

    qDebug()<<"Volume is " << QString::number(game->volume);

    if(game->volume == 1){
        enemyBulletoutput->setVolume(100);
    }else{
        enemyBulletoutput->setVolume(0);
    }

    Type = type;

    if(Type == 0)
        setPixmap(QPixmap(":/images/enemy1.png").scaled(60,60));

    if(Type == 1)
        setPixmap(QPixmap(":/images/enemy2.png").scaled(60,60));

    setTransformOriginPoint(pixmap().width()/2,pixmap().height()/2);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(rand()%2000+1000);

    qDebug()<<"Enemy is created";
}
//qDebug() << "Type is: " << QString::number(Type) << "moving to " << QString::number(notOcc[rando].x()) << QString::number(notOcc[rando].y());

void Enemy::move()
{
    if(active){
        qDebug()<<"enemy is active";
        QVector<QPoint> notOcc;
        int currentX = pos().x();
        int currentY = pos().y();
        bool moveCheck = false;     //was testing, just in case

        notOcc.push_back(QPoint(currentX, currentY));
        if(game->map->objectCords[currentY/60 - 1][currentX/60] == 0) //up
        {
        notOcc.push_back(QPoint(currentX, currentY - 60));
        moveCheck = true;
        }
        if(Type == 1 && game->map->objectCords[currentY/60 - 1][currentX/60] == 2) //up
        {
        notOcc.push_back(QPoint(currentX, currentY - 60));
        moveCheck = true;
        }


        if(game->map->objectCords[currentY/60][currentX/60 + 1] == 0) //right
        {
        notOcc.push_back(QPoint(currentX + 60, currentY));
        moveCheck = true;
        }
        if(Type == 1 && game->map->objectCords[currentY/60][currentX/60 + 1] == 2) //right
        {
        notOcc.push_back(QPoint(currentX + 60, currentY));
        moveCheck = true;
        }


        if(game->map->objectCords[currentY/60 + 1][currentX/60] == 0) //down
        {
        notOcc.push_back(QPoint(currentX, currentY + 60));
        moveCheck = true;
        }
        if(Type == 1 && game->map->objectCords[currentY/60 + 1][currentX/60] == 2) //down
        {
        notOcc.push_back(QPoint(currentX, currentY + 60));
        moveCheck = true;
        }

        if(game->map->objectCords[currentY/60][currentX/60 - 1] == 0)  //left
        {
        notOcc.push_back(QPoint(currentX - 60, currentY));
        moveCheck = true;
        }
        if(Type == 1 && game->map->objectCords[currentY/60][currentX/60 - 1] == 2)  //left
        {
        notOcc.push_back(QPoint(currentX - 60, currentY));
        moveCheck = true;
        }

        if (moveCheck == true)
        {
        int rando;
        rando = rand()%notOcc.size();
        if(notOcc[rando].x() > currentX )
            setRotation(270);
        else if(notOcc[rando].x() < currentX)
            setRotation(90);
        else if(notOcc[rando].y() < currentY)
            setRotation(180);
        else if(notOcc[rando].y() > currentY)
            setRotation(0);

        if(Type == 1)
        qDebug() << "Type is: " << QString::number(Type) << "moving to " << QString::number(notOcc[rando].x()) << QString::number(notOcc[rando].y());

        setPos(notOcc[rando]);

        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i =0;i<colliding_items.size();i++)
        {
            if(typeid(*(colliding_items[i]))==typeid(Player))
            {
            game->score->increase();
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
            }
        }

        qDebug()<<QString::number(rotation());
        EnemyBullet * enemyBullet = new EnemyBullet(rotation(), Type);
        if (rotation() == 0)
        {
            qDebug()<<"setting bullet 0";

        enemyBullet->setPos(x()+(pixmap().width()/2)-(enemyBullet->pixmap().width()/2),y()+(enemyBullet->pixmap().height()+11));
        qDebug()<<" bullet set adding to scene";

        game->scene->addItem(enemyBullet);
        }
        else if (rotation() == 180)
        {
            qDebug()<<"setting bullet 180";
        enemyBullet->setPos(x()+(pixmap().width()/2)-(enemyBullet->pixmap().width()/2),y()-(pixmap().height()+11));
        qDebug()<<" bullet set adding to scene";

        game->scene->addItem(enemyBullet);//THIS IS THE PROBLEM
        qDebug()<<" bullet added to scene";

        }
        else if (rotation() == 270)
        {
            qDebug()<<"setting bullet 270";

        enemyBullet->setPos(x()-enemyBullet->pixmap().width()+11,y()+pixmap().height()/2-enemyBullet->pixmap().height()/2);
        qDebug()<<" bullet set adding to scene";

        game->scene->addItem(enemyBullet);
        }
        else if (rotation() == 90)
        {
            qDebug()<<"setting bullet 90";

        enemyBullet->setPos(x()+pixmap().width()-11,y()+pixmap().height()/2-enemyBullet->pixmap().height()/2);
        qDebug()<<" bullet set adding to scene";

        game->scene->addItem(enemyBullet);
        }
        if(enemyBulletSound->playbackState()==QMediaPlayer::PlayingState){
            enemyBulletSound -> setPosition(0);
        }else if(enemyBulletSound->playbackState()==QMediaPlayer::StoppedState){
            enemyBulletSound->play();
        }

    //change objectCord so that new pos of enemy is recorded (not 0).

        //setPos(x(),y()+5);
        //if(pos().y()+pixmap().height()<600){

        //}
        }
    }
}
