#ifndef Personaje_H
#define Personaje_H
#include <Screen.h>
#include <Position.h>
#include <iostream>
using namespace std;
class Personaje:public Screen
{
    protected:
        Position pos;
        char shape;
        int health;
        string dialogue;
    public:
        Personaje();
        Personaje(char);
        Personaje(Position,char);
        Personaje(Position,char,string);
        virtual void Draw();
        void SetShape(char);
        void Move(int a,int b);
        void Move(Position j);
        void ChangePos(Position h);
        int GetHealth();
        Position GetPos();
        void hit();
        string getDialogue();
};
#endif // PERSONAJE_H
