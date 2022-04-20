#include "player.h"
#include <stdlib.h>
player::player()
{

    QPixmap p("arabRight.png");
    p=p.scaledToWidth(50);
    p=p.scaledToHeight(50);
    setPixmap(p);

    row = 1;
    column= 1;

    setPos(50+50*column,50+50*row);
}
void player::keyPressEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_Up)
    {
        row--;
    }
    else if(event->key()==Qt::Key_Down)
    {
        row++;
    }
    else if(event->key()==Qt::Key_Left)
    {
        column--;
    }
    else if(event->key()==Qt::Key_Right)
    {
        column++;
    }
    setPos(50+50*column,50+50*row);
}
