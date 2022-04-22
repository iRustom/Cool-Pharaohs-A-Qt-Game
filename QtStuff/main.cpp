#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <player.h>
#include <QDebug>
#include <testing.h>
#include <QTimer>
#include "game.h"

// all this stuff should be moved into a game class...
Game * game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->start();

    return a.exec();
}
//hello world num 2
