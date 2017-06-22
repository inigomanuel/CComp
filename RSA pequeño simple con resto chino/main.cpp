#include <iostream>
#include "RSA.h"


using namespace std;


int main()
{
    RSA obj1(512);
    int bucle=0;
    while(bucle!=1)
    {
    int opcion;
    cout<<"1)ENCRIPTAR"<<endl;
    cout<<"2)DESENCRIPTAR"<<endl;
    cout<<"ELIJA UN OPCION:";
    cin>>opcion;
    if(opcion==1){
    ZZ a,b;
    cout<<"INGRESE CLAVE PUBLICA: "<<endl;
    cout<<"ingrese E: ";
    cin>>a;
    cout<<"ingrese N: ";
    cin>>b;
    cout<<endl;
    obj1.RSA_encriptado(a,b);
    cout<<endl;
    system("pause");
    cout<<endl;
    }
    if(opcion==2){
    obj1.RSA_desencriptado();
    system("pause");
    cout<<endl;
    }
    }
    return 0;
}


