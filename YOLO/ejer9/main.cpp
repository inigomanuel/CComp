#include <iostream>

using namespace std;
//9
void insertion_sort(int arr[],int numero_de_array){
    int temp,j;
    for(int i=0;i<numero_de_array;i++){
        j=i;
        while(j>0 && arr[j]<arr[j-1]){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}
int main()
{
    //9
    int numero_de_array;
    cout<<"Ingrese el tamano del array que desee: "<<endl;
    cin >> numero_de_array;
    int arr[numero_de_array];
    cout<<"Ingrese los numeros del array que desee: "<<endl;
    for(int i=0;i<numero_de_array;i++){
        cin >> arr[i];
    }
    cout<<"El arrays ordenado es: "<<endl;
    insertion_sort(arr,numero_de_array);
    for(int i=0;i<numero_de_array;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
