#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //creating view
    QGraphicsView view;
    view.setFixedSize(600,600);
    view.setWindowTitle("Guy Fights Cool Pharaohs");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);

    //creating scene and item
    QGraphicsScene* scene= new QGraphicsScene();
    QPixmap p("arabRight.png");
    p=p.scaledToWidth(50);
    p=p.scaledToHeight(50);
    QGraphicsPixmapItem player(p);

    //object of class game created
    return a.exec();
}
//hello world num 2
