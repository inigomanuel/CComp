#ifndef LVL_H
#define LVL_H
#include <MyWindow.h>
#include <Personaje.h>
#include<time.h>
#include <sstream>


const char UP = 72;
const char LEFT = 75;
const char RIGHT = 77;
const char DOWN = 80;
const char ESC = 27;
const char SPACE = 32;

class lvl
{
    protected:
        MyWindow *windowGame;
        Personaje *myPersonaje;
        Personaje *myEnemy;
        Personaje *myNpc;
        Personaje *myNpc1;
    public:
        lvl();
        void Start();
        void Refresh();
        void ReachLimit(Personaje*,Personaje*,Position);
        void GR(Personaje*,Personaje*,Position);
        void GR1(Personaje*,Personaje*,Position);
        void GR2(Personaje*,Personaje*,Position);
        ~lvl();
};

#endif // LVL_H
