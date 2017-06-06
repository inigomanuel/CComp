#include "Avion.h"
#include <iostream>
using namespace std;

Avion::Avion(int t, int mot,int e)
{
    int m=mot;
    int tamanio=t;
    int estado=e;
}
Avion::Avion()
{
    int mot=0;
    int tamanio=0;
    int estado=0;
}
void Avion::getDesc()
{
    cout<<"El tamanio del avion es: "<<tamanio<<"numero de motores: "<<motores<<"cmxd"<<endl;
}
