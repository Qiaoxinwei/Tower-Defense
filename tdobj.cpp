#include "tdobj.h"
#include <iostream>
#include <QRect>
using namespace std;

void TDobj::initObj(string type)
{
    this->icon=ICON::findICON(type);
    QImage all;
    all.load("C:/Users/qiaoxingwei/Desktop/QTMap/TileB.png");
    this->pic=all.copy(QRect(icon.getX()*ICON::GRID_SIZE,icon.getY()*ICON::GRID_SIZE,icon.getWidth()*ICON::GRID_SIZE,icon.getHeight()*ICON::GRID_SIZE));
}

void TDobj::show(QPainter *painter)
{
    int gSize=ICON::GRID_SIZE;
    painter->drawImage(this->posx*gSize,this->posy*gSize,this->pic);
}
