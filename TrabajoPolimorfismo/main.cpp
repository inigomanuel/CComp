#include <iostream>
#include "Vehiculo.h"
#include "Moto.h"
#include "Camion.h"
#include "Carro.h"
#include "string.h"

using namespace std;

int main()
{
    Moto m("Harley","1960");
    Carro c("Hyundai","2000");
    Camion ca("Mercedes Benz","1950");
    cout << m.getDesc() << endl;
    cout << c.getDesc() << endl;
    cout << ca.getDesc() << endl;
    return 0;
}
