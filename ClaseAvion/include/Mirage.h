#ifndef MIRAGE_H
#define MIRAGE_H
#include <iostream>
#include "Avion.h"


class Mirage : public Avion
{
    private:
        int pasajeros;
    public:
        Mirage();
        Mirage(int tamanio1,int motores1,int estado1,int pasajeros);
        virtual ~Mirage();
};

#endif // MIRAGE_H
