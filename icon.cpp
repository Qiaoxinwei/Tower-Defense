#include "icon.h"
#include <iostream>
int ICON::GRID_SIZE=32;

pair<string,ICON> pairArray[]=
{
    make_pair("stone",ICON("stone",4,9,1,1)),
    make_pair("enemy1",ICON("enemy1",1,13,1,2)),
    make_pair("enemy2",ICON("enemy2",8,12,1,2)),
    make_pair("enemy3",ICON("enemy3",2,6,1,2)),
    make_pair("enemy4",ICON("enemy4",5,6,1,2)),
    make_pair("enemy5",ICON("enemy5",9,12,1,2)),
    make_pair("tower1",ICON("tower1",8,11,1,1)),
    make_pair("tower2",ICON("tower2",9,11,1,1)),
    make_pair("track1",ICON("track1",6,14,1,1)),
    make_pair("track2",ICON("track2",6,15,1,1)),
    make_pair("track3",ICON("track3",7,14,1,1)),
    make_pair("track4",ICON("track4",7,15,1,1))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));

ICON::ICON(string name,int x, int y,int width, int height):name(name),x(x),y(y),width(width),height(height){}

ICON ICON::findICON(string type)
{
    map<string,ICON>::iterator kv;
    kv=ICON::GAME_ICON_SET.find(type);
    if(kv==ICON::GAME_ICON_SET.end())
    {
        cout<<"Error: cannot find ICON"<<endl;
        return ICON();
    }
    else
    {
        return kv->second;
    }
}

