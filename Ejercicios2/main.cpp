
#include <iostream>
using namespace std;
//1
float convertir_millas(float milla){
    float KM;
    KM = milla*1.60934;
    return KM;
}
//2
void tabla_termometro(){
    double cel;
    for (int fahr=0;fahr<=300;fahr=fahr+20){
        cel=(fahr-32)*(5.0/9.0);
        cout<<fahr<<" "<<cel<<endl;
    }
}
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
//4
void potencia(int base, int exponente){
    int temp;
    temp=base;
    for(int i=0;i<exponente-1;i++){
        base=base*temp;
    }
    cout<<"El resultado es: "<< base <<endl;
}
//5
void numeros_en_palabras(int numero){
    if(numero<0){
        cout<<"El numero es negativo, no es permitido "<<endl;
    }else
        if(numero==0){
            cout<<"El numero es: "<<"cero"<<endl;
        }else
            if(numero==1){
                cout<<"El numero es: "<<"uno"<<endl;
            }else
                if(numero==2){
                    cout<<"El numero es: "<<"dos"<<endl;
                }else
                    if(numero==3){
                        cout<<"El numero es: "<<"tres"<<endl;
                    }else
                        if(numero==4){
                            cout<<"El numero es: "<<"cuatro"<<endl;
                        }else
                            if(numero==5){
                                cout<<"El numero es: "<<"cinco"<<endl;
                            }else
                                if(numero==6){
                                    cout<<"El numero es: "<<"seis"<<endl;
                                }else
                                    if(numero==7){
                                        cout<<"El numero es: "<<"siete"<<endl;
                                    }else
                                        if(numero==8){
                                            cout<<"El numero es: "<<"ocho"<<endl;
                                        }else
                                            if(numero==9){
                                                cout<<"El numero es: "<<"nueve"<<endl;
                                            }
}
//6
void operaciones(int numero1, int numero2,string x){
    string a;
    a="+";
    string b;
    b="-";
    string c;
    c="*";
    string d;
    d="/";
    int temp;
    if(x==a){
        temp= numero1 + numero2;
        cout<<"EL resultado es: "<<temp<<endl;
    }else
        if(x==b){
            temp= numero1 - numero2;
            cout<<"EL resultado es: "<<temp<<endl;
        }else
            if(x==c){
                temp= numero1 * numero2;
                cout<<"EL resultado es: "<<temp<<endl;
            }else
                if(x==d){
                    temp= numero1 / numero2;
                    cout<<"EL resultado es: "<<temp<<endl;
                }
}
//7
void cambio_referencia(int &numero1, int &numero2){
    int temp = numero1;
    numero1=numero2;
    numero2=temp;
    cout<<"El resultado del intercambio es: "<<endl;
    cout<<numero1<<endl;
    cout<<numero2<<endl;
}
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
//12
void invertir(int arr[], const int numero_de_array)
{
    int temp;
    for (int i=0;i<numero_de_array/2; i++){
        temp=arr[i];
        arr[i]=arr[numero_de_array-i-1];
        arr[numero_de_array-i-1]=temp;
    }
}
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
//14
int suma_recursiva(int arr[], int a, int b){
    if(a==b)
        return 0;
    else
        return arr[a]+suma_recursiva(arr,a+1,b);
}
//15
string palindromo(string pal)
{
    string palabra1;
    for(int i = pal.size()-1; i>=0; i--)
        palabra1 += pal[i];
    return palabra1;
}
int main()
{
/*
//1.
    int milla;
    cout<<"Ingrese el numero de millas que desee convertir: "<<endl;
    cin >> milla;
    cout<<"La conversion de "<< milla << " millas a kilometros es: " << convertir_millas(milla) <<endl;
//2.
    tabla_termometro();
//3
    int numero;
    cout<<"Ingrese un numero para ser evaluado: "<<endl;
    cin >> numero;
    par_o_impar(numero);
//4
    int base,exponente;
    cout<<"Ingrese la base: "<<endl;
    cin >> base;
    cout<<"Ingrese el exponente: "<<endl;
    cin >> exponente;
    potencia(base,exponente);
//5
    int numero;
    cout<<"Ingrese el numero de su preferencia: "<<endl;
    cin >> numero;
    numeros_en_palabras(numero);
//6
    int numero1,numero2;
    string operador;
    cout<<"Ingrese el operador: "<<endl;
    cin >> operador;
    cout<<"Ingrese el numero de su preferencia: "<<endl;
    cin >> numero1;string a;
    a="+";
    string b;
    b="+";
    string c;
    c="+";
    string d;
    d="+";
    cout<<"Ingrese otro numero de su preferencia: "<<endl;
    cin >> numero2;
    operaciones (numero1,numero2,operador);
//7
    int numero1,numero2;
    cout<<"Ingrese el numero de su preferencia: "<<endl;
    cin >> numero1;
    cout<<"Ingrese otro numero de su preferencia: "<<endl;
    cin >> numero2;
    cambio_referencia(numero1, numero2);
//8
    int numero1,numero2;
    cout<<"Ingrese el numero de su preferencia: "<<endl;
    cin >> numero1;
    cout<<"Ingrese otro numero de su preferencia: "<<endl;
    cin >> numero2;
    int *ptr1=&numero1;
    int *ptr2=&numero2;
    cambio_punteros(ptr1,ptr2);
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
//12
    int numero_de_array;
    cout<<"Ingrese el tamano del array que desee: "<<endl;
    cin >> numero_de_array;
    int arr[numero_de_array];
    cout<<"Ingrese los numeros dentro del array: "<<endl;
    for(int i=0;i<numero_de_array;i++){
        cin >> arr[i];
    }
    cout<<"El arreglo invertido es: "<<endl;
    invertir(arr,numero_de_array);
    for(int i=0;i<numero_de_array;i++){
        cout<<arr[i]<<endl;
    }
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
//15
    string palabra,invertido;
    cout<<"Ingrese una palabra: "<<endl;
    cin >> palabra;
    invertido = palindromo(palabra);
    cout<<invertido<<endl;
    if (palabra==invertido)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
*/
}

