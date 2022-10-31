#include "InventoryModule.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

COORD inventoryCoord = {0,0};

void invGotoxy(int x, int y){
	inventoryCoord.X = x;
	inventoryCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),inventoryCoord);
}

InventoryModule::InventoryModule(){
	
}

void InventoryModule::addEntryToInventory(){
	system("CLS");
	cout << "+------------------------------------------------------------------------+\n"
            "|                         BIBLIOTECA EL PORVENIR                         |\n" 
            "+------------------------------------------------------------------------+\n"
            "|                      AGREGAR ENTRADA AL INVENTARIO                     |\n"
			"+------------------------------------------------------------------------+\n"
			"| Nombre del libro:                                                      |\n"
			"| Nombre del Autor:                                                      |\n"
			"| Descripcion del libro:                                                 |\n"
			"|                                                                        |\n"
			"|                                                                        |\n"
			"|                                                                        |\n"
			"| Nombre de la editorial:                                                |\n"
			"| Anio de publicacion:                                                   |\n"
			"| Numero de paginas:                                                     |\n"
			"| Cantidad de existencias en stock:                                      |\n"
			"+------------------------------------------------------------------------+\n"
			"| Confirmar Creacion: S/N:                                               |\n"
			"+------------------------------------------------------------------------+\n"
	<< endl;
	
}

