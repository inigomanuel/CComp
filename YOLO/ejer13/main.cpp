#include <iostream>

using namespace std;
//13
void invertir_con_punteros(int arr[], const int *numero_de_array)
{
    int temp;
    for (int i=0;i<*numero_de_array/2; i++){
        temp=arr[i];
        arr[i]=arr[*numero_de_array-i-1];
        arr[*numero_de_array-i-1]=temp;
    }
}
int main()
{
    //13
    int numero_de_array;
    cout<<"Ingrese el tamano del array que desee: "<<endl;
    cin >> numero_de_array;
    int arr[numero_de_array];
    cout<<"Ingrese los numeros dentro del array: "<<endl;
    for(int i=0;i<numero_de_array;i++){
        cin >> arr[i];
    }
    cout<<"El arreglo invertido es: "<<endl;
    invertir_con_punteros(arr,&numero_de_array);
    for(int i=0;i<numero_de_array;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
