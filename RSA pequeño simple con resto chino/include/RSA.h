#ifndef RSA_H
#define RSA_H
#include <NTL/ZZ.h>
#include "libreria_RSA.h"
#include <iostream>

using namespace NTL;
using namespace std;

class RSA
{
    public:
        ZZ P,Q,N;
        ZZ Phi_N;
        ZZ D,E;
        RSA(int);
        void RSA_encriptado(ZZ,ZZ);
        void RSA_desencriptado();
        //string firma="Gonzalo Carlos Sanchez Quispe";
        string abecedario="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890,;:-_<>@*+";
        virtual ~RSA();

    protected:

    private:
};

#endif // RSA_H
