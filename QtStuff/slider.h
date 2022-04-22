#ifndef SLIDER_H
#define SLIDER_H
#include <QSlider>
#include <QGraphicsItem>

class Slider: public QSlider, public QGraphicsItem
{
public:
    Slider();
    virtual QRectF boundingRect() const{return QRectF();};
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr){};

};

#endif // SLIDER_H
