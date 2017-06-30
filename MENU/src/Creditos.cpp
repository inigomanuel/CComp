#include "Creditos.h"
#include <Menu.h>
#include <iostream>
#include <windows.h>

using namespace std;

Creditos::Creditos()
{
    cout<<" "<<endl;
    cout<<" Se agradece a los profesor que hizo posible"<<endl;
    cout<<" la creacion de este videojuego. "<<endl;
    cout<<" "<<endl;
    cout<<" Alvaro Henry Mamani"<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" Lenguaje de Programacion: C++"<<endl;
    cout<<" "<<endl;
    cout<<" Miembros:"<<endl;
    cout<<" Rafael Cano Guitton"<<endl;
    cout<<" Inigo Diez Canseco"<<endl;
    cout<<" "<<endl;;
    cout<<" MMXV. Copyright. "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" Este juego se realizo bajo el consentimiento de "<<endl;
    cout<<" nuestro querido amigo KUBLAY :v"<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"1) Regresar al menu principal "<<endl;
    cout<<"2) Salir del juego "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"Que desea hacer?"<<endl;
    int usuario_creditos=0;
    cin>>usuario_creditos;
    switch (usuario_creditos)
            {
                case 1:
                    system("cls");
                    Menu();
                    break;
                case 2:
                    system("cls");
                    break;
            }
}
