#include "log_in.h"
#include "ui_log_in.h"
#include "game.h"
extern Game* game;
log_in::log_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);
}

log_in::~log_in()
{
    delete ui;
}

void log_in::on_pushButton_clicked()
{
    hide();
    game = new Game();
    game->mainMenu2();
}

