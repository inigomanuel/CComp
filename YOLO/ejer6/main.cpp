#include <iostream>

using namespace std;
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
int main()
{
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
    return 0;
}
