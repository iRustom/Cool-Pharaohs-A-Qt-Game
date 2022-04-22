#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Testing : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Testing(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();// should be moved to game class
private:
    QMediaPlayer * bulletSound;
    QAudioOutput * bulletoutput;

};

#endif // PLAYER_H
