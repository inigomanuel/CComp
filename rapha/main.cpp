#include <iostream>
#include <Complejo.h>

using namespace std;

int main()
{
    Complejo a(5.0,6.0);
    Complejo b(4.0,3.0);
    Complejo c=a.suma(b);
    c.imprimir();
    return 0;
}
