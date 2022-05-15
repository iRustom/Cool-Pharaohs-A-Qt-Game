/* #include "boss.h"
#include "game.h"
#include <QTimer>
#include <QPair>
#include <cmath>
#include <vector>
using namespace std;

struct cell {

    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

extern Game* game;
Boss::Boss(QGraphicsItem * parent):QObject(), QGraphicsPixmapItem(parent)
{
    active = false;
    bossBulletSound = new QMediaPlayer();
    bossBulletoutput = new QAudioOutput();

    bossBulletSound->setAudioOutput(bossBulletoutput);
    bossBulletSound->setSource(QUrl("qrc:/sfx/bulletsound.mp3"));

    if(game->volume == 1){
        bossBulletoutput->setVolume(100);
    }else{
        bossBulletoutput->setVolume(0);
    }

    setPixmap(QPixmap(":/images/enemy1.png").scaled(60,60));

    setTransformOriginPoint(pixmap().width()/2,pixmap().height()/2);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(rand()%2000+1000);

    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(checkActive()));
    timer2->start(100);

    oldVal = 6;

}

bool Boss::isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < 20) && (col >= 0)
           && (col < 20);
}

void Boss::move()
{
    if(active){
        //make matrix
        //shortest path using function that take player pos and boss pos
    }
}
bool Boss::isUnBlocked(int grid[][20], int row, int col){
    if(grid[row][col]!=1){
        return true;
    }else{
        return false;
    }
}
bool Boss::isDestination(int row, int col, QPair<int,int> dest){
    if (row==dest.first && col==dest.second){
        return true;
    }else{
        return false;
    }
}
double Boss::calculateHValue(int row, int col, QPair<int,int> dest){
    return ((double)sqrt(
                (row-dest.first)*(row-dest.first) + (col-dest.second)*(col-dest.second)));
}
void Boss::tracePath(cell cellDetails[][20], QPair<int,int> dest){
    int row = dest.first;
    int col = dest.second;
    stack<QPair<int,int>> Path;
    while (!(cellDetails[row][col].parent_i == row
                 && cellDetails[row][col].parent_j == col)) {
            Path.push(std::make_pair(row, col));
            int temp_row = cellDetails[row][col].parent_i;
            int temp_col = cellDetails[row][col].parent_j;
            row = temp_row;
            col = temp_col;
        }
    Path.push(std::make_pair(row, col));
        Pathfinal=Path;
        qDebug()<<Pathfinal.size()<<"before";
        while (!Path.empty()) {
            std::pair<int, int> p = Path.top();
            Path.pop();
            qDebug()<<"("<<p.first<< p.second<<")";
        }
       // qDebug()<<"here";
        return;

}
void Boss::aStar(int grid[][20],QPair<int,int> src, QPair<int,int> dest){
    if (isUnBlocked(grid, src.first, src.second) == false
            || isUnBlocked(grid, dest.first, dest.second)
                   == false) {
            qDebug()<<"Source or the destination is blocked\n";
            return;
        }
    if (isDestination(src.first, src.second, dest)
            == true) {
            qDebug()<<"We are already at the destination\n";
            return;
        }
    bool closedList[20][20];
    memset(closedList, false, sizeof(closedList));
    cell cellDetails[20][20];
    int i, j;

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
    // Initialising the parameters of the starting node
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    // Initialising the parameters of the starting node
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    set<pPair> openList;
    openList.insert(make_pair(0.0, std::make_pair(i, j)));

    bool foundDest = false;

    while (!openList.empty()) {
           pPair p = *openList.begin();

           // Remove this vertex from the open list
           openList.erase(openList.begin());

           // Add this vertex to the closed list
           i = p.second.first;
           j = p.second.second;
           closedList[i][j] = true;

            double gNew, hNew, fNew;

            if (isValid(i - 1, j) == true) {
                        // If the destination cell is the same as the
                        // current successor
                        if (isDestination(i - 1, j, dest) == true) {
                            // Set the Parent of the destination cell
                            cellDetails[i - 1][j].parent_i = i;
                            cellDetails[i - 1][j].parent_j = j;
                            printf("The destination cell is found\n");
                            tracePath(cellDetails, dest);
                            foundDest = true;
                            return;
                        }
}
/*void Boss::checkActive()
{
    if(game->player->pos().x()<600&&game->player->pos().y()<600){
        if(pos().x()<600 && pos().y()<600)
            active = true;
    }else if(game->player->pos().x()>600&&game->player->pos().y()<600){
        if(pos().x()>600 && pos().y()<600)
            active = true;
    }else if(game->player->pos().x()>600&&game->player->pos().y()>600){
        if(pos().x()>600 && pos().y()>600)
            active = true;
    }else if(game->player->pos().x()<600&&game->player->pos().y()>600){
        if(pos().x()<600 && pos().y()>600)
            active = true;
    }
}*/
