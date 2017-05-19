#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <string.h>
#include "stdlib.h"
using namespace std;

class Alumno
{
    protected:
        string numero;
        string anios;
    public:
        Alumno(const string &myNumero, const string myAnios):numero(myNumero),anios(myAnios){}
        const string getDesc() const {return numero + " noobs " + anios;}
        const string &getNumero() const {return numero;}
        const string getAnios() const {return anios;}
    private:
};

#endif // ALUMNO_H
