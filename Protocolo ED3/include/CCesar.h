#ifndef CCESAR_H
#define CCESAR_H
#include <vector>
#include <NTL/ZZ.h>
#include <iostream>

using namespace NTL;
using namespace std;

class CCesar
{
    public:
        CCesar(ZZ);
        string cifrar();
        vector<ZZ> descifrar(vector<ZZ>);
        virtual ~CCesar();

    protected:

    private:
        ZZ clave;
};

#endif // CCESAR_H
