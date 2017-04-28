#include <iostream>

using namespace std;
//4
void potencia(int base, int exponente){
    int temp;
    temp=base;
    for(int i=0;i<exponente-1;i++){
        base=base*temp;
    }
    cout<<"El resultado es: "<< base <<endl;
}
int main()
{
    //4
    int base,exponente;
    cout<<"Ingrese la base: "<<endl;
    cin >> base;
    cout<<"Ingrese el exponente: "<<endl;
    cin >> exponente;
    potencia(base,exponente);
    return 0;
}
