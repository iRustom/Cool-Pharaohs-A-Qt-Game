#include "game.h"
#include <QTimer>
#include "enemy.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QImage>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QWidget>
#include "button.h"
#include <QDebug>

Game::Game(QWidget *parent): QGraphicsView(parent)
{
    lost= false;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,600);
    setWindowTitle("Guy Fights Cool Pharaohs");

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,600,600);
    setScene(scene);

    volume =1;

    show();


}

void Game::start()
{
    scene->clear();
    setFixedSize(600,600);
    scene->setSceneRect(0,0,1200,1200);

    qDebug()<< "i work";
    map = new Map();
    map->readMap(":/maps/map.txt");
    map->drawMap();

    setBackgroundBrush(QBrush(QImage(":/images/sand.jpg").scaled(600,600)));

    player = new Player();
    player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(61,479);

    for(int i=0;i<map->enemyVec.size();i++)
    {
        if(map->enemyVec[i]->pos().x()<600 && map->enemyVec[i]->pos().y()<600)
            map->enemyVec[i]->active=true;
     }

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    //health-> setPos(health->x(),health->y()+25);
    //scene->addItem(health);
    health->setParentItem(player);

    /*QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn())); // switch from p to game later
    timer->start(2000);*/

    QMediaPlayer * music= new QMediaPlayer();
    QAudioOutput * output = new QAudioOutput();

    music-> setAudioOutput(output);
    music->setSource(QUrl("qrc:/sfx/EgyptBg.mp3"));
    if(volume==1){
        output->setVolume(50);
    }else{
        output->setVolume(0);
    }
    music->setLoops(QMediaPlayer::Infinite);
    music->play();

}

void Game::toggleVol()
{
    volume *=-1;
}

void Game::display_login()
{
    hide();
    log = new class log_in(this);
    log->show();
}


void Game::mainMenu()
{
 scene->clear();
    //can be reimplemented using widgets
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Guy kills cool pharaohs"));
    QFont titleFont("comic sans",25);
    title->setFont(titleFont);
    title->setPos(this->width()/2-title->boundingRect().width()/2,100);
    scene->addItem(title);

    Button * play = new Button(QString("Play"));
    play->setPos(this->width()/2-play->boundingRect().width()/2,200);
    connect(play, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(play);

    Button * quit = new Button(QString("Quit"));
    quit->setPos(this->width()/2-quit->boundingRect().width()/2,300);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);

    Button * togVol = new Button(QString("Toggle Volume"));
    togVol->setPos(this->width()/2-togVol->boundingRect().width()/2,400);
    connect(togVol,SIGNAL(clicked()),this,SLOT(toggleVol()));
    scene->addItem(togVol);

    Button * login = new Button(QString("Log in"));
    login->setPos(this->width()/2-login->boundingRect().width()/2,500);
    connect(login,SIGNAL(clicked()),this,SLOT(display_login()));
    scene->addItem(login);

}

void Game::mainMenu2()
{
    lost= false;
    scene->clear();
    //can be reimplemented using widgets
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Guy kills cool pharaohs"));
    QFont titleFont("comic sans",25);
    title->setFont(titleFont);
    title->setPos(this->width()/2-title->boundingRect().width()/2,100);
    scene->addItem(title);

    Button * play = new Button(QString("Play"));
    play->setPos(this->width()/2-play->boundingRect().width()/2,200);
    connect(play, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(play);

    Button * quit = new Button(QString("Quit"));
    quit->setPos(this->width()/2-quit->boundingRect().width()/2,300);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);

    Button * togVol = new Button(QString("Toggle Volume"));
    togVol->setPos(this->width()/2-togVol->boundingRect().width()/2,400);
    connect(togVol,SIGNAL(clicked()),this,SLOT(toggleVol()));
    scene->addItem(togVol);

    QGraphicsTextItem* status = new QGraphicsTextItem(QString("Logged in!"));
    status->setPos(this->width()/2-status->boundingRect().width()/2,500);
    scene->addItem(status);
}
void Game::lose()
{
    lost= true;
    setSceneRect(0,0,600,600);
    //scene->clear();
    player->clearFocus();
    delete scene;
    scene = new QGraphicsScene(this);
    setScene(scene);

    setSceneRect(0,0,600,600);
    QGraphicsTextItem* done = new QGraphicsTextItem(QString("GAME OVER"));
    QFont doneFont("comic sans",25);
    done->setFont(doneFont);

    done->setPos(this->width()/2-done->boundingRect().width()/2,100);
    scene->addItem(done);

    Button * quit = new Button(QString("Quit"));
    quit->setPos(this->width()/2-quit->boundingRect().width()/2,400);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);

    Button * restart = new Button(QString("Play Again"));
    restart->setPos(this->width()/2-restart->boundingRect().width()/2,300);
    connect(restart, SIGNAL(clicked()),this,SLOT(mainMenu2()));
    scene->addItem(restart);

}

void Game::win()
{

    lost= true;
    player->clearFocus();
    delete scene;
    scene = new QGraphicsScene(this);
    setScene(scene);

    setSceneRect(0,0,600,600);
    QGraphicsTextItem* user_win = new QGraphicsTextItem(QString("You win (p.s.boss wasnt home)"));
    QFont user_winFont("comic sans",25);
    user_win->setFont(user_winFont);
    user_win->setPos(this->width()/2-user_win->boundingRect().width()/2,100);
    scene->addItem(user_win);

    Button * quit = new Button(QString("Quit"));
    quit->setPos(this->width()/2-quit->boundingRect().width()/2,400);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quit);

    Button * restart = new Button(QString("Play Again"));
    restart->setPos(this->width()/2-restart->boundingRect().width()/2,300);
    connect(restart, SIGNAL(clicked()),this,SLOT(mainMenu2()));
    scene->addItem(restart);

}
