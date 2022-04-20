#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <player.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating view
    QGraphicsView view;
    view.setFixedSize(600,600);
    view.setWindowTitle("Guy Fights Cool Pharaohs");
    QBrush brush(Qt::blue);
    view.setBackgroundBrush(brush);

    //creating scene and item
    QGraphicsScene* scene= new QGraphicsScene();
    player p;
    scene->addItem(&p);
    p.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    p.setFocus();
    view.setScene(scene);
    view.show();
    QApplication::closeAllWindows();


    //object of class game created
    return a.exec();
}
//hello world num 2
