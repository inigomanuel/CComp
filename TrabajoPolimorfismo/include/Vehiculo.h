#ifndef VEHICULO_H
#define VEHICULO_H
#include "string.h"
using namespace std;
class Vehiculo
{
    protected:
        string tipo;
        string anio;
    public:
        Vehiculo(const string &myTipo, const string myAnio);
        const string getDesc() const {return tipo + ", " + anio;}
        const string &getTipo() const {return tipo;}
        const string getAnios() const {return anio;}


};

#endif // VEHICULO_H
        Alumno(const string &myNumero, const string myAnios):numero(myNumero),anios(myAnios){}
