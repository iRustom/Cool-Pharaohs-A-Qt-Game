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
#include <player.h>
#include <QTimer>
#include "game.h"
#include "door.h"

// MADE BY: OMAR ELFOULY; AHMED ALI; NOUR KASABY
Game * game;
int Door::count = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->mainMenu();

    return a.exec();
}
//hello world num 2
