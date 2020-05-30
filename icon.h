#ifndef ICON_H
#define ICON_H
#include <string>
#include <map>
using namespace std;

class ICON
{
public:
    static int GRID_SIZE;
    static map<string,ICON> GAME_ICON_SET;
    static ICON findICON(string type);
    ICON(){}
    ICON(string name,int x, int y, int width, int height);
    string getTypeName() const{return this->name;}
    int getX() const{return this->x;}
    int getY() const{return this->y;}
    int getWidth() const{return this->width;}
    int getHeight() const{return this->height;}
private:
    string name;
    int x,y,width,height;
};

#endif // ICON_H
