#include <iostream>

using namespace std;

int main()
{

//Un programa que solicite datos para calcular el area del circulo
    float radio;
    float a,r;
    cout<<"Hallar el area de un circulo" << endl;
    cout<<"Ingrese el valor del radio: ";
    cin >> radio;
    a=radio*radio;
    r=a*3.14159265359;
    cout<<"El area es: "<< r <<endl;
//Un programa que solicite datos para calcular el area del cuadrado
    int lado;
    int x;
    cout<<"Hallar el area de un cuadrado" << endl;
    cout<<"Ingrese el valor de el lado: ";
    cin >> lado;
    x=lado*lado;
    cout<<"El area es: "<< x <<endl;
//Un programa que solicite datos para calcular el area del rectangulo
    int base;
    int altura;
    int w;
    cout<<"Hallar el area de un rectangulo" << endl;
    cout<<"Ingrese el valor de la base: ";
    cin >> base;
    cout<<"Ingrese el valor de la altura: ";
    cin >> altura;
    w=base*altura;
    cout<<"El area es: "<< w <<endl;
//Un programa que intercambie los valores de mis variables utilizando 3 variables
    int a,b,c;
    cout<<"Ingrese el valor a: ";
    cin >> a;
    cout<<"Ingrese el valor b: ";
    cin >> b;
    c=a;
    a=b;
    b=c;
    cout<<"El valor de a es: " << a <<endl;
    cout<<"El valor de b es: " << b;

//Un programa que intercambie los valores de mis variables utilizando 2 variables
    int x,y;
    cout<<"Ingrese el valor x: ";
    cin >> x;
    cout<<"Ingrese el valor y: ";
    cin >> y;
    x=x+y;
    y=x-y;
    x=x-y;
    cout<<"El valor de x es: " << x <<endl;
    cout<<"El valor de y es: " << y;

//Hacer un programa que solicite dos numeros y evaluar cual es el mayor
    int a,b;
    cout<<"Ingrese el valor de a: " << endl;
    cin >> a;
    cout<<"Ingrese el valor de b: " << endl;
    cin >> b;
    if (a==b)
        cout<<"Los numeros de a y b son iguales: ";
    else;
        if (a<b)
            cout<<"b es mayor que a"<<endl;
        else;
            if (a>b)
                cout<<"a es mayor que b"<<endl;

//Hacer un programa que solicite tres numeros y evaluar cual es el mayor
    int a,b,c;
    cout<<"Ingrese el valor de a: " << endl;
    cin >> a;
    cout<<"Ingrese el valor de b: " << endl;
    cin >> b;
    cout<<"Ingrese el valor de c: " << endl;
    cin >> c;
    if (a>=b){
        if(a>=c)
        cout<<"a es mayor: "<< a << endl;
    }
    else{
        if (b>=c)
            cout<<"b es mayor: "<< b << endl;
        else
            cout<<"c es mayor: "<< c << endl;
    }
    return 0;
}
