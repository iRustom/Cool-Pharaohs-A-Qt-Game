#include "game.h"
#include <QTimer>
#include "enemy.h"

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,600);

    setScene(scene);
    setWindowTitle("Guy Fights Cool Pharaohs");
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,600);


    player = new Testing();
    player->setRect(0,0,100,100);
    scene->addItem(player);
    player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2-player->rect().width()/2,height()-player->rect().height());

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn())); // switch from p to game later
    timer->start(2000);

}
