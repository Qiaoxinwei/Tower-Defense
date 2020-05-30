#ifndef ENEMY1_H
#define ENEMY1_H
#include <QPoint>
#include "icon.h"
#include "mainwindow.h"
#include <QPainter>
#include "ui_mainwindow.h"
class MainWindow;


class Enemy1 :public TDobj,public QObject
{
public:
    Enemy1(MainWindow *game);
    ~Enemy1();
    void move();
    bool getlivingcondition();
    bool alive;
    int getPosx(){return this->posx;}
    int getPosy(){return this->posy;}
private:
    int maxHP;
    int currentHP;
    int speed;
    MainWindow *mygame;
};

#endif // ENEMY1_H
