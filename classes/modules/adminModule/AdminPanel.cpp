#include "AdminPanel.h"
#include "subModules/inventoryModule/InventoryModule.h"
#include "subModules/masiveModule/MasiveModule.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

COORD adminCoord = {0,0};

void adminGotoxy(int x, int y){
	adminCoord.X = x;
	adminCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),adminCoord);
}

void AdminPanel::setEnvironmentVariables(){
	adminGotoxy(98,1);
	cout<<AdminPanel::getlogedUser();
}

AdminPanel::AdminPanel(){
	
}

void AdminPanel::displayPanelAdmin(){
	
	
resetPanel:
	system("CLS");	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                            BIBLIOTECA EL PORVENIR                   Bienvenido:                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Bienvenido nuevamente estimado Administrador                                                                        |" << endl;
	cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| 1) Aperturar Modulo de Inventario                                                                                   |" << endl;
	cout << "| 2) Aperturar Modulo de Masivos                                                                                      |" << endl;
	cout << "| 3) Aperturar Modulo de Reporteria                                                                                   |" << endl;
	cout << "| 4) Aperturar Modulo de Administracion de Usuarios                                                                   |" << endl;
	cout << "| 5) Cerrar Sesion                                                                                                    |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Su opcion:                                                                                                          |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	
	setEnvironmentVariables();
	
	adminGotoxy(13,15);
	cin >> option;
	
	switch(option){
		case 1:{
			InventoryModule im = InventoryModule();
			
			im.displayModule();
			break;
		}
		
		case 2:{
			MasiveModule mm = MasiveModule();
			mm.displayModule();
			break;
		}
		
		case 3:{
			break;
		}
		
		case 4:{
			break;
		}
		
		case 5:{
			break;
		}
	}
	
	adminGotoxy(0,17);
	
}


void AdminPanel::setlogedUser(string user){
	logedUser = user;
}

string AdminPanel::getlogedUser(){
	return logedUser;
}

