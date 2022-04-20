#ifndef TESTING_H
#define TESTING_H

#include <QGraphicsRectItem>
class Testing : public QGraphicsRectItem
{
public:
    Testing();
    void keyPressEvent(QKeyEvent* event);
};

#endif // TESTING_H
