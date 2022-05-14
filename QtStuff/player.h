#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent* event);
    int oldVal;
public slots:
    void spawn();// should be moved to game class
private:
    QMediaPlayer * bulletSound;
    QAudioOutput * bulletoutput;
    bool stopUp = false; bool stopDown = false;bool stopRight = false;bool stopLeft = false;

};

#endif // PLAYER_H
