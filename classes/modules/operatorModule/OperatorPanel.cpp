#include "OperatorPanel.h"
#include "../Adminmodule/AdminPanel.h"
#include "../AdminModule/subModules/inventoryModule/InventoryModule.h"
#include "../AdminModule/subModules/usersModule/UserModule.h"
#include "../AdminModule/subModules/masiveModule/MasiveModule.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

COORD operCoord = {0,0};

void operGotoxy(int x, int y){
	operCoord.X = x;
	operCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),operCoord);
}


OperatorPanel::OperatorPanel(){

}

void OperatorPanel::displayPanel(){
	
    system("CLS");	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                            BIBLIOTECA EL PORVENIR                   Bienvenido:                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Bienvenido nuevamente estimado Operador                                                                             |" << endl;
	cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| 1) Aperturar Modulo de Inventario                                                                                   |" << endl;
	cout << "| 2) Aperturar Modulo de prestamos                                                                                    |" << endl;
    cout << "| 3) Cerrar sesion                                                                                                    |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Su opcion:                                                                                                          |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	
	setEnvironmentVariables();
	
	operGotoxy(13,15);
	cin >> option;

    switch(option){

        case 1:{
            InventoryModule im = InventoryModule();
            im.displayInventoryModuleOperator();
            break;
        }

        case 2:{
            MasiveModule mm = MasiveModule();
            //mm.displayMasiveModuleSupervisor();
            break;
        }

        case 3:{
            exit(0);
            break;
        }

    }
}

void OperatorPanel::setlogedUser(string user){
	logedUser = user;
}

string OperatorPanel::getlogedUser(){
	return logedUser;
}

void OperatorPanel::setEnvironmentVariables(){
	operGotoxy(98,1);
	cout<<OperatorPanel::getlogedUser();
}

