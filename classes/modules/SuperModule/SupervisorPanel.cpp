#include "SupervisorPanel.h"
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

COORD superCoord = {0,0};

void supGotoxy(int x, int y){
	superCoord.X = x;
	superCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),superCoord);
}


SupervisorPanel::SupervisorPanel(){

}

void SupervisorPanel::displayPanel(){
	
    system("CLS");	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                            BIBLIOTECA EL PORVENIR                   Bienvenido:                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Bienvenido nuevamente estimado Supervisor                                                                           |" << endl;
	cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| 1) Aperturar Modulo de Inventario                                                                                   |" << endl;
	cout << "| 2) Aperturar Modulo de Masivos                                                                                      |" << endl;
	cout << "| 3) Aperturar Modulo de Administracion de Usuarios                                                                   |" << endl;
	cout << "| 4) Cerrar sesion                                                                                                    |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Su opcion:                                                                                                          |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	
	setEnvironmentVariables();
	
	supGotoxy(13,15);
	cin >> option;

    switch(option){

        case 1:{
            InventoryModule im = InventoryModule();
            im.displayInventoryModuleSupervisor();
            break;
        }

        case 2:{
            MasiveModule mm = MasiveModule();
            mm.displayMasiveModuleSupervisor();
            break;
        }

        case 3:{
            UserModule sm = UserModule();
            sm.displayModuleSupervisor();
            break;
        }
        
        case 4:{
            exit(0);
            break;
        }

    }
}

void SupervisorPanel::setlogedUser(string user){
	logedUser = user;
}

string SupervisorPanel::getlogedUser(){
	return logedUser;
}

void SupervisorPanel::setEnvironmentVariables(){
	supGotoxy(98,1);
	cout<<SupervisorPanel::getlogedUser();
}
