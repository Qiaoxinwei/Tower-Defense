#ifndef TDOBJ_H
#define TDOBJ_H
#include <QPainter>
#include <QImage>
#include <string>
#include "icon.h"
#include <map>

using namespace std;


class TDobj
{
public:
    TDobj(){}
    void initObj(string type);
    void show(QPainter *painter);
    void setPosX(int x) {this->posx=x;}
    void setPosY(int y) {this->posy=y;}
    int getPosX() const{return this->posx;}
    int getPosY() const{return this->posy;}
    int getHeight() const{return this->icon.getHeight();}
    int getWidth() const{return this->icon.getWidth();}
    string getObjType() const{return this->icon.getTypeName();}
protected:
    float posx,posy;
    ICON icon;
    QImage pic;
};


#endif // TDOBJ_H
