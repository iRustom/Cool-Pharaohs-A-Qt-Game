#ifndef PLSBOSS_H
#define PLSBOSS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <player.h>
#include <bits/stdc++.h>
#include <QTimer>
#define ROW 10
#define COL 10

// Creating a shortcut for int, int pair type
typedef std::pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef std::pair<double, std::pair<int, int> > pPair;

// A structure to hold the necessary parameters
struct cell {
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

class plsBoss: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
int row;
int column;
Player *ptr;
public:
    plsBoss(int [][20], Player *);
    bool isValid(int row, int col);
    bool isUnBlocked(int grid[][COL], int row, int col);
    bool isDestination(int row, int col, Pair dest);
    double calculateHValue(int row, int col, Pair dest);
    void tracePath(cell cellDetails[][COL], Pair dest);
    void aStarSearch(int grid[][COL], Pair src, Pair dest);
    QMediaPlayer * bossBulletSound;
    QAudioOutput * bossBulletoutput;
    std::stack<Pair> Pathfinal;
    int data[10][10];

    bool active;
public slots:
    void move();

    void checkActive();
};
#endif // PLAYER_H
