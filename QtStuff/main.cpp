#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    view.setFixedSize(600,600);
    view.setWindowTitle("Cool Pharaoh Fights Bad Guys");
    return a.exec();
}
