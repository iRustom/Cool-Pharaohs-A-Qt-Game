#ifndef TESTING_H
#define TESTING_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Testing : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Testing();
    void keyPressEvent(QKeyEvent* event);
    int check;
public slots:
    void spawn();// should be moved to game class
private:
    QMediaPlayer * bulletSound;
    QAudioOutput * bulletoutput;

};

#endif // TESTING_H
