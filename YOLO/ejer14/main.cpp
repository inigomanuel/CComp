#include <iostream>

using namespace std;
//14
int suma_recursiva(int arr[], int a, int b){
    if(a==b)
        return 0;
    else
        return arr[a]+suma_recursiva(arr,a+1,b);
}
int main()
{
    //14
    int numero_de_array;
    cout<<"Ingrese el tamano del array que desee: "<<endl;
    cin >> numero_de_array;
    int arr[numero_de_array];
    cout<<"Ingrese los numeros dentro del array: "<<endl;
    for(int i=0;i<numero_de_array;i++){
        cin >> arr[i];
    }
    cout<<"La respuesta de la suma es: "<<suma_recursiva(arr,0,numero_de_array)<<endl;
    return 0;
}
