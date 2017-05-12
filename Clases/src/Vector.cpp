#include "Vector.h"
#include <iostream>
#include <math.h>
using namespace std;

void Vector::impri()
{
    cout<<"Start:";
    start.imprime();
    cout<<"End:";
    endx.imprime();
}
void Vector::origin()
{
    start.x=0.0;
    start.y=0.0;
}
void Vector::modulo()
{
    cout<<"Resultado: "<<sqrt((endx.x-start.x)*(endx.x-start.x)+((endx.y-start.y)*(endx.y-start.y)));
}
