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
#include "score.h"
#include "health.h"

extern Health* health;
extern Score*score;

Game::Game(QWidget *parent): QGraphicsView(parent)
{
    xOff = 0;
    yOff = 0;
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

    map = new Map();
    map->readMap(":/maps/map.txt");
    map->drawMap();

    setBackgroundBrush(QBrush(QImage(":/images/sand.jpg").scaled(600,600)));

    player = new Player();
    player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(60,480);

    boss = new plsBoss(map->objectCords,player);

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

void Game::display_coins()
{
    QGraphicsTextItem* coin_amount = new QGraphicsTextItem(QString("Coins: " + QString::number(score->getCoins())));
    coin_amount->setZValue(1000);
    QFont coinFont("comic sans",18);
    coin_amount->setFont(coinFont);
    coin_amount->setPos(this->width()/2-coin_amount->boundingRect().width()/2,200);
    scene->addItem(coin_amount);
}

void Game::toggleVol()
{
    volume *=-1;
}

void Game::draw(int x, int y, int width, int height, QColor colour, double opacity)
{
panel = new QGraphicsRectItem(x,y,width,height);
panel->setZValue(999);
QBrush brush;
brush.setStyle(Qt::SolidPattern);
brush.setColor(colour);
panel->setBrush(brush);
panel->setOpacity(opacity);
scene->addItem(panel);
}

void Game::resume()
{
   scene->removeItem(panel);
   scene->removeItem(shop_title);
   scene->removeItem(coin_amount);
   scene->removeItem(health_amount);
   scene->removeItem(buy_health);
   scene->removeItem(back);
   scene->removeItem(low_funds);
   for (size_t i=0, n=scene->items().size();i<n;i++)
   {
       scene->items()[i]->setEnabled(true);
   }
}

void Game::display_shop()
{

    for (size_t i=0, n=scene->items().size();i<n;i++)
    {
        scene->items()[i]->setEnabled(false);
    }

    draw(xOff+100,yOff+150,400,300,Qt::lightGray,0.75);



    shop_title = new QGraphicsTextItem(QString("Welcome to Shop"));
    shop_title->setZValue(1000);
    QFont titleFont("comic sans",25);
    shop_title->setFont(titleFont);
    shop_title->setPos(xOff+this->width()/2-shop_title->boundingRect().width()/2,yOff+175);
    scene->addItem(shop_title);

    coin_amount = new QGraphicsTextItem(QString("Coins: " + QString::number(score->getCoins())));
    coin_amount->setZValue(1000);
    QFont coinFont("comic sans",18);
    coin_amount->setFont(coinFont);
    coin_amount->setPos(xOff+this->width()/2-coin_amount->boundingRect().width()/2,yOff+230);
    scene->addItem(coin_amount);

    health_amount = new QGraphicsTextItem(QString("Lives: " + QString::number(health->getHealth())));
    health_amount->setZValue(1000);
    QFont healthFont("comic sans",18);
    health_amount->setFont(healthFont);
    health_amount->setPos(xOff+this->width()/2-health_amount->boundingRect().width()/2,yOff+260);
    scene->addItem(health_amount);

    buy_health = new Button (QString("life"));
    buy_health->setZValue(1000);
    buy_health->setPos(xOff+this->width()/2-buy_health->boundingRect().width()/2,yOff+300);
    connect(buy_health,SIGNAL(clicked()),this,SLOT(purchase()));
    scene->addItem(buy_health);

    back = new Button (QString("return"));
    back->setZValue(1000);
    back->setPos(xOff+this->width()/2-back->boundingRect().width()/2,yOff+380);
    connect(back,SIGNAL(clicked()),this,SLOT(resume()));
    scene->addItem(back);
}

void Game::purchase()
{
    if (score->getCoins()>0 && (health->getHealth()>0 || health->getHealth()<5) )
    {

        score->decreaseCoins();
        coin_amount->setPlainText(QString("Coins: " + QString::number(score->getCoins())));

        health->increase();
        health_amount->setPlainText("Lives: " + QString::number(health->getHealth()));

    }
    else if (score->getCoins()<=0)
    {
        low_funds = new QGraphicsTextItem(QString("insufficient number of coins"));
        low_funds->setZValue(1000);
        QFont coinFont("comic sans",18);
        low_funds->setFont(coinFont);
        low_funds->setPos(xOff+this->width()/2-low_funds->boundingRect().width()/2,yOff+500);
        scene->addItem(low_funds);

    }

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
    QGraphicsTextItem* user_win = new QGraphicsTextItem(QString("You win! Hope you had fun!"));
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
