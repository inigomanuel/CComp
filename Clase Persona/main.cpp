#include <iostream>
#include "Persona.h"
#include "Birthday.h"
#include "Gerente.h"
#include "Conserje.h"

using namespace std;

int main()
{
    Birthday Cumple4(1985,3,10);
    Gerente Josefina("Josefina","Femenino",Cumple4,1500);
    Josefina.saludar();
    cout <<"Mi edad actual es : "<<Josefina.edadPersona()<<endl;
    Birthday Cumple5(1999,7,21);
    Conserje Pancracio("Pancracio","Masculino",Cumple5,300);
    Pancracio.saludar();
    cout <<"Mi edad actual es : "<<Pancracio.edadPersona()<<endl;

    Birthday Cumple2(1998,4,17);
    Gerente Juanchito("Juanchito","Masculino",Cumple2,500);
    Juanchito.saludar();
    cout <<"Mi edad actual es : "<<Juanchito.edadPersona()<<endl;
    Birthday Cumple3(1993,9,26);
    Conserje Celestia("Celestia","Femenino",Cumple3,500);
    Celestia.saludar();
    cout <<"Mi edad actual es : "<<Celestia.edadPersona()<<endl;
}
