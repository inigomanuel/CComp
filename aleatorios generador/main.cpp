#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <bitset>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>

using namespace std;


ZZ cero=to_ZZ("0");
ZZ menos_1=to_ZZ("-1");
ZZ uno=to_ZZ("1");
ZZ dos=to_ZZ("2");
ZZ cinco=to_ZZ("5");


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
string bit_str(bitset<10> n){
    stringstream b;
    b<<n;
    return b.str();
}

string bit_str_5(bitset<5> n){
    stringstream b;
    b<<n;
    return b.str();
}

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
    bit_1=atoi(bit1.c_str());
    bit_2=atoi(bit2.c_str());
    sum_bit=modulo(bit_1+bit_2,2);
    stream<<sum_bit;
    aux_bit=stream.str();
    char ress;
    ress=aux_bit[0];
    return ress;
}
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

bool millerTest(ZZ N, ZZ D){
    ZZ A=RandomBnd(N);
        while(A==cero||A==uno||A==dos){A=RandomBnd(N);}
    ZZ x=exp_mod_rap(A,D,N);
    if(x==uno||x==N-uno){return true;}
    while(D!=N-uno){
        x=modulo_Z(x*x,N);
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

ZZ generar_aleatorio(int N_bits,int tam_sem,int T_bloques){

    int aleatorio;
    aleatorio=rand()%100000;
    bitset<10>binario(aleatorio);
    string semilla = bit_str(binario);
    //cout<<semilla<<endl;

    char bit_1s,bit_2s;
    for(int i=tam_sem;i<N_bits;i++){
        bit_1s=semilla[i];
        bit_2s=semilla[i+1];
        semilla+=operar_bit(bit_1s,bit_2s);
    }
    //cout<<semilla<<endl;
    int guardar_tam_semilla=semilla.size();
    while(modulo(semilla.size(),T_bloques)!=0){semilla+="1";}
    vector<bitset<5> >aux;
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
    }*/


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
    }*/
    string ress;
    for(int x=0;x<aux.size();x++){
        bitset<5>aux_bloques;
        aux_bloques=aux[0];
        string aux_res=bit_str_5(aux_bloques);
        ress+=aux_res;
    }
    string ress_semilla;
    for(int i=0;i<guardar_tam_semilla;i++){
        ress_semilla+=ress[i];
    }
    //cout<<ress<<endl;
    if(ress[ress.size()-1]=='0'){
        ress[ress.size()-1]='1';
    }
    return conv_bin_num(ress);
    //int guardar_tam_semilla=semilla.size();
}

ZZ generar_num_primo(int tam_bits){
int aux_bucle=1;
ZZ e;
srand(time(NULL));
while(aux_bucle==1){
    e=generar_aleatorio(tam_bits,5,5);
    cout<<e<<endl;
    while(modulo_Z(e,cinco)==cero||e==uno){e=generar_aleatorio(tam_bits,5,5);}
    //cout<<e<<endl;
    if(isPrime(e)==true){aux_bucle=0;
    cout<<"PRIMO ES: "<<e<<endl;}
    }
return e;
}


int main()
{
   generar_num_primo(512);
}
