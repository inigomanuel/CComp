#include <iostream>
#include "Persona.h"
#include "Birthday.h"
#include "Gerente.h"
#include "Conserje.h"

using namespace std;

int main()
{
    Birthday Cumple1(1985,3,10);
    Gerente Maria("Maria","Femenino",Cumple1,1500);
    Maria.saludar();
    cout <<"Mi Edad actual es : "<<Maria.edadPersona()<<endl;
    cout <<" "<<endl;
    Birthday Cumple2(1999,7,21);
    Conserje Carlos("Carlos","Masculino",Cumple2,300);
    Carlos.saludar();
    cout <<"Mi Edad actual es : "<<Carlos.edadPersona()<<endl;
    cout <<" "<<endl;
    Birthday Cumple3(1998,4,17);
    Gerente Juan("Juan","Masculino",Cumple3,500);
    Juan.saludar();
    cout <<"Mi Edad actual es : "<<Juan.edadPersona()<<endl;
    cout <<" "<<endl;
    Birthday Cumple4(1993,9,26);
    Conserje Camila("Camila","Femenino",Cumple4,200);
    Camila.saludar();
    cout <<"Mi Edad actual es : "<<Camila.edadPersona()<<endl;
    cout <<" "<<endl;
}
