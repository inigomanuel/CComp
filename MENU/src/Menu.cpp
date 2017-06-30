#include "Menu.h"
#include <Instrucciones.h>
#include <Creditos.h>
#include <Historia.h>
#include <windows.h>
#include <iostream>

using namespace std;

Menu::Menu()
{
    cout<<"                ___    ___     __         __ ___             __            "<<endl;
    cout<<"|    /\\    |   |__ \\ /|__ |\\ ||  \\ /\\    |  ||__    |__/|  ||__)|     /\\ \\ / "<<endl;
    cout<<"|___/__\\   |___|___ | |___| \\||__//__\\   |__/|___   |  \\|__||__)|___ /__\\ |  "<<endl;

    int usuario=0;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"1) Iniciar el Juego"<<endl;
    cout<<"2) Historia"<<endl;
    cout<<"3) Instrucciones"<<endl;
    cout<<"4) Creditos"<<endl;
    cout<<"5) Salir del Juego"<<endl;
    cout<<""<<endl;
    cout<<"Que desea hacer?"<<endl;
    cin>>usuario;
    int m=usuario;
        switch (m)
            {
                case 1:
                    cout<<"Juego Empieza"<<endl;
                    break;
                case 2:
                    system("cls");
                    Historia();
                    break;
                case 3:
                    system("cls");
                    Instrucciones();
                    break;
                case 4:
                    system("cls");
                    Creditos();
                    break;
                case 5:
                    system("cls");
                    break;
            }
}
