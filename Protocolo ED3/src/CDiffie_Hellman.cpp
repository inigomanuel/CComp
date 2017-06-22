#include "CDiffie_Hellman.h"
#include <iostream>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

ZZ modulo_Z(ZZ a,ZZ n){
    if(a>=0){
        if(a<n){
            return a;}
        return a-(n*(a/n));}
    ZZ c=to_ZZ(a-(n*(a/n)));
    if(c==0)
        return c;
    return a-n*(a/n-1);
}

ZZ exp_mod_rap(ZZ a,ZZ n,ZZ m){

	ZZ exp=to_ZZ("1");
	ZZ dos=to_ZZ("2");
	ZZ x= to_ZZ(modulo_Z(a,m));
	while (n>0){
		if (modulo_Z(n,dos)!=0) { exp=modulo_Z((exp*x),m);}

		x=to_ZZ(modulo_Z((x*x),m));
		n=to_ZZ(n/dos);
	}
	return exp;
}


CDiffie_Hellman::CDiffie_Hellman(ZZ P1,ZZ G1)
{
    P=P1;
    G=G1;
    A=RandomBnd(P);
    C_Publica=exp_mod_rap(G,A,P);
}

ZZ CDiffie_Hellman::Generar_Clave(ZZ C_Recibida){
    return exp_mod_rap(C_Recibida,A,P);
}

CDiffie_Hellman::~CDiffie_Hellman()
{
    //dtor
}
