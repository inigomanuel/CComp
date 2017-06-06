#include "Conserje.h"

Conserje::Conserje(): Persona(),salario(0){}
Conserje::Conserje(char *nombre1,char *sexo1,Birthday birthday1, int salario1): Persona(nombre1,sexo1,birthday1),salario(salario1){}

int Conserje::getSalario()
{
    return salario;
}
void Conserje::saludar()
{
    cout <<"Hola soy un Conserje" <<endl;
    cout <<"Mi Nombre es: "<<nombre<<endl;
    cout <<"Mi Sexo es: "<<sexo<<endl;
    cout <<"Mi Salario es: "<<salario<<"$ al mes "<<endl;
}
int Conserje::edadPersona()
{
    int EsteAnio = 2017;
    int EsteMes = 6;
    int EsteDia = 6;
    int edad = EsteAnio - birthday.getYear();
    if (birthday.getMonth() > EsteMes){
        edad=edad-1;
    }
    else {
        if (birthday.getMonth() == EsteMes){
            if (birthday.getDay() > EsteDia){
                edad = edad -1;
            }
        }
    }
    return edad;
}
