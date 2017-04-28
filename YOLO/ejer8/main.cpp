#include <iostream>

using namespace std;
//8
void cambio_punteros(int *ptr1, int *ptr2){
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
    //a=a+b
    //b=a-b
    //a=a-b
    cout<<"El resultado del intercambio es: "<<endl;
    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;
}
int main()
{
    //8
    int numero1,numero2;
    cout<<"Ingrese el numero de su preferencia: "<<endl;
    cin >> numero1;
    cout<<"Ingrese otro numero de su preferencia: "<<endl;
    cin >> numero2;
    int *ptr1=&numero1;
    int *ptr2=&numero2;
    cambio_punteros(ptr1,ptr2);
    return 0;
}
