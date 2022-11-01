#include "MasiveModule.h"
#include "../../../../BinFilesHandler.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

COORD masiveCoord = {0,0};

void masiveGotoxy(int x, int y){
	masiveCoord.X = x;
	masiveCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),masiveCoord);
}

MasiveModule::MasiveModule(){
	
}


void MasiveModule::displayModule(){
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                              BIBLIOTECA EL PORVENIR                                                 |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                MODULO DE MASIVOS                                                    |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Administrador                                                                        |" << endl;
		cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Carga masiva de inventario                                                                                       |" << endl;
		cout << "| 2) Descarga masiva de inventario                                                                                    |" << endl;
		cout << "| 3) Eliminacion Masiva de inventario                                                                                 |" << endl;
		cout << "| 4) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		masiveGotoxy(13,17);
		cin >> parser;


		std::istringstream (parser) >> optionMenu;
		
		BinFilesHandler bfh = BinFilesHandler();
		switch(optionMenu){
			case 1:{
				bfh.masiveBulk();
				masiveGotoxy(13,25);
				break;
			}

			case 2:{
					
				break;
			}
			
			case 3:{
					
				break;
			}
			
			case 4:{
					
				break;
			}
			
			default:{
				displayModule();
				break;
			}
		}
		
	masiveGotoxy(0,30);
}
