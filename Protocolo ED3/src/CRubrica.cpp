#include "CRubrica.h"
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
#include <conio.h>

using namespace NTL;
using namespace std;

ZZ cero_G=to_ZZ("0");
ZZ menos_1_G=to_ZZ("-1");
ZZ uno_G=to_ZZ("1");
ZZ dos_G=to_ZZ("2");
ZZ cinco=to_ZZ("5");

int modulo_G(int a,int n){
    if(a>=0){
        if(a<n){
            return a;}
        return a-(n*(a/n));}
    int c=a-(n*(a/n));
    if(c==0)
        return c;
    return a-n*(a/n-1);
}

ZZ modulo_Z_R(ZZ a,ZZ n){
    if(a>=0){
        if(a<n){
            return a;}
        return a-(n*(a/n));}
    ZZ c=to_ZZ(a-(n*(a/n)));
    if(c==0)
        return c;
    return a-n*(a/n-1);
}

ZZ val_absoluto_ZZ(ZZ a){

    if(a<cero_G){
        return a*menos_1_G;
    }
    else{
        return a;
    }
}

ZZ mcd_binario_ZZ(ZZ a,ZZ b){
    ZZ aux=uno_G,t;
    while((a&1)==0&&(b&1)==0){
        a=a/dos_G;
        b=b/dos_G;
        aux=aux*dos_G;
    }
    while (a!=cero_G){
        while((a&1)==0){
            a=a/dos_G;
        }
        while((b&1)==0){
            b=b/dos_G;
        }
        t=(val_absoluto_ZZ(a-b))/dos_G;
        if(a>=b){a = t;}
        else {b = t;}
    }
    return aux*b;
}


ZZ exp_mod_rap_R(ZZ a,ZZ n,ZZ m){

	ZZ exp=to_ZZ("1");
	ZZ dos=to_ZZ("2");
	ZZ x= to_ZZ(modulo_Z_R(a,m));
	while (n>0){
		if (modulo_Z_R(n,dos)!=0) { exp=modulo_Z_R((exp*x),m);}

		x=to_ZZ(modulo_Z_R((x*x),m));
		n=to_ZZ(n/dos);
	}

	return exp;
}

bool millerTest_G(ZZ N, ZZ D){
    ZZ A=RandomBnd(N);
        while(A==cero_G||A==uno_G||A==dos_G){A=RandomBnd(N);}
    ZZ x=exp_mod_rap_R(A,D,N);
    if(x==uno_G||x==N-uno_G){return true;}
    while(D!=N-uno_G){
        x=modulo_Z_R(x*x,N);
        D*=2;
        if(x==uno_G)return false;
        if(x==N-uno_G)return true;
    }
return false;
}
bool isPrime_G(ZZ N){///las iteraciones ya estan definidas
    //if(N<=1||N==4)return false;
    //if(N<=3)return true;
    ZZ D=N-uno_G;
    while((D&1)==0){D/=dos_G;}
    for(int i=0;i<10;i++){
        if(millerTest_G(N,D)==false)return false;
    }
    return true;
}

ZZ Phi_G(ZZ X){
    if(X==uno_G){
        return cero_G;
    }
    if(isPrime_G(X)==true){
        return X-uno_G;
    }
    else{
        ZZ res=uno_G;
        for(ZZ i=to_ZZ("2");i<=X;i++){
            ZZ aux_num=cero_G;
            ZZ aux_res;
            long aux_pot=0;
                while(modulo_Z_R(X,i)==cero_G){
                aux_num=i;
                aux_pot++;
                X/=i;
                }
            if(aux_num!=0){
                aux_res=power(aux_num,aux_pot)-power(aux_num,aux_pot-1);
                res*=aux_res;
            }
        }
    return res;
    }
}

ZZ exp_teoremas(ZZ A,ZZ B,ZZ P){
    if(/*isPrime(P)==true&&*/modulo_Z_R(A,P)!=0){///aplicando teorema pequeño de fermat primera version
        if((P-1)<B){
        ZZ aux=modulo_Z_R(B,P-1);
            return exp_mod_rap_R(A,aux,P);
        }
        if(modulo_Z_R(B,P-1)==cero_G){
            return uno_G;
        }
    }
    /*if(A<P){///aplicando teorema de euler segunda version
        ZZ Phi_P=Phi(P)+uno;
        if(Phi_P<B){
            ZZ aux=modulo_Z(B,Phi_P);
            return modulo_Z(A*exp_mod_rap(A,aux,P),P);
        }
        if(Phi_P==B)return A;
    }*/
    return exp_mod_rap_R(A,B,P);
}


ZZ inversa_G(ZZ a, ZZ b){
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

ZZ inversa_teoremas(ZZ A,ZZ P){
    //if(/*isPrime(P)==true&&*/modulo_Z(A,P)!=0){///aplicando teorema pequeño de fermat
      /*  return exp_mod_rap(A,P-dos,P);
    }*/
    if(mcd_binario_ZZ(P,A)==uno_G){///aplicando teorema de euler
        return exp_mod_rap_R(A,Phi_G(P)-uno_G,P);
    }
    return inversa_G(A,P);
}

/*ZZ euclides_extendido_binario(ZZ x,ZZ y){

    ZZ aux=to_ZZ("1"),u,v,A,B,C,D;
    while((x&1)==0&&(y&1)==0){
        x=x>>1;
        y=y>>1;
        aux=aux<<1;
    }
    u=x;v=y;A=to_ZZ("1");B=to_ZZ("0");C=to_ZZ("0");D=to_ZZ("1");
    while(u!=0)
    {
        if((u&1)==0){
            u=u>>1;
            if(modulo_Z_R(A,dos)==cero&&modulo_Z_R(B,dos)==cero){
                A=A>>1;
                B=B>>1;
            }
            else{
                A=(A+y)/2;
                B=(B-x)/2;
            }
        }
        else{
                if((v&1)==0){
                    v=v>>1;
                    if(modulo_Z_R(C,dos)==cero&&modulo_Z_R(D,dos)==cero){
                        C=C>>1;
                        D=D>>1;
                    }
                    else{
                        C=(C+y)/2;
                        D=(D-x)/2;
                    }
                }
            }
    if(u>=v){
        u=u-v;
        A=A-C;
        B=B-D;
    }
    else{
        v=v-u;
        C=C-A;
        D=D-B;
    }
   }
return C*aux;
}
*/
int str_int(string aux){
    int num;
    num=atoi(aux.c_str());
    return num;
}

char operar_bit(char a,char b){
    string bit1,bit2;
    bit1=a;
    bit2=b;
    int bit_1,bit_2,sum_bit;
    string aux_bit;
    stringstream stream;
    bit_1=str_int(bit1);
    bit_2=str_int(bit2);
    sum_bit=modulo_G(bit_1+bit_2,2);
    stream<<sum_bit;
    aux_bit=stream.str();
    char ress;
    ress=aux_bit[0];
    return ress;
}

/*string bit_str(bitset<10> n){
    stringstream b;
    b<<n;
    return b.str();
}

string bit_str_5(bitset<5> n){
    stringstream b;
    b<<n;
    return b.str();
}*/



ZZ conv_bin_num(string a){
    ZZ res;
    ZZ dos=to_ZZ("2");
    int tamano=a.size();
    int aux_1=tamano-1;
    ZZ num=to_ZZ("0");
    for(long x=0;x<tamano;x++){
    if(a[aux_1]=='1'){
        num=to_ZZ(num+power(dos,x));
    }
    aux_1--;
    }
    res=num;
    return res;
}


ZZ generar_aleatorio(int N_bits,int tam_sem,int T_bloques){
    int aleatorio;
    aleatorio=rand()%10000;
    string semilla;
    bitset<10>binario(aleatorio);
    string temp = binario.to_string<char,std::string::traits_type,std::string::allocator_type>();
    semilla=temp;
    //cout<<semilla<<endl;

    char bit_1s,bit_2s;
    for(int i=tam_sem;i<N_bits;i++){
        bit_1s=semilla[i];
        bit_2s=semilla[i+1];
        semilla+=operar_bit(bit_1s,bit_2s);
    }
    //cout<<semilla<<endl;

    int guardar_tam_semilla=semilla.size();
    while(modulo_G(semilla.size(),T_bloques)!=0){semilla+="0";}
    //cout<<semilla<<endl;

/*    vector<bitset<5> >aux;
    int bucle=semilla.size()/T_bloques;
    if(modulo(semilla.size(),T_bloques)!=0){
        bucle++;
    }
    int aux_num=0,aux_num_2=0;
    for(int x=0;x<bucle;x++){
        string g_semilla;
        for(int y=0;y<T_bloques;y++){
            g_semilla+=semilla[y+aux_num_2];
            aux_num++;
        }
        aux_num_2=aux_num;
        //cout<<g_semilla<<",";
        bitset<5>aux_semilla;
        int aux_it=g_semilla.size()-1;
        for(int i=0;i<g_semilla.size();i++){
            if(g_semilla[aux_it]=='1'){aux_semilla[i]=1;}
            else{aux_semilla[i]=0;}
            aux_it--;
        }
        //int bit_g;
        //bit_g=str_int(g_semilla);
        //cout<<bit_g<<",";

        aux.push_back(aux_semilla);
    }
    /*cout<<endl;
    for(int x=0;x<aux.size();x++){
        cout<<aux[x]<<endl;
    }


    for(int i=0;i<10;i++){
    int rand_P=rand()%T_bloques;
    int iterador=0;
    vector<bitset<5> >aux_g;
        for(int x=0;x<aux.size();x++){
        bitset<5>aux_corrimiento;
        bitset<5>aux_operar;
        if(iterador==0){
            aux_corrimiento=aux[x];
            aux_operar=aux[x];
            string operar=bit_str_5(aux_operar);
            int aumento_bit=operar_bit(operar[rand_P],operar[0]);
            aux_corrimiento=aux_corrimiento<<1;
            if(aumento_bit=='1'){
                aux_corrimiento[0]=1;
            }
            else{aux_corrimiento[0]=0;}
            aux_g.push_back(aux_corrimiento);
            iterador=1;
        }
        else{
            aux_corrimiento=aux[x];
            aux_operar=aux[x];
            string operar=bit_str_5(aux_operar);
            int aumento_bit=operar_bit(operar[rand_P],operar[4]);
            aux_corrimiento=aux_corrimiento>>1;
            if(aumento_bit=='1'){
                aux_corrimiento[4]=1;
            }
            else{aux_corrimiento[4]=0;}
            aux_g.push_back(aux_corrimiento);
            iterador=0;
        }
        }
    aux=aux_g;
    }
    /*cout<<endl;
    for(int x=0;x<aux.size();x++){
        cout<<aux[x]<<endl;
    }
    string ress;
    for(int x=0;x<aux.size();x++){
        bitset<5>aux_bloques;
        aux_bloques=aux[0];
        string aux_res=bit_str_5(aux_bloques);
        ress+=aux_res;
    }
*/
    ///separa en bloques
    vector<vector<char> >bloques;
    int aux_num=0,aux_num_2=0;
    for(int x=0;x<semilla.size()/T_bloques;x++){
        vector<char>aux;
        for(int y=0;y<T_bloques;y++){
            aux.push_back(semilla[y+aux_num_2]);
            aux_num++;
        }
        aux_num_2=aux_num;
        bloques.push_back(aux);
    }
    ///...................

    //out<<endl;

    for(int i=0;i<10;i++){
    int rand_P=rand()%T_bloques;
    vector<char>g_blo1;
    vector<char>g_blo2;
    vector<vector<char> >bloques_aux;
    for(int x=0;x<bloques.size();x=x+2){
        g_blo1=bloques[x];
        g_blo2=bloques[x+1];
        char g_bit1=g_blo1[0];
        char g_bit2=g_blo2[T_bloques];
        char g_bit_aux1=g_blo1[rand_P];
        char g_bit_aux2=g_blo2[rand_P];
        ///corrimiento izquierda
        g_blo1.push_back(operar_bit(g_bit1,g_bit_aux1));
        vector<char>aux_b_1;
        for(int i=1;i<g_blo1.size();i++){
            aux_b_1.push_back(g_blo1[i]);
        }
        g_blo1=aux_b_1;
        ///.....
        ///corrimiento derecha
        g_blo2.pop_back();
        vector<char>aux_b_2;
        aux_b_2.push_back(operar_bit(g_bit2,g_bit_aux2));
        for(int i=0;i<g_blo2.size();i++){
            aux_b_2.push_back(g_blo2[i]);
        }
        g_blo2=aux_b_2;
        ///.....
        bloques_aux.push_back(g_blo1);
        bloques_aux.push_back(g_blo2);
    }
    bloques=bloques_aux;
    bloques_aux.clear();
    }

    string ress_bits;
    for(int i=0;i<bloques.size();i++){
        vector<char>a=bloques[i];
        for(int z=0;z<a.size();z++){
                ress_bits+=a[z];
        }
    }
    //cout<<ress_bits<<endl;

    string ress_semilla;
    for(int i=0;i<guardar_tam_semilla;i++){
        ress_semilla+=ress_bits[i];
    }
    if(ress_semilla[ress_semilla.size()-1]=='0'){
        ress_semilla[ress_semilla.size()-1]='1';
    }
    //cout<<ress_semilla;
    return conv_bin_num(ress_semilla);
}

std::string numberToString_R(const ZZ &num)
{
    std::stringstream buffer;
    buffer << num;
    return buffer.str();
}

ZZ numberToZZ_R(string palabra){
    ZZ num(INIT_VAL,palabra.c_str());
    return num;
}

/*string transformar_mensaje(string mensaje,string alfabeto){
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
}*/

int tamano_bloques_G(ZZ num){
    string aux=numberToString_R(num);
    int tam_bloques=aux.size();
    return tam_bloques;
}

string aumentar_basura_G(string mensaje,int tam_bloques){
    string aumentar="23";
    while(modulo_G(mensaje.size(),tam_bloques)!=0){
        mensaje=mensaje+aumentar;
    }
    return mensaje;
}

string cifrar_mensaje(string mensaje,ZZ E,ZZ N,ZZ D,ZZ N_P){
    string encriptado;
    int tam_bloques,num_bucle;
    vector<ZZ>bloques;
    vector<string>bloques_exponenciacion;

    //mensaje=transformar_mensaje(mensaje,alfabeto);
    tam_bloques=tamano_bloques_G(N_P)-1;
    mensaje=aumentar_basura_G(mensaje,tam_bloques);
    num_bucle=mensaje.size()/tam_bloques;

    int aux_num=0,aux_num_2=0;
    for(int x=0;x<num_bucle;x++){
        string aux;
        for(int i=0;i<tam_bloques;i++){
            aux+=mensaje[i+aux_num_2];
            aux_num++;
        }
    aux_num_2=aux_num;
    bloques.push_back(numberToZZ_R(aux));
    }

    for(int i=0;i<num_bucle;i++){
        ZZ aux_exp;
        //ZZ aux_ress=exp_mod_rap_R(bloques[i],D,N_P);
        aux_exp=exp_mod_rap_R(bloques[i],E,N);
        //cout<<aux_exp<<endl;
        string palabra=numberToString_R(aux_exp);
        bloques_exponenciacion.push_back(palabra);
    }

    tam_bloques++;
    string aumentar_cero="0";
    for(int i=0;i<num_bucle;i++){
        string aumentador;
        aumentador=bloques_exponenciacion[i];
        while(aumentador.size()!=tam_bloques){
            aumentador=aumentar_cero+aumentador;
        }
        encriptado+=aumentador;
    }
    return encriptado;
}

ZZ resto_chino(ZZ mensaje,ZZ DP,ZZ DQ,ZZ P,ZZ Q){
    ZZ P_1,P_2,P_1_aux,P_2_aux,Q_1,Q_2,A_1,A_2,D_0;
    ZZ P_aux=P*Q;
    P_1=P_aux/P;
    P_2=P_aux/Q;

        P_1_aux=modulo_Z_R(P_1,P);
        P_2_aux=modulo_Z_R(P_2,Q);

    Q_1=inversa_teoremas(P_1_aux,P);
    Q_2=inversa_teoremas(P_2_aux,Q);

    A_1=exp_teoremas(mensaje,DP,P);
    A_2=exp_teoremas(mensaje,DQ,Q);

    D_0=modulo_Z_R((A_1*P_1*Q_1)+(A_2*P_2*Q_2),P_aux);

    return D_0;
}


vector<ZZ> descifrar_mensaje(string mensaje,ZZ D,ZZ N,ZZ P,ZZ Q,ZZ E_P,ZZ N_P){
    vector<ZZ>acumulable;
    string cero="0";
    int tam_bloques=tamano_bloques_G(N);
    int bucle=mensaje.size()/tam_bloques;
    int aux_num_1=0,aux_num_2=0;
    for(int i=0;i<bucle;i++){
        string aux;
        for(int x=0;x<tam_bloques;x++){
            aux+=mensaje[x+aux_num_2];
            aux_num_1++;
        }
        aux_num_2=aux_num_1;
        acumulable.push_back(numberToZZ_R(aux));
    }
    vector<ZZ>bloques_aum;
    ZZ DP=modulo_Z_R(D,P-uno_G);
    ZZ DQ=modulo_Z_R(D,Q-uno_G);
    for(int i=0;i<bucle;i++){
        ZZ aux_exp=resto_chino(acumulable[i],DP,DQ,P,Q);
        //ZZ aux_exp=exp_mod_rap_R(aux_exp_1,E_P,N_P);
        string palabra=numberToString_R(aux_exp);
            while(palabra.size()!=tam_bloques-1){
                palabra=cero+palabra;
            }
    bloques_aum.push_back(numberToZZ_R(palabra));
    }

    return bloques_aum;
}

ZZ generar_num_primo(int tam_bits){
int aux_bucle=1;
ZZ e;
srand(time(NULL));
while(aux_bucle==1){
    e=generar_aleatorio(tam_bits,5,5);
    while(modulo_Z_R(e,cinco)==cero_G||e==uno_G){e=generar_aleatorio(tam_bits,5,5);}
    //cout<<e<<endl;
    if(isPrime_G(e)==true){aux_bucle=0;}
    }
return e;
}

bool prov_val_E(ZZ x,ZZ N){
    if(x>1&&x<N&&mcd_binario_ZZ(N,x)==1)
    {
        return true;
    }
    else{
        return false;
    }
}

ZZ generar_valor_E(ZZ Phi_N,int tam_bits){
int aux_bucle=1;
ZZ random;
srand(time(NULL));
while(aux_bucle==1){
    //random=RandomBits_ZZ(tam_bits);
    random=generar_aleatorio(tam_bits,5,5);
        if(prov_val_E(random,Phi_N)==1){aux_bucle=0;}
    }
return random;
}


CRubrica::CRubrica(int tam_bits)
{
    int aux_bucle_2=1;
    //P=RandomPrime_ZZ(tam_bits);
    P=generar_num_primo(tam_bits);
    while(aux_bucle_2==1){
        //Q=RandomPrime_ZZ(tam_bits);
        Q=generar_num_primo(tam_bits);
            if(P!=Q){aux_bucle_2=0;}
            }
    N=to_ZZ(P*Q);
    Phi_N=(P-uno_G)*(Q-uno_G);
    E=generar_valor_E(Phi_N,tam_bits);
    D=inversa_G(E,Phi_N);

    cout<<endl<<endl;
    cout<<"CLAVE PUBLICA: <"<<E<<","<<N<<">"<<endl;
    cout<<"CLAVE PRIVADA: <"<<D<<","<<N<<">"<<endl;

    string guardar_aux1="E:  ";
    string guardar_aux3="N:  ";
    ofstream fs("claves_firma.txt");
    fs <<guardar_aux1<<endl;
    fs << E << endl;
    fs <<guardar_aux3<<endl;
    fs << N << endl;
    fs.close();
}

string CRubrica::Firma_encriptado(ZZ E_publica,ZZ N_publica,string mensaje){
    string mensaje_encriptado;
    cout<<"MENSAJE A CIFRAR RSA: "<<mensaje<<endl;
    mensaje_encriptado=cifrar_mensaje(mensaje,E_publica,N_publica,D,N);
    cout<<endl<<"CIFRADO FIRMA RSA: "<<mensaje_encriptado<<endl;
    return mensaje_encriptado;
}

vector<ZZ> CRubrica::Firma_desencriptado(ZZ E_publica,ZZ N_publica,string mensaje){
    vector<ZZ> mensaje_descencriptado;
    cout<<"MENSAJE A DESENCRIPTAR RSA: "<<mensaje<<endl<<endl;
    mensaje_descencriptado=descifrar_mensaje(mensaje,D,N,P,Q,E_publica,N_publica);
    cout<<"MENSAJE DESENCRIPTADO RSA: "<<endl;
    for(int i=0;i<mensaje_descencriptado.size();i++){cout<<mensaje_descencriptado[i];}
    return mensaje_descencriptado;
}

CRubrica::~CRubrica()
{
    //dtor
}
