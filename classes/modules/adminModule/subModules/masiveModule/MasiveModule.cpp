#include "MasiveModule.h"
#include "../../../../BinFilesHandler.h"
#include "../inventoryModule/InventoryModule.h"
#include "../../AdminPanel.h"
#include "../../../SuperModule/SupervisorPanel.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include<algorithm>

COORD masiveCoord = {0,0};

void masiveGotoxy(int x, int y){
	masiveCoord.X = x;
	masiveCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),masiveCoord);
}

MasiveModule::MasiveModule(){
	
}

void MasiveModule::displayMasiveModuleSupervisor(){
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                              BIBLIOTECA EL PORVENIR                                                 |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                MODULO DE MASIVOS                                                    |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Supervisor                                                                           |" << endl;
		cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Carga masiva de inventario                                                                                       |" << endl;
		cout << "| 2) Descarga masiva de inventario                                                                                    |" << endl;
		cout << "| 3) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
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
		
		switch(optionMenu){
			case 1:{
				masiveUpload(2);
				break;
			}

			case 2:{
				masiveDownload(2);
				break;
			}
			
			case 3:{
				SupervisorPanel sp = SupervisorPanel();
				sp.displayPanel();
				break;
			}
			
			
			default:{
				displayModule();
				break;
			}
		}
	
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
		cout << "| 3) Eliminacion masiva de inventario                                                                                 |" << endl;
		cout << "| 4) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		masiveGotoxy(13,18);
		cin >> parser;


		std::istringstream (parser) >> optionMenu;
		
		switch(optionMenu){
			case 1:{
				masiveUpload(3);
				break;
			}

			case 2:{
				masiveDownload(3);
				break;
			}
			
			case 3:{
				masiveDelete();
				break;
			}
			
			case 4:{
				AdminPanel ap = AdminPanel();
				ap.displayPanelAdmin();
				break;
			}
			
			default:{
				displayModule();
				break;
			}
		}
		
	masiveGotoxy(0,30);
}

void MasiveModule::masiveUpload(int rol){
system("CLS");
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                                BIBLIOTECA EL PORVENIR                                               |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                        MODULO DE MASIVOS CARGA MASIVA DE DATOS                                      |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Bienvenido nuevamente estimado usuario                                                                              |" << endl;
	cout << "| Instrucciones de uso:                                                                                               |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| 1) Se abrira la carpeta en la cual se contiene un template para la carga masiva                                     |" << endl;
	cout << "| 2) Rellene el documento y guardelo en formato CSV                                                                   |" << endl;
	cout << "| 3) Por favor escriba Confirmar en la barra de texto para comenzar la carga masiva                                   |" << endl;
	cout << "| 4) Si dentro del inventario se encuentran registros iguales, a los registro del inventario se les sumara el stock   |" << endl;
	cout << "|    de los elementos cargados en la suma masiva                                                                      |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| x) Si desea regresar al menu y cancelar la carga, escriba en el recuadro de texto 'Cancelar'                        |" << endl;
	cout << "| x) Para confirmar la carga de los datos, por favor escriba 'Confirmar'                                              |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Su opcion:                                                                                                          |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	
	BinFilesHandler bfh = BinFilesHandler();
	bfh.copytemplate();
	
	cin.ignore();
	string opt,opt2;
	
	masiveGotoxy(13,22);
	getline(cin, opt);
	
	std::for_each(opt.begin(), opt.end(), [](char & c){
    c = ::tolower(c);
	});
	
	if(opt == "confirmar"){
		
		if(bfh.masiveBulk()){
			masiveGotoxy(0,22);
			cout << "| Se ha finalizado la carga masiva, por favor escriba 'aceptar' para ser llevado a la ventana de inventarios          |" << endl;			
			masiveGotoxy(0,23);
			cout << "| Su opcion:                                                                                                          |" << endl;	
			masiveGotoxy(0,24);
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;		
			
			masiveGotoxy(13,23);
			getline(cin, opt2);
			
			std::for_each(opt2.begin(), opt2.end(), [](char & c){
		    c = ::tolower(c);
			});
			
			if(opt2 == "aceptar"){
				InventoryModule im = InventoryModule();
				im.displayAllEntrys(rol);
			}else{
				switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
			}
		}else{
			masiveGotoxy(0,22);
			cout << "| Se ha finalizado la carga masiva con errores, por favor escriba 'aceptar' y verifique el archivo por favor          |" << endl;			
			masiveGotoxy(0,23);
			cout << "| Su opcion:                                                                                                          |" << endl;	
			masiveGotoxy(0,24);
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;		
			
			masiveGotoxy(13,23);
			getline(cin, opt2);
			
			std::for_each(opt2.begin(), opt2.end(), [](char & c){
		    c = ::tolower(c);
			});
			
			if(opt2 == "aceptar"){
				switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
			}else{
				switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
			}
		}	
	}else{
		switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
	}
		
}

void MasiveModule::masiveDownload(int rol){
	system("CLS");
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                                BIBLIOTECA EL PORVENIR                                               |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                        MODULO DE MASIVOS DESCARGA MASIVA DE DATOS                                   |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Bienvenido nuevamente estimado                                                                                      |" << endl;
	cout << "| Instrucciones de uso:                                                                                               |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| 1) Se realizara un backup del inventario actual en formato CSV                                                      |" << endl;
	cout << "| 2) Se procesara el backup y se alojara en la carpeta downloads del programa                                         |" << endl;
	cout << "| 3) Al finalizar se abrira la carpeta en la que se ha realizado la exportacion del inventario                        |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| x) Si desea regresar al menu y cancelar la descarga, escriba en el recuadro de texto 'Cancelar'                     |" << endl;
	cout << "| x) Para confirmar la descarga de los datos, por favor escriba 'Confirmar'                                           |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Su opcion:                                                                                                          |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	
	BinFilesHandler bfh = BinFilesHandler();
	
	cin.ignore();
	string opt,opt2;
	
	masiveGotoxy(13,22);
	getline(cin, opt);
	
	std::for_each(opt.begin(), opt.end(), [](char & c){
    c = ::tolower(c);
	});
	
	if(opt == "confirmar"){
		
		if(bfh.downloadInventory()){
			masiveGotoxy(0,22);
			cout << "| Se ha finalizado la descarga masiva, por favor escriba 'aceptar' para ser llevado a la ventana principal            |" << endl;			
			masiveGotoxy(0,23);
			cout << "| Su opcion:                                                                                                          |" << endl;	
			masiveGotoxy(0,24);
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;		
			
			masiveGotoxy(13,23);
			getline(cin, opt2);
			
			std::for_each(opt2.begin(), opt2.end(), [](char & c){
		    c = ::tolower(c);
			});
			
			if(opt2 == "aceptar"){
				InventoryModule im = InventoryModule();
				im.displayAllEntrys(rol);
			}else{
				switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
			}
		}else{
			masiveGotoxy(0,22);
			cout << "| Se ha finalizado la descarga masiva con errores, por favor escriba 'aceptar' y contacte al administrador            |" << endl;			
			masiveGotoxy(0,23);
			cout << "| Su opcion:                                                                                                          |" << endl;	
			masiveGotoxy(0,24);
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;		
			
			masiveGotoxy(13,23);
			getline(cin, opt2);
			
			std::for_each(opt2.begin(), opt2.end(), [](char & c){
		    c = ::tolower(c);
			});
			
			if(opt2 == "aceptar"){
				switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
			}else{
				switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
			}
		}	
	}else{
		switch(rol){
					case 2:{
						displayMasiveModuleSupervisor();
						break;
					}
					case 3:{
						displayModule();	
						break;
					}
				}
	}
}

void MasiveModule::masiveDelete(){
	system("CLS");
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                                BIBLIOTECA EL PORVENIR                                               |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                        MODULO DE MASIVOS ELIMINACION MASIVA DE DATOS                                |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Bienvenido nuevamente estimado                                                                                      |" << endl;
	cout << "| Instrucciones de uso:                                                                                               |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| 1) Se realizara procedere a eliminar todos los productos sin stock del inventario actual                            |" << endl;
	cout << "| 2) Media vez procesado el inventario y eliminado los productos sin stock, esto para eliminar basura del stock, por  |" << endl;
	cout << "|    defecto los productos sin stock no son visualizados en pantalla para evitar que se intenten vender o alquilar.   |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "| x) Si desea regresar al menu y cancelar la eliminacion, escriba en el recuadro de texto 'Cancelar'                  |" << endl;
	cout << "| x) Para confirmar la eliminacion de los datos, por favor escriba 'Confirmar'                                        |" << endl;
	cout << "|                                                                                                                     |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Su opcion:                                                                                                          |" << endl;	
	cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
	
	BinFilesHandler bfh = BinFilesHandler();
	
	cin.ignore();
	string opt,opt2;
	
	masiveGotoxy(13,22);
	getline(cin, opt);
	
	std::for_each(opt.begin(), opt.end(), [](char & c){
    c = ::tolower(c);
	});
	
	if(opt == "confirmar"){
		vector <Book> aux = bfh.readALLInventory();	
		if(bfh.editOnInventory(aux)){
			masiveGotoxy(0,20);
			cout << "| Se ha finalizado la eliminacion masiva, por favor escriba 'aceptar' para ser llevado a la ventana principal         |" << endl;			
			masiveGotoxy(0,22);
			cout << "| Su opcion:                                                                                                          |" << endl;	
			masiveGotoxy(0,23);
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;		
			
			masiveGotoxy(13,22);
			getline(cin, opt2);
			
			std::for_each(opt2.begin(), opt2.end(), [](char & c){
		    c = ::tolower(c);
			});
			
			if(opt2 == "aceptar"){
				displayModule();
			}else{
				displayModule();	
			}
		}else{
			masiveGotoxy(0,20);
			cout << "| Se ha finalizado la eliminacion masiva con errores, por favor escriba 'aceptar' y contacte al administrador         |" << endl;			
			masiveGotoxy(0,22);
			cout << "| Su opcion:                                                                                                          |" << endl;	
			masiveGotoxy(0,23);
			cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;		
			
			masiveGotoxy(13,22);
			getline(cin, opt2);
			
			std::for_each(opt2.begin(), opt2.end(), [](char & c){
		    c = ::tolower(c);
			});
			
			if(opt2 == "aceptar"){
				displayModule();	
			}else{
				displayModule();	
			}
		}	
	}else{
		displayModule();	
	}
}
