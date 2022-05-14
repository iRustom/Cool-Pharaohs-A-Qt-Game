/*#ifndef BOSS_H
#define BOSS_H
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <bits/stdc++.h>
#include <QKeyEvent>



class Boss:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    struct cell {
        // Row and Column index of its parent
        // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
        int parent_i, parent_j;
        // f = g + h
        double f, g, h;
    };
    typedef QPair<double, QPair<int, int> > pPair;

public:
    Boss(QGraphicsItem * parent = 0);
    bool active;
    int oldVal;
    int aMatrix[20][20];
    bool isUnBlocked(int grid[][20], int row, int col);
    bool isDestination(int row, int col, QPair<int, int> dest);
    double calculateHValue(int row, int col, QPair<int, int> dest);
    void tracePath(cell cellDetails[][20], QPair<int, int> dest);
    std::stack<QPair<int,int>> Pathfinal;

    void aStar(int grid[][20], QPair<int, int> src, QPair<int, int> dest);
    bool isValid(int row, int col);
private:
    QMediaPlayer * bossBulletSound;
    QAudioOutput * bossBulletoutput;

public slots:
    void move();
    void checkActive();
};

#endif // BOSS_H
*/
