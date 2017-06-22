#include "CDiffie_Hellman.h"
#include "CCesar.h"
#include "CRubrica.h"
#include "CGamal.h"
#include "windows.h"
using namespace std;

int main()
{
    ZZ P=to_ZZ("21");//generar_num_primo(16);
    ZZ G=to_ZZ("2");//find_generador_eficiente(P);
    //DIFFI HELLMAN
    CDiffie_Hellman obj1(P,G);
    ZZ clv_recibida;
    cout<<"INGRESE LA CLAVE RECIBIDA: ";
    cin>>clv_recibida;
    ZZ clv_cesar=obj1.Generar_Clave(clv_recibida);
    //
    //CESAR
    cout<<"CLAVE PARA CESAR: "<<clv_cesar<<endl;
    CCesar obj2(clv_cesar);
    string ress_cesar=obj2.cifrar();
    //FIRMA DIGITAL
    CRubrica obj3(64);
    ZZ E,N;
    cout<<endl;
    cout<<"INGRESE E: ";
    cin>>E;
    cout<<"INGRESE N: ";
    cin>>N;
    string ress_firma=obj3.Firma_encriptado(E,N,ress_cesar);
    //

    //GAMAL
    CGamal obj4(64);
    ZZ E1,E2,P_G;
    cout<<"INGRESE E1: ";
    cin>>E1;
    cout<<"INGRESE E2: ";
    cin>>E2;
    cout<<"INGRESE P: ";
    cin>>P_G;
    string ress_gamal_firma=obj4.Gamal_encriptado_firma(E1,E2,P_G,ress_firma);
    obj4.Gamal_encriptado_texto(E1,E2,P_G,ress_gamal_firma);
    //
    system("pause");

    ZZ C1;
    cout<<"INGRESE C1: ";
    cin>>C1;
    string rec_mensaje=obj4.Gamal_desencriptado_texto(C1);
    ZZ C1f;
    cout<<"INGRESE C1 Firma: ";
    cin>>C1f;
    string rec_firma=obj4.Gamal_desencriptado_firma(C1f,rec_mensaje);
    vector<ZZ> rec_firma_RSA=obj3.Firma_desencriptado(E,N,rec_firma);
    vector<ZZ> ress=obj2.descifrar(rec_firma_RSA);
    for(int i=0;i<ress.size();i++){
        cout<<ress[i]<<endl;
    }
    system("pause");

}
