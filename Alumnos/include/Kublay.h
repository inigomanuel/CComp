#ifndef KUBLAY_H
#define KUBLAY_H
#include "Alumno.h"
#include <iostream>
#include <string.h>
using namespace std;

class Kublay : public Alumno
{
    string numero;
    public:
        Kublay(const string &myNumero, const string myAnios):Alumno(myNumero,myAnios),numero(myNumero){}
        const string &getNumero(){return numero;}
    protected:
    private:
};

#endif // KUBLAY_H
