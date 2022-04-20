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
#include <QDebug>
#include <testing.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating scene and item
    QGraphicsScene* scene= new QGraphicsScene();
    qDebug() << "test 1";
    Testing *p= new Testing();
    p->setRect(0,0,100,100);
    scene->addItem(p);
    p->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    p->setFocus();

    //creating view
    QGraphicsView *view= new QGraphicsView(scene);
    //view->setFixedSize(600,600);
    view->setWindowTitle("Guy Fights Cool Pharaohs");
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(600,600);
    scene->setSceneRect(0,0,600,600);

    p->setPos(view->height()/2,view->height()-p->rect().height());

    return a.exec();
}
//hello world num 2
