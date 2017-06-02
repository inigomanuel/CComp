#include "Avion.h"
#include <iostream>
using namespace std;

Avion::Avion(int t, int mot)
{
    int m=mot;
    int tamanio=t;
}
Avion::Avion()
{
    int mot=0;
    int tamanio=0;
}
void Avion::getDesc()
{
    cout<<"El tamanio del avion es: "<<tamanio<<"numero de motores: "<<motores<<"cmxd"<<endl;
}
Avion::~Avion()
{
    cout<<"Destructor utilizado"<<endl;
}
