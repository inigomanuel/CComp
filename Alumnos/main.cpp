#include <iostream>
#include "Alumno.h"
#include "string.h"
#include "Kublay.h"

using namespace std;

int main()
{
    Alumno a(":v","me la pela");
    Kublay k("v:","sucia");
    cout << a.getDesc() << endl;
    cout << k.getDesc() << endl;
    return 0;
}
