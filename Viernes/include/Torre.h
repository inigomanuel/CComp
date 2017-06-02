#ifndef TORRE_H
#define TORRE_H
#include <vector>
#include <iostream>
#include "Avion.h"
using namespace std;


class Torre
{
    public:
        vector <Avion *> aviones;
        Torre();
        void getmensaje();
        virtual ~Torre();
    protected:
    private:
};

#endif // TORRE_H
