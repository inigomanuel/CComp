#include <iostream>

using namespace std;
void numeros_en_palabras(){
    int x;
    while(x!=-1)
    {
    cout<<"Ingrese un numero"<<endl;
    cin>>x;
    switch(x){
        case 0:
        cout<<"Cero"<<endl;
        break;
        case 1:
        cout<<"Uno"<<endl;
        break;
        case 2:
        cout<<"Dos"<<endl;
        break;
        case 3:
        cout<<"Tres"<<endl;
        break;
        case 4:
        cout<<"Cuatro"<<endl;
        break;
        case 5:break;
        cout<<"Cinco"<<endl;
        break;
        case 6:
        cout<<"Seis"<<endl;
        break;
        case 7:
        cout<<"Siete"<<endl;
        break;
        case 8:
        cout<<"Ocho"<<endl;
        break;
        case 9:
        cout<<"Nueve"<<endl;
        break;
        default:
        cout<<"Numero no permitido"<<endl;
    }
    }
}
int main()
{
//5
    numeros_en_palabras();
    return 0;
}
