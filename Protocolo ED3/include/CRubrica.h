#ifndef CRUBRICA_H
#define CRUBRICA_H
#include <vector>
#include <iostream>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

class CRubrica
{
    public:
        ZZ P,Q,N;
        ZZ Phi_N;
        ZZ D,E;
        CRubrica(int);
        string Firma_encriptado(ZZ,ZZ,string);
        vector<ZZ> Firma_desencriptado(ZZ,ZZ,string);
        virtual ~CRubrica();

    protected:

    private:
};

#endif // CRUBRICA_H
