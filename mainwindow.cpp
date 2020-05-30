#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include "icon.h"
#include <map>
#include <iostream>
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initworld();
    QTimer *timer1=new QTimer(this);
    QTimer *timer2=new QTimer(this);
    QTimer *timer3=new QTimer(this);
    QTimer *timer4=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(initenemy1()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(updateenemy1()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(initenemy2()));
    connect(timer4,SIGNAL(timeout()),this,SLOT(updateenemy2()));
    timer1->start(2000);
    timer2->start(1000);
    timer3->start(2000);
    timer4->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter *pa;
    pa=new QPainter();
    pa->begin(this);
    this->showworld(pa);
    pa->end();
    delete pa;
    QPainter *pa1;
    pa1=new QPainter();
    pa1->begin(this);
    int n1=this->m_enemy1list.size();
    for(int i1=0;i1<n1;i1++)
    {
        this->m_enemy1list[i1]->show(pa1);
    }
    pa1->end();
    delete pa1;
    QPainter *pa2;
    pa2=new QPainter();
    pa2->begin(this);
    int n2=this->m_enemy2list.size();
    for(int i2=0;i2<n2;i2++)
    {
        this->m_enemy2list[i2]->show(pa2);
    }
    pa2->end();
    delete pa2;
}

void MainWindow::getHPdamage(int damage)
{

}

void MainWindow::removeEnemy1(Enemy1* enemy)
{
    this->m_enemy1list.removeOne(enemy);
    delete enemy;
}

void MainWindow::removeEnemy2(Enemy2 *enemy)
{
    this->m_enemy2list.removeOne(enemy);
    delete enemy;
}

void MainWindow::initenemy1()
{
    if(this->m_enemy1list.size()<=3)
    {
        Enemy1 *enemy=new Enemy1(this);
        enemy->initObj("enemy1");
        enemy->setPosX(0);
        enemy->setPosY(5.0);
        enemy->alive=true;
        this->m_enemy1list.push_back(enemy);
    }
    else
        return;
}

void MainWindow::initenemy2()
{
    if(this->m_enemy2list.size()<=3)
    {
        Enemy2 *enemy=new Enemy2(this);
        enemy->initObj("enemy2");
        enemy->setPosX(7);
        enemy->setPosY(5);
        enemy->alive=true;
        this->m_enemy2list.push_back(enemy);
    }
    else
        return;
}

void MainWindow::initworld()
{
    int i;
    for(i=0;i<=22;i++)
    {
        TDobj *p=new TDobj;
        p->initObj("stone");
        p->setPosX(i);
        p->setPosY(4);
        this->objs.push_back(p);
    }
    for(i=0;i<=20;i++)
    {
        TDobj *p=new TDobj;
        p->initObj("stone");
        p->setPosX(i);
        p->setPosY(7);
        this->objs.push_back(p);
    }
    for(i=0;i<=11;i++)
    {
        TDobj *p=new TDobj;
        p->initObj("stone");
        p->setPosX(22);
        p->setPosY(5+i);
        this->objs.push_back(p);
    }
    for(i=0;i<=5;i++)
    {
        TDobj *p=new TDobj;
        p->initObj("stone");
        p->setPosX(20);
        p->setPosY(8+i);
        this->objs.push_back(p);
    }
    for(i=0;i<=22;i++)
    {
        TDobj *p=new TDobj;
        p->initObj("stone");
        p->setPosX(i);
        p->setPosY(16);
        this->objs.push_back(p);
    }
    for(i=0;i<=20;i++)
    {
        TDobj *p=new TDobj;
        p->initObj("stone");
        p->setPosX(i);
        p->setPosY(13);
        this->objs.push_back(p);
    }
}

void MainWindow::showworld(QPainter *painter)
{
    int n=this->objs.size();
    for(int i=0;i<n;i++)
    {
        this->objs[i]->show(painter);
    }
}

void MainWindow::updateenemy1()
{
    foreach(Enemy1* enemy,this->m_enemy1list)
        enemy->move();
    this->repaint();
}

void MainWindow::updateenemy2()
{
    foreach(Enemy2* enemy,this->m_enemy2list)
        enemy->move();
    this->repaint();
}

