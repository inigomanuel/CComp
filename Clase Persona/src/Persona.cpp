#include "Persona.h"
#include "Birthday.h"
Persona::Persona()
{
    nombre = NULL;
    sexo = NULL;
    cout <<"Construccion por defecto hecha"<<endl;
}
Persona::Persona(char *nombre1,char *sexo1, Birthday birthday1)
{
    nombre = new char[20];
    this -> nombre = nombre1;
    sexo = new char[20];
    this -> sexo = sexo1;
    this -> birthday = birthday1;
    cout <<"Construccion hecha"<<endl;
}
Persona::~Persona()
{
    delete[] nombre;
    delete[] sexo;
    cout <<"Destruccion de persona hecha "<<endl;
}

int Persona::edadPersona()
{
    int currentyear = 2017;
    int currentmonth = 6;
    int currentday = 6;
    int currentage = currentyear - birthday.getYear();
    if (birthday.getMonth() > currentmonth){
        currentage=currentage-1;
    }
    else {
        if (birthday.getMonth() == currentmonth){
            if (birthday.getDay() > currentday){
                currentage = currentage -1;
            }
        }
    }
    return currentage;
}
