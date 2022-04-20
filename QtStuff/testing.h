#ifndef TESTING_H
#define TESTING_H
#include <QObject>
#include <QGraphicsRectItem>
class Testing : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Testing();
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn(); // should be moved to game class

};

#endif // TESTING_H
