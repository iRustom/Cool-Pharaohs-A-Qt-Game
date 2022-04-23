#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(int type,QGraphicsItem * parent = 0);
    int Type;
public slots:
    void move();
private:
    QMediaPlayer * enemyBulletSound;
    QAudioOutput * enemyBulletoutput;

};

#endif // ENEMY_H
