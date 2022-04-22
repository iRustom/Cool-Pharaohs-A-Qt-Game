#include "button.h"
#include <QBrush>
#include <QGraphicsTextItem>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent), QWidget()
{
    setRect(0,0,200,50);
    QBrush brush; brush.setStyle(Qt::SolidPattern); brush.setColor(Qt::darkCyan);
    setBrush(brush);
    text = new QGraphicsTextItem(name,this);
    text->setPos(QGraphicsRectItem::rect().width()/2- text->boundingRect().width()/2, QGraphicsRectItem::rect().height()/2- text->boundingRect().height()/2);
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
     QBrush brush;brush.setStyle(Qt::SolidPattern); brush.setColor(Qt::cyan);
     setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;brush.setStyle(Qt::SolidPattern); brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
