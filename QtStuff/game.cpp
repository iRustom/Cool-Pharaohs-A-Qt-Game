#include "game.h"
#include <QTimer>
#include "enemy.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QImage>
#include <QGraphicsTextItem>
#include "button.h"

Game::Game(QWidget *parent): QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,600);
    setWindowTitle("Guy Fights Cool Pharaohs");

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,600,600);
    setScene(scene);

    show();

}

void Game::start()
{
    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/images/sand.jpg").scaled(600,600)));

    player = new Testing();
    player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2-player->pixmap().width()/2,height()-player->pixmap().height());

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    scene->addItem(health);
    health-> setPos(health->x(),health->y()+25);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn())); // switch from p to game later
    timer->start(2000);

    QMediaPlayer * music= new QMediaPlayer();
    QAudioOutput * output = new QAudioOutput();

    music-> setAudioOutput(output);
    music->setSource(QUrl("qrc:/sfx/EgyptBg.mp3"));
    output->setVolume(50);
    music->setLoops(QMediaPlayer::Infinite);
    music->play();

}

void Game::mainMenu()
{
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

}
