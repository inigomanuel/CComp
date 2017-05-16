#include "Complejo.h"
#include <iostream>
using namespace std;

Complejo::Complejo(double x, double y)
{
    real=x;
    complejo=y;
}
Complejo Complejo::suma(Complejo x)
{
    double a=real,b=complejo;
    double w=x.real,z=x.complejo;
    x.real=a+w;
    x.complejo=b+z;
    return x;

}
void Complejo::imprimir()
{
    cout<<real<<complejo<<endl;
}
