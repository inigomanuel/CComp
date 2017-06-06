#ifndef BOING_H
#define BOING_H
#include <iostream>
#include "Avion.h"


class Boing : public Avion
{
    private:
        int pasajeros;
    public:
        Boing();
        Boing(int tamanio1,int motores1,int estado1,int pasajeros);
        virtual ~Boing();
};

#endif // BOING_H
