#include "enemy1.h"
#include <QRect>
#include <QPoint>
#include <qmath.h>

Enemy1::Enemy1(MainWindow *game):QObject(0),mygame(game)
{
    this->alive=false;
    this->maxHP=100;
    this->speed=1;
    this->currentHP=100;
}

Enemy1::~Enemy1(){}

void Enemy1::move()
{
    if(!this->alive)
        return;
    if((this->posy==5)&&(this->posx>=0)&&(this->posx<21))
    {
        this->posx+=this->speed;
        this->posy=this->posy;
    }
    if((this->posx==21)&&(this->posy>=5)&&(this->posy<14))
    {
        this->posx=this->posx;
        this->posy+=this->speed;
    }
    if((this->posy==14)&&(this->posx<=21)&&(this->posx>0))
    {
        this->posy=this->posy;
        this->posx-=this->speed;
    }
    if((this->posx==0)&&(this->posy==14))
    {
        this->mygame->getHPdamage();
        this->mygame->removeEnemy1(this);
    }
}



