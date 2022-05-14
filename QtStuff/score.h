#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent = 0);
    void increase();
    int getScore();
    void increaseCoins();
    int getCoins();
private:
    int score;
    int coins;
};

#endif // SCORE_H
