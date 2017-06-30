#include "Instrucciones.h"
#include <Menu.h>
#include <iostream>
#include <windows.h>

using namespace std;

Instrucciones::Instrucciones()
{
    cout<<"1) Movimiento"<<endl;
    cout<<" Para el movimiento use las las flechas (arriba,abajo,izquierda,derecha)"<<endl;
    cout<<" de su teclado para poder movilizar al personaje."<<endl;
    cout<<" "<<endl;
    cout<<"2) Accion"<<endl;
    cout<<" Para poder sacar la espada y atacar a los enemigos, utilice la tecla SAPACE "<<endl;
    cout<<" para acabar con la injusticia y la maldad del pueblo de Kublay."<<endl;
    cout<<" "<<endl;
    cout<<"3) Aceptar"<<endl;
    cout<<" Para acepar las opciones del Menu, presione la tecla ENTER y asi podra "<<endl;
    cout<<" iniciar la gran aventura o tambien podra ver a los programadores detras de"<<endl;
    cout<<" LA LEYENDA DE KUBLAY entre otros contenidos."<<endl;
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
