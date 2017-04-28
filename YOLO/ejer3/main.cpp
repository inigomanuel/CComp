#include <iostream>

using namespace std;
//3
void par_o_impar(int numero){
    if (numero<0){
        cout<<"El numero ingresado es negativo"<<endl;
    }else
        if (numero%2==0)
            cout<<"El numero ingresado es par"<<endl;
        else
            cout<<"El numero ingresado es impar"<<endl;
}
int main()
{
    //3
    int numero;
    cout<<"Ingrese un numero para ser evaluado: "<<endl;
    cin >> numero;
    par_o_impar(numero);
    return 0;
}
