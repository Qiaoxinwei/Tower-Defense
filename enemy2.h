#ifndef ENEMY2_H
#define ENEMY2_H
#include <QPoint>
#include "icon.h"
#include "mainwindow.h"
#include <QPainter>
#include "ui_mainwindow.h"
class MainWindow;


class Enemy2 :public TDobj,public QObject
{
public:
    Enemy2(MainWindow *game);
    ~Enemy2();
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

#endif // ENEMY2_H
