#include <iostream>
#include <Avion.h>
#include <vector>
#include "Torre.h"
#include "Avion.h"
using namespace std;
int main()
{
    Avion r;
    cout<<"Tu GFA"<<endl;
    Torre t1;
    t1.aviones.push_back(&r);
    t1.getmensaje();//Encargado de recorrer el vector aviones

    return 0;
}
