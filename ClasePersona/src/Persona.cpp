#include "Persona.h"
#include "Birthday.h"
Persona::Persona()
{
    nombre = NULL;
    sexo = NULL;
}
Persona::Persona(char *nombre1,char *sexo1, Birthday birthday1)
{
    nombre = new char[20];
    this -> nombre = nombre1;
    sexo = new char[20];
    this -> sexo = sexo1;
    this -> birthday = birthday1;
}
Persona::~Persona()
{
    delete[] nombre;
    delete[] sexo;
}

int Persona::edadPersona()
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
