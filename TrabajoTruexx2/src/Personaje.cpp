#include "Personaje.h"
#include <Screen.h>
#include <Position.h>
Personaje::Personaje()
{
    pos.x=0;
    pos.y=0;
    shape='è';
    health=3;
}

Personaje::Personaje(char c)
{
    pos.x=0;
    pos.y=0;
    shape=c;
    health=3;
}

Personaje::Personaje(Position p,char c)
{
    pos.x=p.x;
    pos.y=p.y;
    shape=c;
    health=3;
}
Personaje::Personaje(Position p,char c,string a)
{
    pos.x=p.x;
    pos.y=p.y;
    shape=c;
    health=3;
    dialogue=a;
}
void Personaje::Draw()
{
    DrawPixel(pos,shape);
}

void Personaje::SetShape(char s)
{
    shape= s;
}

void Personaje::Move(int a, int b)
{
    Position j(pos.x+a,pos.y+b);
    DeletePixel(pos);
    pos=j;
}

void Personaje::Move(Position j_)
{
    Position j(pos.x+j_.x, pos.y+j_.y);
    DeletePixel(pos);
    pos=j;
}


Position Personaje::GetPos()
{
    return pos;
}
void Personaje::ChangePos(Position h)
{
    pos=h;
}
int Personaje::GetHealth()
{
    return health;
}
void Personaje::hit()
{
    health+=-1;
}
string Personaje::getDialogue()
{
    return dialogue;
}
