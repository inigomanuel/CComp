#ifndef CDIFFIE_HELLMAN_H
#define CDIFFIE_HELLMAN_H

#include <iostream>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

class CDiffie_Hellman
{
    public:
        ZZ P;
        ZZ G;
        ZZ A;
        ZZ C_Publica;
        CDiffie_Hellman(ZZ,ZZ);
        ZZ Generar_Clave(ZZ);
        virtual ~CDiffie_Hellman();

    protected:

    private:
};

#endif // CDIFFIE_HELLMAN_H
