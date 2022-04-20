#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class player : public QObject, public QGraphicsPixmapItem
{
public:
    player();
private:
    int row;
    int column;
public slots:
    void keyPressEvent(QKeyEvent* event);

signals:

};

#endif // PLAYER_H
