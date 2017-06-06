#ifndef CONSERJE_H
#define CONSERJE_H
#include "Persona.h"

class Conserje : public Persona
{
    private:
        int salario;
    public:
        Conserje();
        Conserje(char *nombre1,char *sexo1,Birthday birthday1, int salario1);
        int getSalario();
        void saludar();
        int edadPersona();
};

#endif // CONSERJE_H
