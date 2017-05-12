#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
    Vector vec;
    vec.start.x=2.0;
    vec.start.y=4.0;
    vec.endx.y=5.0;
    vec.endx.x=7.0;
    vec.impri();
    vec.origin();
    vec.modulo();
    return 0;
}
