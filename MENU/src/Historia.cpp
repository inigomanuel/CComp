#include "Historia.h"
#include <Menu.h>
#include <iostream>
#include <windows.h>

using namespace std;

Historia::Historia()
{
    cout<<" "<<endl;
    cout<<" En las lejanas llanuras, estaba un joven llamado Kublay,"<<endl;
    cout<<" vivia en un pequeño pueblo invadido de enemigos perversos y gente extraña."<<endl;
    cout<<" "<<endl;
    cout<<" Es un joven muy apuesto :v aunque solo le importa la aventura."<<endl;
    cout<<" "<<endl;
    cout<<" Ahora tienes la posibilidad de ser parte de la historia de este aventurero y"<<endl;
    cout<<" guiarlo en su travesia en busca del secreto de las mil maravillas."<<endl;
    cout<<" "<<endl;
    cout<<" Esta aventura recien inicia. . . "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"1) Regresar al menu principal "<<endl;
    cout<<"2) Salir del juego "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"Que desea hacer?"<<endl;
    int usuario_instrucciones=0;
    cin>>usuario_instrucciones;
    switch (usuario_instrucciones)
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
