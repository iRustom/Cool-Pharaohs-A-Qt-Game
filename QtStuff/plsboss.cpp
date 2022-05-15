#include "plsboss.h"
#include "enemybullet.h"
#include "game.h"
#include <cmath>
#include <QDebug>
#include <vector>

extern Game * game;

bool plsBoss::isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL);
}
bool plsBoss::isUnBlocked(int grid[][COL], int row, int col)
{
    // Returns true if the cell is not blocked else false
    if (grid[row][col] != 1)
      {
      //  qDebug()<<grid[row][col];
        return (true);
      }
    else
    {
        //qDebug()<<grid[row][col];
        return (false);
    }
}
bool plsBoss::isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}
double plsBoss::calculateHValue(int row, int col, Pair dest)
{
    // Return using the distance formula
    return ((double)sqrt((row - dest.first) * (row - dest.first)+ (col - dest.second) * (col - dest.second)));
}
void plsBoss::tracePath(cell cellDetails[][COL], Pair dest)
{
    // qDebug()<<"here";
    int row = dest.first;
    int col = dest.second;

    std::stack<Pair> Path;
    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
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
void plsBoss::aStarSearch(int grid[][COL], Pair src, Pair dest)
{
    qDebug()<<"here1";
    // If the source is out of range
    if (isValid(src.first, src.second) == false) {
        qDebug()<<"Source is invalid\n";
        return;
    }

    // If the destination is out of range
    if (isValid(dest.first, dest.second) == false) {
        qDebug()<<"Destination is invalid\n";
        return;
    }

    // Either the source or the destination is blocked
    if (isUnBlocked(grid, src.first, src.second) == false|| isUnBlocked(grid, dest.first, dest.second)
               == false) {
        qDebug()<<"Source or the destination is blocked\n";
        return;
    }

    // If the destination cell is the same as source cell
    if (isDestination(src.first, src.second, dest)
        == true) {
        qDebug()<<"We are already at the destination\n";
        return;
    }

    // Create a closed list and initialise it to false which
    // means that no cell has been included yet This closed
    // list is implemented as a boolean 2D array
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    // Declare a 2D array of structure to hold the details
    // of that cell
    cell cellDetails[ROW][COL];

    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
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
    qDebug()<<"here5";
    /*
     Create an open list having information as-
     <f, <i, j>>
     where f = g + h,
     and i, j are the row and column index of that cell
     Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
     This open list is implemented as a set of pair of
     pair.*/
    std::set<pPair> openList;

    // Put the starting cell on the open list and set its
    // 'f' as 0
    openList.insert(make_pair(0.0, std::make_pair(i, j)));

    // We set this boolean value as false as initially
    // the destination is not reached.
    bool foundDest = false;

    while (!openList.empty()) {
        pPair p = *openList.begin();

        // Remove this vertex from the open list
        openList.erase(openList.begin());

        // Add this vertex to the closed list
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        /*
         Generating all the 8 successor of this cell

                   N   N.E
               \   |   /
                   |  /
             W----Cell----E
                  / | \
                /   |  \
             S.W    S   S.E

         Cell-->Popped Cell (i, j)
         N -->  North       (i-1, j)
         S -->  South       (i+1, j)
         E -->  East        (i, j+1)
         W -->  West           (i, j-1)*/

        // To store the 'g', 'h' and 'f' of the 8 successors
        double gNew, hNew, fNew;

        //----------- 1st Successor (North) ------------

        // Only process this cell if this is a valid one
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
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i - 1][j] == false
                     && isUnBlocked(grid, i - 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i - 1][j].f == FLT_MAX
                    || cellDetails[i - 1][j].f > fNew) {
                    openList.insert(make_pair(
                        fNew, std::make_pair(i - 1, j)));

                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }

        //----------- 2nd Successor (South) ------------

        // Only process this cell if this is a valid one
        if (isValid(i + 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i + 1, j, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i + 1][j] == false
                     && isUnBlocked(grid, i + 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i + 1][j].f == FLT_MAX
                    || cellDetails[i + 1][j].f > fNew) {
                    openList.insert(make_pair(fNew, std::make_pair(i + 1, j)));
                    // Update the details of this cell
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }

        //----------- 3rd Successor (East) ------------

        // Only process this cell if this is a valid one
        if (isValid(i, j + 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j + 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }

            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j + 1] == false
                     && isUnBlocked(grid, i, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i][j + 1].f == FLT_MAX
                    || cellDetails[i][j + 1].f > fNew) {
                    openList.insert(make_pair(fNew, std::make_pair(i, j + 1)));

                    // Update the details of this cell
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }

        //----------- 4th Successor (West) ------------

        // Only process this cell if this is a valid one
        if (isValid(i, j - 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j - 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }

            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j - 1] == false
                     && isUnBlocked(grid, i, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i][j - 1].f == FLT_MAX
                    || cellDetails[i][j - 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, std::make_pair(i, j - 1)));

                    // Update the details of this cell
                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }

      }
    // When the destination cell is not found and the open
    // list is empty, then we conclude that we failed to
    // reach the destination cell. This may happen when the
    // there is no way to destination cell (due to
    // blockages)
    if (foundDest == false)
        qDebug()<<"Failed to find the Destination Cell\n";

   // qDebug()<<"end 0";

    return;
}
plsBoss::plsBoss(int boarddata[][20], Player *ptr)
{

    active = false;
    bossBulletSound = new QMediaPlayer();
    bossBulletoutput = new QAudioOutput();


    health = new bossHealth();
    //health-> setPos(health->x(),health->y()+25);
    //scene->addItem(health);
    health->setParentItem(this);

    bossBulletSound->setAudioOutput(bossBulletoutput);
    bossBulletSound->setSource(QUrl("qrc:/sfx/bulletsound.mp3"));

    if(game->volume == 1){
        bossBulletoutput->setVolume(100);
    }else{
        bossBulletoutput->setVolume(0);
    }
    row=5;
    column=1;
    this->ptr=ptr;

    setPixmap(QPixmap(":/images/boss.png").scaled(60,60));
    setPos(column*60,600+row*60);

    setZValue(99);
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
        {
         data[i][j]=boarddata[i+10][j];
        };
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(500);

    QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(checkActive()));
    timer2->start(100);

    //qDebug()<<Pathfinal.size() << "after";
    //qDebug()<<Pathfinal.top()<<"top";

    game->scene->addItem(this);


}
void  plsBoss:: move()
{
    if(active){
        qDebug()<<"Source is "<<(pos().y()-600)/60<<" "<<pos().x()/60;
        Pair src = std::make_pair((pos().y()-600)/60, pos().x()/60);
        qDebug()<<"Destination is "<<(ptr->pos().y()-600)/60<<" "<<(ptr->pos().x())/60;
        Pair dest = std::make_pair((ptr->pos().y()-600)/60, ptr->pos().x()/60);
        for (int i=0;i<10;i++)
            for (int j=0;j<10;j++)
            {
            data[i][j]=game->map->objectCords[i+10][j];
            };
        for (int i=0;i<10;i++)
                for (int j=0;j<10;j++)
                {
                    qDebug() << "Data: " << data[i][j] << Qt::endl;
                }
        aStarSearch(data, src, dest);

        //Pair temp=Pathfinal.top();

        if(Pathfinal.empty()==false)
        {
        Pathfinal.pop();
        if(!Pathfinal.empty()){
        Pair temp=Pathfinal.top();

        int ro=temp.first;
        int co=temp.second;
        qDebug()<<"still moving";
        qDebug()<<"((" <<ro<<","<<co<<"))";
        if(co*60 > pos().x() )
            setRotation(90);
        else if(co*60 < pos().x())
            setRotation(270);
        else if(600+ro*60 < pos().y())
            setRotation(0);
        else if(600+ro*60 > pos().y())
            setRotation(180);
        setPos(co*60,600+ro*60);
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i =0;i<colliding_items.size();i++)
                {
                    if(typeid(*(colliding_items[i]))==typeid(Player))
                    {
                        game->score->increase();
                        game->health->decrease();
                        health->decrease();

                        return;
                    }
                }
        EnemyBullet * enemyBullet = new EnemyBullet(int(int(rotation()+180)%360),1 );
        if (rotation() == 180)
        {

            enemyBullet->setPos(x()+(pixmap().width()/2)-(enemyBullet->pixmap().width()/2)-50,y()+(enemyBullet->pixmap().height()+11));

            game->scene->addItem(enemyBullet);
        }
        else if (rotation() == 0)
        {
            enemyBullet->setPos(x()+(pixmap().width()/2)-(enemyBullet->pixmap().width()/2),y()-(pixmap().height()+11));

            game->scene->addItem(enemyBullet);//THIS IS THE PROBLEM

        }
        else if (rotation() == 90)
        {

            enemyBullet->setPos(x()-enemyBullet->pixmap().width()+11,y()+pixmap().height()/2-enemyBullet->pixmap().height()/2);

            game->scene->addItem(enemyBullet);
        }
        else if (rotation() == 270)
        {

            enemyBullet->setPos(x()+pixmap().width()/2,y()+pixmap().height()/2-enemyBullet->pixmap().height()/2-50);

            game->scene->addItem(enemyBullet);
        }
        if(bossBulletSound->playbackState()==QMediaPlayer::PlayingState){
            bossBulletSound -> setPosition(0);
        }else if(bossBulletSound->playbackState()==QMediaPlayer::StoppedState){
            bossBulletSound->play();
        }
        }

        }
    }
}
void plsBoss::checkActive()
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
}
