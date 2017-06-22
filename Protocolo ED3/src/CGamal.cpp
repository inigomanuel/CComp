#include "CGamal.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include <bitset>
#include <vector>
#include <stdlib.h>
#include <math.h>

#include <NTL/ZZ.h>


using namespace NTL;
using namespace std;

int modulo(int a,int n){
    if(a>=0){
        if(a<n){
            return a;}
        return a-(n*(a/n));}
    int c=a-(n*(a/n));
    if(c==0)
        return c;
    return a-n*(a/n-1);
}

ZZ dos=to_ZZ("2");
ZZ uno=to_ZZ("1");
ZZ cero=to_ZZ("0");
ZZ menos_1=to_ZZ("-1");

ZZ modulo_Z_G(ZZ a,ZZ n){
    if(a>=0){
        if(a<n){
            return a;}
        return a-(n*(a/n));}
    ZZ c=to_ZZ(a-(n*(a/n)));
    if(c==0)
        return c;
    return a-n*(a/n-1);
}


ZZ exp_mod_rap_G(ZZ a,ZZ n,ZZ m){

	ZZ exp=to_ZZ("1");
	ZZ dos=to_ZZ("2");
	ZZ x= to_ZZ(modulo_Z_G(a,m));
	while (n>0){
		if (modulo_Z_G(n,dos)!=0) { exp=modulo_Z_G((exp*x),m);}

		x=to_ZZ(modulo_Z_G((x*x),m));
		n=to_ZZ(n/dos);
	}

	return exp;
}

ZZ inversa(ZZ a, ZZ b){
    ZZ r1,r2,r,q,s1,s2,s;
    s2=to_ZZ("0");
    s1=to_ZZ("1");
    r1=to_ZZ(a);r2=to_ZZ(b);
    while(r2>0){
        q=to_ZZ(r1/r2);
        r=to_ZZ(r1-q*r2);
        r1=to_ZZ(r2);r2=to_ZZ(r);
        s=to_ZZ(s1-q*s2);
        s1=to_ZZ(s2);s2=to_ZZ(s);
    }
    if(s1<0)
        return s1+abs(b);
return s1;}

bool millerTest(ZZ N, ZZ D){
    ZZ A=RandomBnd(N);
        while(A==cero||A==uno||A==dos){A=RandomBnd(N);}
    ZZ x=exp_mod_rap_G(A,D,N);
    if(x==uno||x==N-uno){return true;}
    while(D!=N-uno){
        x=modulo_Z_G(x*x,N);
        D*=2;
        if(x==uno)return false;
        if(x==N-uno)return true;
    }
return false;
}
bool isPrime(ZZ N){///las iteraciones ya estan definidas
    //if(N<=1||N==4)return false;
    //if(N<=3)return true;
    ZZ D=N-uno;
    while((D&1)==0){D/=dos;}
    for(int i=0;i<10;i++){
        if(millerTest(N,D)==false)return false;
    }
    return true;
}

ZZ Phi(ZZ X){
    if(X==uno){
        return cero;
    }
    if(isPrime(X)==true){
        return X-uno;
    }
    else{
        ZZ res=uno;
        for(ZZ i=to_ZZ("2");i<=X;i++){
            ZZ aux_num=cero;
            ZZ aux_res;
            long aux_pot=0;
                while(modulo_Z_G(X,i)==cero){
                aux_num=i;
                aux_pot++;
                X/=i;
                }
            if(aux_num!=0){
                aux_res=power(aux_num,aux_pot)-power(aux_num,aux_pot-1);
                res*=aux_res;
            }
            //cout<<aux_num<<",";
        }
    return res;
    }
}

ZZ find_generador_eficiente(ZZ num){
    //ZZ raiz_primitiva=Phi(Phi(num));
    //if(raiz_primitiva>cero){
    ZZ elemento_generador;
    ZZ q=(num-uno)/dos;
    for(ZZ i=uno;i<num-uno;i++){
        //cout<<exp_mod_rap(i,dos,num)<<endl;
        //cout<<exp_mod_rap(i,q,num)<<endl<<endl;
        if(exp_mod_rap_G(i,dos,num)!=uno&&exp_mod_rap_G(i,q,num)!=uno){
            return i;
        }
    }
    //}
    return cero;
}

std::string numberToString_G(const ZZ &num)
{
    std::stringstream buffer;
    buffer << num;
    return buffer.str();
}

ZZ numberToZZ_G(string palabra){
    ZZ num(INIT_VAL,palabra.c_str());
    return num;
}

int tamano_bloques(ZZ num){
    string aux=numberToString_G(num);
    int tam_bloques=aux.size();
    return tam_bloques;
}

string transformar_mensaje(string mensaje,string alfabeto){
string guardar_num;
    for(int x=0;x<mensaje.size();x++){
        int num=alfabeto.find(mensaje[x]);
            stringstream stream;
            stream << num;
            string palabra;
            palabra=stream.str();
            if(num<10){
                palabra="0"+palabra;
            }
            guardar_num=guardar_num+palabra;
            }
return guardar_num;
}

string aumentar_basura(string mensaje,int tam_bloques){
    string aumentar="23";
    while(modulo(mensaje.size(),tam_bloques)!=0){
        mensaje=mensaje+aumentar;
    }
    return mensaje;
}
ZZ R;
string cifrar_mensaje(string mensaje,ZZ E1,ZZ E2,ZZ P,string alfabeto,ZZ &C1){
    string encriptado;
    ZZ K;
    int tam_bloques,num_bucle;
    vector<ZZ>bloques;
    vector<string>bloques_exponenciacion;

    C1=exp_mod_rap_G(E1,R,P);//cout<<"C1: "<<C1<<endl;
    K=exp_mod_rap_G(E2,R,P);

    //cout<<"MENSAJE ORIGINAL: "<<mensaje<<endl;
    mensaje=transformar_mensaje(mensaje,alfabeto);
   // cout<<"MENSAJE TRANFORMACION 1:"<<mensaje<<endl;
    tam_bloques=tamano_bloques(P); //cout<<"TAMAÑO DE LOS BLOQUES: "<<tam_bloques<<endl;
    mensaje=aumentar_basura(mensaje,tam_bloques);
   // cout<<"MENSAJE MAS BASURA SEGUN P: "<<mensaje<<endl;
    num_bucle=mensaje.size()/tam_bloques;

    int aux_num=0,aux_num_2=0;
    for(int x=0;x<num_bucle;x++){
        string aux;
        for(int i=0;i<tam_bloques;i++){
            aux+=mensaje[i+aux_num_2];
            aux_num++;
        }
    aux_num_2=aux_num;
    //cout<<aux<<endl;
    bloques.push_back(numberToZZ_G(aux));
    }

    for(int i=0;i<num_bucle;i++){
        ZZ aux_exp;
        aux_exp=modulo_Z_G(bloques[i]*K,P);
        string palabra=numberToString_G(aux_exp);
        //cout<<"BLOQUE PROCESADO: "<<palabra<<endl;
        bloques_exponenciacion.push_back(palabra);
    }

    string aumentar_cero="0";
    for(int i=0;i<num_bucle;i++){
        string aumentador;
        aumentador=bloques_exponenciacion[i];
        while(aumentador.size()!=tam_bloques){
            aumentador=aumentar_cero+aumentador;
        }
       // cout<<"BLOQUE SEGUN TAMAÑO P: "<<aumentador<<endl;
        encriptado+=aumentador;
    }
    return encriptado;
}

string destransformar_mensaje(vector<ZZ>mensaje,string abecedario){
    string guar_respuesta;
    for(int x=0;x<mensaje.size();x++){
        for(int y=0;y<abecedario.size();y++){
        if(mensaje[x]==y){guar_respuesta+=abecedario[y];}
        }
    }
    return guar_respuesta;
}


string descifrar_mensaje(string C2,ZZ C1,ZZ D,ZZ P,string abecedario){
    string res_mensaje;
    string cero="0";

    int tam_bloques,bucle;
    vector<ZZ>g_bloques;
    ZZ K,K_inversa;
    K=exp_mod_rap_G(C1,D,P);
    K_inversa=inversa(K,P);
    tam_bloques=tamano_bloques(P);
    bucle=C2.size()/tam_bloques;

    int aux_num_1=0,aux_num_2=0;
    for(int i=0;i<bucle;i++){
        string aux;
        for(int x=0;x<tam_bloques;x++){
            aux+=C2[x+aux_num_2];
            aux_num_1++;
        }
        aux_num_2=aux_num_1;
       // cout<<"SEPARANDO BLOQUES: "<<aux<<endl;
        g_bloques.push_back(numberToZZ_G(aux));
    }
    //cout<<endl;
    string bloques_aum;
    for(int i=0;i<bucle;i++){
        //cout<<"BLOQUE A PROCESAR: "<<g_bloques[i]<<endl;
        ZZ aux_exp=modulo_Z_G(g_bloques[i]*K_inversa,P);
        string palabra=numberToString_G(aux_exp);
            while(palabra.size()!=tam_bloques){
                palabra=cero+palabra;
            }
          //  cout<<"PALABRA PROCESADA: "<<palabra<<endl;
    bloques_aum+=palabra;
    }

    vector<ZZ>guardar_exp;
    int aux_1=0,aux_0=0;
    for(int i=0;i<bloques_aum.size()/2;i++){
        string aux;
        for(int y=0;y<2;y++){
            aux+=bloques_aum[y+aux_1];
            aux_0++;
        }
        aux_1=aux_0;
        ZZ convertir=numberToZZ_G(aux);
        guardar_exp.push_back(convertir);
    }
    return destransformar_mensaje(guardar_exp,abecedario);
}

string cifrar_firma(string mensaje,ZZ E1,ZZ E2,ZZ P,ZZ &C1){
    string encriptado;
    ZZ K;
    int tam_bloques,num_bucle;
    vector<ZZ>bloques;
    vector<string>bloques_exponenciacion;
    R=RandomBnd(P-1);
    while(R==0||R==1||R==2){R=RandomBnd(P-1);}
    C1=exp_mod_rap_G(E1,R,P);//cout<<"C1: "<<C1<<endl;
    K=exp_mod_rap_G(E2,R,P);

    tam_bloques=tamano_bloques(P); //cout<<"TAMAÑO DE LOS BLOQUES: "<<tam_bloques<<endl;
    mensaje=aumentar_basura(mensaje,tam_bloques);
    //cout<<"MENSAJE MAS BASURA SEGUN P: "<<mensaje<<endl;
    num_bucle=mensaje.size()/tam_bloques;

    int aux_num=0,aux_num_2=0;
    for(int x=0;x<num_bucle;x++){
        string aux;
        for(int i=0;i<tam_bloques;i++){
            aux+=mensaje[i+aux_num_2];
            aux_num++;
        }
    aux_num_2=aux_num;
    //cout<<aux<<endl;
    bloques.push_back(numberToZZ_G(aux));
    }

    for(int i=0;i<num_bucle;i++){
        ZZ aux_exp;
        aux_exp=modulo_Z_G(bloques[i]*K,P);
        string palabra=numberToString_G(aux_exp);
        //cout<<"BLOQUE PROCESADO: "<<palabra<<endl;
        bloques_exponenciacion.push_back(palabra);
    }

    string aumentar_cero="0";
    for(int i=0;i<num_bucle;i++){
        string aumentador;
        aumentador=bloques_exponenciacion[i];
        while(aumentador.size()!=tam_bloques){
            aumentador=aumentar_cero+aumentador;
        }
        //cout<<"BLOQUE SEGUN TAMAÑO P: "<<aumentador<<endl;
        encriptado+=aumentador;
    }
    return encriptado;
}

string descifrar_firma(string C2,ZZ C1,ZZ D,ZZ P){
    string cero="0";
    int tam_bloques,bucle;
    vector<ZZ>g_bloques_2;

    ZZ K,K_inversa;
    K=exp_mod_rap_G(C1,D,P);
    K_inversa=inversa(K,P);
    tam_bloques=tamano_bloques(P);
    bucle=C2.size()/tam_bloques;

    int aux_num_1=0,aux_num_2=0;
    for(int i=0;i<bucle;i++){
        string aux;
        for(int x=0;x<tam_bloques;x++){
            aux+=C2[x+aux_num_2];
            aux_num_1++;
        }
        aux_num_2=aux_num_1;
        cout<<"SEPARANDO BLOQUES: "<<aux<<endl;
        g_bloques_2.push_back(numberToZZ_G(aux));
    }
    cout<<endl;
    string bloques_aum;
    for(int i=0;i<bucle;i++){
        cout<<"BLOQUE A PROCESAR: "<<g_bloques_2[i]<<endl;
        ZZ aux_exp=modulo_Z_G(g_bloques_2[i]*K_inversa,P);
        string palabra=numberToString_G(aux_exp);
            while(palabra.size()!=tam_bloques){
                palabra=cero+palabra;
            }
            cout<<"PALABRA PROCESADA: "<<palabra<<endl;
    bloques_aum+=palabra;
    }
    return bloques_aum;
}

string recuperar_mensaje(string mensaje){
    string mensaje_ress;
    for(int i=0;i<mensaje.size();i++){
        if(mensaje[i]!='#'){mensaje_ress+=mensaje[i];}
        else{return mensaje_ress;}
    }
}

string recuperar_firma(string mensaje){
    string mensaje_ress;
    int aux_entrada=0;
    for(int i=0;i<mensaje.size();i++){
        if(aux_entrada==1){
            mensaje_ress+=mensaje[i];
        }
        if(mensaje[i]=='#'){
            aux_entrada=1;
        }
    }
    return mensaje_ress;
}

CGamal::CGamal(int tam_bits)
{
    //P=to_ZZ("2");
    P=RandomPrime_ZZ(tam_bits);
    E_1=find_generador_eficiente(P);
    //E_1=to_ZZ("3");
    //D=to_ZZ("4");//
    D=RandomBnd(P-1);///clave privada
    while(D==0||D==1||D==2){
       D=RandomBnd(P-1);
    }
    //E_2=to_ZZ("23");
    E_2=exp_mod_rap_G(E_1,D,P);///clave publica
    cout<<endl<<"Primo Generado: "<<P<<endl;
    cout<<"Elemento Generador: "<<E_1<<endl;
    cout<<"CLAVE PRIVADA: "<<D<<endl;
    cout<<"CLAVE PUBLICA: "<<E_2<<endl;

    string guardar_aux1="E1:  ";
    string guardar_aux2="E2:  ";
    string guardar_aux3="P:  ";
    ofstream fs("claves_gamal.txt");
    fs <<guardar_aux1<<endl;
    fs << E_1 << endl;
    fs <<guardar_aux2<<endl;
    fs << E_2 << endl;
    fs <<guardar_aux3<<endl;
    fs << P << endl;
    fs.close();
}

void CGamal::Gamal_encriptado_texto(ZZ E1,ZZ E2,ZZ P,string firma){
    string mensaje_encriptado;
    string guardar_pal;
    ifstream fichero("mensaje.txt");
    ofstream encriptado;
    encriptado.open("encriptado_gamal.txt");
    char caracter;
    while(fichero.get(caracter))
        {
        guardar_pal+=caracter;
        }
    fichero.close();
    cout<<"MENSAJE A ENCRIPTAR GAMAL: "<<guardar_pal<<endl;
    mensaje_encriptado=cifrar_mensaje(guardar_pal,E1,E2,P,abecedario,C_1)+'#'+firma;
    encriptado<<mensaje_encriptado<<endl;
    encriptado.close();

    cout<<"C1 : "<<C_1<<endl;
    string guardar_aux1="C1:  ";
    ofstream fs("C1.txt");
    fs <<guardar_aux1<<endl;
    fs << C_1 << endl;
    fs.close();
    cout<<mensaje_encriptado<<endl;
}

string CGamal::Gamal_desencriptado_texto(ZZ C1){
    string mensaje_descencriptado;
    string guardar_pal;
    ifstream fichero("mensaje_recibido.txt");
    ofstream encriptado;
    encriptado.open("mensaje_desencriptado.txt");
    char caracter;
    while(fichero.get(caracter))
        {
        guardar_pal+=caracter;
        }
    fichero.close();
    cout<<"MENSAJE A DESENCRIPTAR GAMAL: "<<guardar_pal<<endl<<endl;
    string guardar_palabra=recuperar_mensaje(guardar_pal);
    mensaje_descencriptado=descifrar_mensaje(guardar_palabra,C1,D,P,abecedario);
    encriptado<<mensaje_descencriptado<<endl;
    encriptado.close();
    cout<<"MENSAJE DESENCRIPTADO GAMAL: "<<mensaje_descencriptado<<endl;
    return guardar_pal;
}

string CGamal::Gamal_encriptado_firma(ZZ E1,ZZ E2,ZZ P,string mensaje){
    string mensaje_encriptado;
    cout<<"FIRMA A ENCRIPTAR GAMAL: "<<mensaje<<endl;
    mensaje_encriptado=cifrar_firma(mensaje,E1,E2,P,C_1_Firma);
    cout<<"FIRMA ENCRIPTADA GAMAL: "<<mensaje_encriptado<<endl;
    cout<<"C1 FIRMA : "<<C_1_Firma<<endl;
    string guardar_aux1="C1:  ";
    ofstream fs("C1 firma.txt");
    fs <<guardar_aux1<<endl;
    fs << C_1_Firma << endl;
    fs.close();
    return mensaje_encriptado;
}

string CGamal::Gamal_desencriptado_firma(ZZ C1,string mensaje){
    string mensaje_descencriptado;
    string mensaje_r=recuperar_firma(mensaje);
    cout<<"FIRMA A DESENCRIPTAR GAMAL: "<<mensaje_r<<endl<<endl;
    mensaje_descencriptado=descifrar_firma(mensaje_r,C1,D,P);
    cout<<"FIRMA DESENCRIPTADO GAMAL: "<<mensaje_descencriptado<<endl;
    return mensaje_descencriptado;
}
CGamal::~CGamal()
{
    //dtor
}
