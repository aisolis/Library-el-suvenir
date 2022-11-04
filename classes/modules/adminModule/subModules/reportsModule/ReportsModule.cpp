#include "ReportsModule.h"
#include "../../../../BinFilesHandler.h"
#include "../../AdminPanel.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include<algorithm>

COORD reportsCoord = {0,0};

void reportsGotoxy(int x, int y){
	reportsCoord.X = x;
	reportsCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),reportsCoord);
}


ReportsModule::ReportsModule(){
	
}

void ReportsModule::displayModule(){
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                              BIBLIOTECA EL PORVENIR                                                 |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                MODULO DE REPORTES                                                   |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Administrador                                                                        |" << endl;
		cout << "| Por favor elija una opcion para generar el reporte, al finalizar se abrira la carpeta donde esta contenido el       |" << endl;
		cout << "| reporte solicitado                                                                                                  |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Reporte de todas las entradas por Titulo del Libro y autor                                                       |" << endl;
		cout << "| 2) Reporte de inventario completo ordenado alfabeticamente por los nombres de los libros                            |" << endl;
		cout << "| 3) Reporte de inventario completo ordenado por precio de menor a mayor                                              |" << endl;
		cout << "| 4) Reporte de ventas / alquileres totales                                                                           |" << endl;
		cout << "| 5) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		reportsGotoxy(13,19);
		cin >> parser;

		std::istringstream (parser) >> optionMenu;
		
		if(optionMenu == 5){
			AdminPanel ap = AdminPanel();
			ap.displayPanelAdmin();
		}else{
			throwAlert(optionMenu);
		}
		
		
	reportsGotoxy(0,30);
}


void ReportsModule::throwAlert(int report){
	system("CLS");
	reportsGotoxy(0,0);
	cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                              BIBLIOTECA EL PORVENIR                                                       |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|                                                                                                                           |" << endl;
	cout << "|                                                                                                                           |" << endl;
	cout << "|                                                                                                                           |" << endl;
	cout << "|                                                                                                                           |" << endl;
	cout << "|                                                                                                                           |" << endl;
	cout << "|                                                                                                                           |" << endl;
	cout << "|                                                                                                                           |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "| Se finalizo la generacion del reporte solicitado, por favor escriba 's'  S:                                               |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
	
	BinFilesHandler bfh = BinFilesHandler();
	
	switch(report){
		case 1:{
			bfh.generateInventoryReportByAutorAndBookTitle();
			break;
		}

		case 2:{
			bfh.generateInventoryReportByBookTitleSorted();
			break;
		}
		
		case 3:{
			bfh.generateInventoryReportByPrice();
			break;
		}
		
		case 4:{
			bfh.generateInventoryReportBySellings();
			break;
		}
		
		default:{
			displayModule();
			break;
		}
	}
		
	reportsGotoxy(32,4);
	cout << " 000000  0000000 000    00 0000000 000000   00000  000000   000000\n";  
	reportsGotoxy(32,5);
	cout << "00       00      0000   00 00      00   00 00   00 00   00 00    00 \n";
	reportsGotoxy(32,6);
	cout <<	"00   000 00000   00 00  00 00000   000000  0000000 00   00 00    00 \n";
	reportsGotoxy(32,7);
	cout << "00    00 00      00  00 00 00      00   00 00   00 00   00 00    00 \n";
	reportsGotoxy(32,8);
	cout <<	" 000000  0000000 00   0000 0000000 00   00 00   00 000000   000000 \n";
			
	string opt;
	
	reportsGotoxy(0,11);
	cout << "| Se finalizo la generacion del reporte solicitado, por favor escriba 's'  S:                                               |" << endl;	
	
	cin.ignore();
	
	reportsGotoxy(78,11);
	getline(cin, opt);
	
	if(opt.size()>0){
		displayModule();
	}else{
		displayModule();
	}
	
}
