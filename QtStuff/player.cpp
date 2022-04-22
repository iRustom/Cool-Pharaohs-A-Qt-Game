#include "player.h"
#include <QDebug>
player::player()
{

    QPixmap p(":/images/arabRight.png");
    //p=p.scaledToWidth(50);
    //p=p.scaledToHeight(50);
    setPixmap(p);

    row = 1;
    column= 1;

    setPos(50+50*column,50+50*row);
}
void player::keyPressEvent(QKeyEvent* event)
{
    qDebug() << "Key was pressed";
}
