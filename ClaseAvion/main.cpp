#include <iostream>
#include <vector>
#include <Torre.h>
#include <Avion.h>
#include <Boing.h>
#include <Mirage.h>
using namespace std;

int main()
{
    Avion r;
    Mirage m;
    Boing b;
    cout<<"Avion"<<endl;
    Torre t1;
    t1.aviones.push_back(&r);
    t1.aviones.push_back(&m);
    t1.aviones.push_back(&b);
    t1.getmensaje();//Encargado de recorrer el vector aviones
    return 0;
}
