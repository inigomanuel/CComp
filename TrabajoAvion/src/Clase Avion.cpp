#include "Clase Avion.h"
#include <iostream>
using namespace std;

Clase Avion::Clase Avion(int t, int mot)
{
    m=mot;
    tamanio=t;
}
Clase Avion::Clase Avion()
{
    mot=0;
    tamanio=0;
}
void Clase Avion::getDesc()
{
    cout<<"El avion pesa: "<<peso<<"Kg mide: "<<tamano<<"cmxd"<<endl;
}
Clase Avion::~Clase Avion()
{
    cout<<"BOSTON TENMOS UN PROBLEMA CONCHASUMARE"<<endl;
}
