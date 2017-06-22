#include "CCesar.h"
#include <sstream>
#include <fstream>


ZZ modulo_Z_Cesar(ZZ a,ZZ n){
    if(a>=0){
        if(a<n){
            return a;}
        return a-(n*(a/n));}
    ZZ c=to_ZZ(a-(n*(a/n)));
    if(c==0)
        return c;
    return a-n*(a/n-1);
}

ZZ numberToZZ(string palabra){
    ZZ num(INIT_VAL,palabra.c_str());
    return num;
}

std::string numberToString(const ZZ &num)
{
    std::stringstream buffer;
    buffer << num;
    return buffer.str();
}

string cifrar_mensaje(string palabra,ZZ clave){
    vector<ZZ>ress;
    string aux,vacio,ress_final;
    cout<<palabra<<endl;
    for(int i=0;i<palabra.size();i++){
        if(palabra[i]!=' '){
            aux+=palabra[i];
        }
        else{
            ress.push_back(numberToZZ(aux));
            aux=vacio;
        }
    }

    /*for(int i=0;i<ress.size();i++){
        cout<<ress[i]<<endl;
    }*/
    ZZ modulo=to_ZZ("255");
    for(int i=0;i<ress.size();i++){
        ZZ pos=ress[i]+clave;
        if(pos>modulo){
            pos=modulo_Z_Cesar(pos,modulo);
        }
        ress_final+=numberToString(pos);
    }
    return ress_final;
}


CCesar::CCesar(ZZ clv)
{
   clave=clv;
}

string CCesar::cifrar(){
   string mensaje_encriptado;
    string guardar_pal;
    ifstream fichero("matriz imagen.txt");
    char caracter;
    while(fichero.get(caracter))
        {
        guardar_pal+=caracter;
        }
    fichero.close();
    mensaje_encriptado=cifrar_mensaje(guardar_pal,clave);
    cout<<"ENCRIPTADO CON CESAR: "<<mensaje_encriptado;
    return mensaje_encriptado;
}

vector<ZZ> CCesar::descifrar(vector<ZZ>recibido){
    ZZ cero=to_ZZ("0");
    ZZ menos_uno=to_ZZ("-1");
    vector<ZZ> resultado;
    for(int i=0;i<recibido.size();i++){
        ZZ pos=recibido[i]-clave;
        if(pos<cero){
            pos=pos*menos_uno;
        }
        resultado.push_back(pos);
    }
    return resultado;
}

CCesar::~CCesar()
{
    //dtor
}
