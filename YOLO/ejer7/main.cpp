#include <iostream>

using namespace std;
//7
void cambio_referencia(int &numero1, int &numero2){
    int temp = numero1;
    numero1=numero2;
    numero2=temp;
    cout<<"El resultado del intercambio es: "<<endl;
    cout<<numero1<<endl;
    cout<<numero2<<endl;
}
int main()
{
    //7
    int numero1,numero2;
    cout<<"Ingrese el numero de su preferencia: "<<endl;
    cin >> numero1;
    cout<<"Ingrese otro numero de su preferencia: "<<endl;
    cin >> numero2;
    cambio_referencia(numero1, numero2);
    return 0;
}
