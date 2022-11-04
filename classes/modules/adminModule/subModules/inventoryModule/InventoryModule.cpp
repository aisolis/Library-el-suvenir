#include "InventoryModule.h"
#include "../../../../Book.h"
#include "../../../../Selling.h"
#include "../../../../BinFilesHandler.h"
#include "../../AdminPanel.h"
#include "../../../SuperModule/SupervisorPanel.h"
#include "../../../operatorModule/OperatorPanel.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <ctime>

time_t now1 = time(0);
tm * time1 = localtime(&now1);
int year = 1900 + time1->tm_year;

string date = std::to_string(time1->tm_mday) + "-" + std::to_string(time1->tm_mon) + "-" + std::to_string(year);

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}


COORD inventoryCoord = {0,0};

void invGotoxy(int x, int y){
	inventoryCoord.X = x;
	inventoryCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),inventoryCoord);
}

std::string truncate(std::string str, size_t width, bool show_ellipsis=true)
{
    if (str.length() > width)
        if (show_ellipsis)
            return str.substr(0, width) + "...";
        else
            return str.substr(0, width);
    return str;
}

InventoryModule::InventoryModule(){
	
}

void InventoryModule::displayInventoryModuleOperator(){
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                  BIBLIOTECA EL PORVENIR                                             |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                  MODULO DE INVENTARIOS                                              |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Operador                                                                             |" << endl;
		cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Listar todos los registros                                                                                       |" << endl;
		cout << "| 2) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		invGotoxy(13,17);
		cin >> parser;


		std::istringstream (parser) >> optionMenu;
		
		AdminPanel ap = AdminPanel();
		switch(optionMenu){
			case 1:{
					displayAllEntrys(1);
				break;
			}

			case 2:{
					OperatorPanel op = OperatorPanel();
					op.displayPanel();
				break;
			}

			default:{
					OperatorPanel op = OperatorPanel();
					op.displayPanel();
				break;
			}
		}
		
	invGotoxy(0,30);
}

void InventoryModule::displayInventoryModuleSupervisor(){
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                  BIBLIOTECA EL PORVENIR                                             |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                  MODULO DE INVENTARIOS                                              |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Supervisor                                                                           |" << endl;
		cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Agregar un registro al inventario                                                                                |" << endl;
		cout << "| 2) Listar todos los registros                                                                                       |" << endl;
		cout << "| 3) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		invGotoxy(13,17);
		cin >> parser;


		std::istringstream (parser) >> optionMenu;
		
		AdminPanel ap = AdminPanel();
		switch(optionMenu){
			case 1:{
					addEntryToInventory(2);
				break;
			}

			case 2:{
					displayAllEntrys(2);
				break;
			}
			
			case 3:{
					SupervisorPanel sp = SupervisorPanel();
					sp.displayPanel();
				break;
			}

			default:{
					SupervisorPanel sp = SupervisorPanel();
					sp.displayPanel();
				break;
			}
		}
		
	invGotoxy(0,30);
}

void InventoryModule::displayModule(){
	
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                  BIBLIOTECA EL PORVENIR                                             |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                  MODULO DE INVENTARIOS                                              |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Administrador                                                                        |" << endl;
		cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Agregar un registro al inventario                                                                                |" << endl;
		cout << "| 2) Listar todos los registros                                                                                       |" << endl;
		cout << "| 3) Editar un registro                                                                                               |" << endl;
		cout << "| 4) Eliminar un registro                                                                                             |" << endl;
		cout << "| 5) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		invGotoxy(13,17);
		cin >> parser;


		std::istringstream (parser) >> optionMenu;
		
		AdminPanel ap = AdminPanel();
		switch(optionMenu){
			case 1:{
					addEntryToInventory(3);
				break;
			}

			case 2:{
					displayAllEntrys(3);
				break;
			}
			
			case 3:{
					editEntryOfInventory(3);
				break;
			}
			
			case 4:{
					deleteEntryOfInventory();
				break;
			}
			
			case 5:{
					ap.displayPanelAdmin();
				break;
			}
			
			default:{
				displayModule();
				break;
			}
		}
		
	invGotoxy(0,30);
}

void InventoryModule::addEntryToInventory(int rol){
	
	
	vector<string> descVector;
	string title;
	string autor;
	string category;
	string description;
	string editorial;
	string anio;
	string pages;
	string price;
	string stock;
	
	char option;
	int counter;
	
	
	system("CLS");
	cout << "+------------------------------------------------------------------------+----------------------------+\n"
            "|                         BIBLIOTECA EL PORVENIR                         |         VALIDACIONES       |\n" 
            "+------------------------------------------------------------------------+----------------------------+\n"
            "|                      AGREGAR ENTRADA AL INVENTARIO                     |  VALIDACION DE FORMULARIO  |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"| Nombre del libro:                                                      | STATUS:                    |\n"
			"| Nombre del Autor:                                                      | STATUS:                    |\n"
			"| Categoria/s del libro:                                                 | STATUS:                    |\n"
			"| Descripcion del libro:                                                 | STATUS:                    |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"| Nombre de la editorial:                                                | STATUS:                    |\n"
			"| Anio de publicacion:                                                   | STATUS:                    |\n"
			"| Numero de paginas:                                                     | STATUS:                    |\n"
			"| Precio de venta/alquiler:                                              | STATUS:                    |\n"
			"| Cantidad de existencias en stock:                                      | STATUS:                    |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"| Confirmar Creacion: S/N:                                               | FORMULARIO:                |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
	<< endl;
	
	invGotoxy(20,5);
	cin.ignore();
	getline(cin, title);
	
	invGotoxy(20,6);
	getline(cin, autor);
	
	invGotoxy(25,7);
	getline(cin, category);
	
	invGotoxy(25,8);
	counter = 8;
	while (getline(cin, description))
    {	invGotoxy(2,++counter);
        if (description.empty()) {        	
            break;
        }
        descVector.push_back(description);
    }
	
	invGotoxy(26,12);
	getline(cin, editorial);
	
	invGotoxy(23,13);
	getline(cin, anio);
	
	invGotoxy(21,14);
	getline(cin, pages);
	
	invGotoxy(28,15);
	getline(cin, price);
	
	invGotoxy(36,16);
	getline(cin, stock);
	
	invGotoxy(27,18);
	cin >> option;

	if(tolower(option) == 's'){
		invGotoxy(0,18);
		InventoryModule::validateForm(title, autor, category, descVector, editorial, anio, pages, price, stock, false, rol);
	}else{
		switch(rol){
			case 1:{
				displayInventoryModuleOperator();
				break;
			}
			case 2:{
				displayInventoryModuleSupervisor();
				break;
			}
			case 3:{
				displayModule();	
				break;
			}
		}
		
	}
	
	
}

void InventoryModule::validateForm(string title, string autor, string category, vector<string> desc, string editorial, string anio, string pages, string price, string stock, bool isEdit, int rol){
	Book book = Book();

	int errorCount;
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	bool b4 = false;
	bool b5 = false;
	bool b6 = false;
	bool b7 = false;
	bool b8 = false;
	bool b9 = false;
	
	if(title.size() > 0){
		if(isEdit){
			invGotoxy(107,5);
			cout << "| STATUS: OK: CAMPO VALIDO!  |";
		}else{
			invGotoxy(83,5);
			cout<<"OK: CAMPO VALIDO   ";
		}
		book.setBookTitle(title);
	}else{
		
		if(isEdit){
			invGotoxy(0,5);
			cout << "| Nombre del libro:                                                      |";
			invGotoxy(107,5);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,5);
			cout << "| Nombre del libro:                                                      | STATUS: ERROR: CAMPO VACIO!|";
		}
		errorCount += 1;
		b1 = true;
	}
	
	

	if(autor.size() > 0){
		if(isEdit){
			invGotoxy(107,6);
			cout << "| STATUS: OK: CAMPO VALIDO!  |";
		}else{
			invGotoxy(83,6);
			cout<<"OK: CAMPO VALIDO   ";
		}
		book.setAutor(autor);
	}else{
		if(isEdit){
			invGotoxy(0,6);
			cout << "| Nombre del Autor:                                                      |";
			invGotoxy(107,6);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,6);
			cout << "| Nombre del Autor:                                                      | STATUS: ERROR: CAMPO VACIO!|";	
		}
		errorCount += 1;
		b2 = true;
	}
	
	
	if(category.size() > 0){
		if(isEdit){
			invGotoxy(107,7);
			cout << "| STATUS: OK: CAMPO VALIDO!  |";
		}else{
			invGotoxy(83,7);
			cout<<"OK: CAMPO VALIDO   ";
		}
		book.setCategory(category);
	}else{
		if(isEdit){
			invGotoxy(0,7);
			cout << "| Categoria/s del libro:                                                 |";
			invGotoxy(107,7);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,7);
			cout << "| Categoria/s del libro:                                                 | STATUS: ERROR: CAMPO VACIO!|";	
		}
		errorCount += 1;
		b3 = true;
	}
	
	
	

	if(desc.size() > 0){
		if(isEdit){
			invGotoxy(107,8);
			cout << "| STATUS: OK: CAMPO VALIDO!  |";
		}else{
			invGotoxy(83,8);
			cout<<"OK: CAMPO VALIDO   ";
		}
		book.setDescription(desc);
		
	}else{
		if(isEdit){
			invGotoxy(0,8);
			cout << "| Descripcion del libro:                                                 |\n";
			        "|                                                                        |\n";
			        "|                                                                        |";
			invGotoxy(107,8);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,8);
			cout << "| Descripcion del libro:                                                 | STATUS: ERROR: CAMPO VACIO!|\n"
			        "|                                                                        |                            |\n"
					"|                                                                        |                            |";	
		}
		errorCount += 1;
		b4 = true;
	}
	
	
	

	if(editorial.size() > 0){
		if(isEdit){
			invGotoxy(107,12);
			cout << "| STATUS: OK: CAMPO VALIDO!  |";
		}else{
			invGotoxy(83,12);
			cout<<"OK: CAMPO VALIDO   ";
		}
		book.setEditorial(editorial);
	}else{
		if(isEdit){
			invGotoxy(0,12);
			cout << "| Nombre de la editorial:                                                |";
			invGotoxy(107,12);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,12);
			cout << "| Nombre de la editorial:                                                | STATUS: ERROR: CAMPO VACIO!|";	
		}
		errorCount += 1;
		b5 =  true;
	}
	
	
	

	if(anio.size() > 0){
		int parsedYear;
		std::istringstream (trim(anio)) >> parsedYear;
		if(parsedYear !=0){
			
			if(isEdit){
				invGotoxy(107,13);
				cout << "| STATUS: OK: CAMPO VALIDO!  |";
			}else{
				invGotoxy(83,13);
				cout<<"OK: CAMPO VALIDO   ";
			}
			book.setPublicationYear(parsedYear);
			
		}else{
			if(isEdit){
				invGotoxy(0,13);
				cout << "| Anio de publicacion:                                                   |";
				invGotoxy(107,13);
				cout << "| STATUS: ERROR: SOLO NUMEROS|";
			}else{
				invGotoxy(0,13);
				cout << "| Anio de publicacion:                                                   | STATUS: ERROR: SOLO NUMEROS|";
			}
			errorCount += 1;
			b6 = true;	
		}
	}else{
		if(isEdit){
			invGotoxy(0,13);
			cout << "| Anio de publicacion:                                                   |";
			invGotoxy(107,13);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,13);
			cout << "| Anio de publicacion:                                                   | STATUS: ERROR: CAMPO VACIO!|";	
		}
		errorCount += 1;
		b6 = true;	
	}
	
	
	
	

	if(pages.size() > 0){
		int parsedPage;
		std::istringstream (trim(pages)) >> parsedPage;
		if(parsedPage !=0){
			if(isEdit){
				invGotoxy(107,14);
				cout << "| STATUS: OK: CAMPO VALIDO!  |";
			}else{
				invGotoxy(83,14);
				cout<<"OK: CAMPO VALIDO   ";
			}
			book.setPagesNumbers(parsedPage);
		}else{
			if(isEdit){
				invGotoxy(0,14);
				cout << "| Numero de paginas:                                                     |";
				invGotoxy(107,14);
				cout << "| STATUS: ERROR: SOLO NUMEROS|";
			}else{
				invGotoxy(0,14);
				cout << "| Numero de paginas:                                                     | STATUS: ERROR: SOLO NUMEROS|";	
			}
			errorCount += 1;	
			b7 = true;	
		}
	}else{
		if(isEdit){
			invGotoxy(0,14);
			cout << "| Numero de paginas:                                                     |";
			invGotoxy(107,14);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,14);
			cout << "| Numero de paginas:                                                     | STATUS: ERROR: CAMPO VACIO!|";	
		}
		errorCount += 1;
		b7 = true;	
	}
	
	
	
	if(price.size() > 0){
		double parsedPrice;
		parsedPrice = std::stod (trim(price));
		if(parsedPrice !=0){
			if(isEdit){
				invGotoxy(107,15);
				cout << "| STATUS: OK: CAMPO VALIDO!  |";
			}else{
				invGotoxy(83,15);
				cout<<"OK: CAMPO VALIDO   ";
			}
			book.setPrice(parsedPrice);
		}else{
			if(isEdit){
				invGotoxy(0,15);
				cout << "| Precio de venta/alquiler:                                              |";
				invGotoxy(107,15);
				cout << "| STATUS: ERROR: SOLO NUMEROS|";
			}else{
				invGotoxy(0,15);
				cout << "| Precio de venta/alquiler:                                              | STATUS: ERROR: SOLO NUMEROS|";	
			}
			errorCount += 1;	
			b8 = true;	
		}
	}else{
		if(isEdit){
			invGotoxy(0,15);
			cout << "| Precio de venta/alquiler:                                              |";
			invGotoxy(107,15);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,15);
			cout << "| Precio de venta/alquiler:                                              | STATUS: ERROR: CAMPO VACIO!|";	
		}
		errorCount += 1;
		b8 = true;	
	}
	
	

	if(stock.size() > 0){
		int parsedStock;
		std::istringstream (trim(stock)) >> parsedStock;
		if(parsedStock !=0){
			if(isEdit){
				invGotoxy(107,16);
				cout << "| STATUS: OK: CAMPO VALIDO!  |";
			}else{
				invGotoxy(83,16);
				cout<<"OK: CAMPO VALIDO   ";
			}
			book.setStock(parsedStock);
		}else{
			if(isEdit){
				invGotoxy(0,16);
				cout << "| Cantidad de existencias en stock:                                      |";
				invGotoxy(107,16);
				cout << "| STATUS: ERROR: SOLO NUMEROS|";
			}else{
				invGotoxy(0,16);
				cout << "| Cantidad de existencias en stock:                                      | STATUS: ERROR: SOLO NUMEROS|";	
			}
			errorCount += 1;
			b9 = true;	
		}
	}else{
		if(isEdit){
			invGotoxy(0,16);
			cout << "| Cantidad de existencias en stock:                                      |";
			invGotoxy(107,16);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			invGotoxy(0,16);
			cout << "| Cantidad de existencias en stock:                                      | STATUS: ERROR: CAMPO VACIO!|";	
		}
		errorCount += 1;
		b9 = true;	
	}

	if(errorCount > 0){
		if(isEdit){
			invGotoxy(0,18);
			cout << "| Confirmar esta edicion S/N:                                            |                                 | FORMULARIO:                |\n";
			invGotoxy(123,18);
			cout << "INVALIDO";
		}else{
			invGotoxy(0,18);
			cout << "| Confirmar Creacion: S/N:                                               | FORMULARIO:                |";	
			invGotoxy(87,18);
			cout << "INVALIDO";
		}
	 
	 	if(isEdit){
	 		fixFormData(b1,b2,b3,b4,b5,b6,b7,b8,b9, title, autor, category, desc, editorial, anio, pages, price, stock, true, rol);	
		}else{
			fixFormData(b1,b2,b3,b4,b5,b6,b7,b8,b9, title, autor, category, desc, editorial, anio, pages, price, stock, false, rol);
		}
		

	}else{
		if(!isEdit){
			invGotoxy(87,18);
			cout << "VALIDO";	
		}
		
		BinFilesHandler bfh = BinFilesHandler();
		if(isEdit){
			
			Book aux = editingVector[indexvector];
			book.setHashCode(aux.getHashCode());
			book.setIsBorrowed(aux.getIsBorrowed());
			book.setBorrowedDate(aux.getBorrowedDate());
			editingVector[indexvector] = book;
			
			char opt2;
			
			if(bfh.editOnInventory(editingVector)){
				while(toupper(opt2) != 'S'){
					invGotoxy(0,18);
					cout << "| Libro editado en el inventario con exito, aceptar? S:                  |                                 | FORMULARIO:  FINALIZADO    |";
		
					invGotoxy(56,18);
					cin >> opt2;	
				}	
			}else{
				while(toupper(opt2) != 'S'){
				invGotoxy(0,18);
				cout << "| Libro no editado en el inventario con exito, aceptar? S:                |                                 | FORMULARIO:  CON ERROR    |";
	
				invGotoxy(56,18);
				cin >> opt2;	
				}
			}
			invGotoxy(0,0);
			InventoryModule::editEntryOfInventory(rol);	
		}else{

			char opt2;
			
			vector<Book> booksTovalidate = bfh.readALLInventory();
			
			for(int x = 0; x < booksTovalidate.size(); x++){
				Book aux = booksTovalidate[x];
				if(book.getBookTitle() == aux.getBookTitle()){
					throwAlert(booksTovalidate, x, rol);
				}
			}
	
			if(bfh.writeOnInventory(book)){
				invGotoxy(0,18);
				cout << "| Libro agregado al inventario con exito, agregar otro? S/N:              | FORMULARIO:  FINALIZADO   |";
	
				invGotoxy(61,18);
				cin >> opt2;
	
				if(toupper(opt2) == 'S' || tolower(opt2) == 's'){
					invGotoxy(0,0);
					InventoryModule::addEntryToInventory(rol);	
				}else{
					switch(rol){
						case 1:{
							displayInventoryModuleOperator();
							break;
						}
						case 2:{
							displayInventoryModuleSupervisor();
							break;
						}
						case 3:{
							displayModule();	
							break;
						}
					}
				}
			}		
		}

	
	}
	
}

void InventoryModule::throwAlert(vector<Book> books, int index, int rol){
	system("CLS");
	invGotoxy(0,0);
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
	cout << "| Se encontro una entrada en el inventario con el mismo titulo, desea modificar esta entrada? S/N:                          |" << endl;
	cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
	
	invGotoxy(32,4);
	cout << " 00000  00      0000000 000000  00000000  00000  00\n";
	invGotoxy(32,5);
	cout << "00   00 00      00      00   00    00    00   00 00\n";
	invGotoxy(32,6);
	cout <<	"0000000 00      00000   000000     00    0000000 00\n";
	invGotoxy(32,7);
	cout << "00   00 00      00      00   00    00    00   00   \n";
	invGotoxy(32,8);
	cout <<	"00   00 0000000 0000000 00   00    00    00   00 00\n";
			
	char opt;
	invGotoxy(99,11);
	cin >> opt;
	
	
	
	do{
		if(tolower(opt) == 'n'){
			displayModule();
			break;
		}
		
		invGotoxy(0,11);
		cout << "| Se encontro una entrada en el inventario con el mismo titulo, desea modificar esta entrada? S/N:                          |" << endl;		
		
		invGotoxy(99,11);
		cin >> opt;
	}while(tolower(opt) != 's');
	
	editEntry(books, index, false, rol);
	
}

void InventoryModule::fixFormData(bool title, bool autor, bool category, bool desc, bool editorial, bool anio, bool pages, bool price, bool stock, string a, string b,string c, vector<string> d, string e, string f, string g, string h, string i, bool editMode, int rol){
	vector<string> descVector;
	string titleFix;
	string autorFix;
	string categoryFix;
	string descriptionFix;
	string editorialFix;
	string anioFix;
	string pagesFix;
	string priceFix;
	string stockFix;

	char optionFix;
	int counterFix;

	cin.ignore();

	if(title){
		invGotoxy(20,5);
		getline(cin, titleFix);
	}else{
		titleFix = a;
	}

	if(autor){
		invGotoxy(20,6);
		getline(cin, autorFix);
	}else{
		autorFix = b;
	}
	
	if(category){
		invGotoxy(20,7);
		getline(cin, autorFix);
	}else{
		autorFix = c;
	}
	
	if(desc){
		invGotoxy(25,8);
		counterFix = 8;
		while (getline(cin, descriptionFix))
		{	invGotoxy(2,++counterFix);
			if (descriptionFix.empty()) {        	
				break;
			}
			descVector.push_back(descriptionFix);
		}
	}else{
		descVector = d;
	}
	
	if(editorial){
		invGotoxy(26,12);
		getline(cin, editorialFix);
	}else{
		editorialFix = e;
	}
	
	if(anio){
		invGotoxy(23,13);
		getline(cin, anioFix);
	}else{
		anioFix = f;
	}
	
	if(pages){
		invGotoxy(21,14);
		getline(cin, pagesFix);
	}else{
		pagesFix = g;
	}
	
	if(price){
		invGotoxy(21,15);
		getline(cin, pagesFix);
	}else{
		pagesFix = h;
	}
	
	if(stock){
		invGotoxy(36,16);
		getline(cin, stockFix);
	}else{
		stockFix = i;
	}

	invGotoxy(28,18);
	cin >> optionFix;


	if(editMode){
		if(toupper(optionFix) == 'S' || tolower(optionFix) == 's'){
			invGotoxy(0,20);
			InventoryModule::validateForm(titleFix, autorFix, categoryFix, descVector, editorialFix, anioFix, pagesFix, priceFix, stockFix, true, rol);
		}		
	}else{
		if(toupper(optionFix) == 'S' || tolower(optionFix) == 's'){
			invGotoxy(0,18);
			InventoryModule::validateForm(titleFix, autorFix, categoryFix, descVector, editorialFix, anioFix, pagesFix, priceFix, stockFix, false, rol);
		}	
	}
	

}

void InventoryModule::displayAllEntrys(int rol){
		system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<Book> books = bfh.readALLInventory();
		
		char opt;
		
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                                          BIBLIOTECA EL PORVENIR                                                                            |" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                                      LISTADO DE REGISTROS BIBLIOTECA                                                                       |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		cout << "|           Titulo           |      Autor      |    Categorias    |     Editorial     | Año de Publicacion | Numero de Paginas | Precio venta o Alquiler | Cantidad en Stock |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < books.size(); x++){
		Book tmpB = books[x];
		
		invGotoxy(0,(firstLine));
		cout << "|" << endl;
		invGotoxy(2,(firstLine));
		cout <<	truncate(tmpB.getBookTitle(),26, true);
		
		
		invGotoxy(29,(firstLine));
		cout << "|" << endl;
		invGotoxy(31,(firstLine));
		cout <<	truncate(tmpB.getAutor(),15, true);
		
		
		invGotoxy(47,(firstLine));
		cout << "|" << endl;
		invGotoxy(49,(firstLine));
		cout <<	truncate(tmpB.getCategory(),16, true);
		
		
		invGotoxy(66,(firstLine));
		cout << "|" << endl;
		invGotoxy(68,(firstLine));
		cout <<	truncate(tmpB.getEditorial(),17, true);
		
		
		invGotoxy(86,(firstLine));
		cout << "|" << endl;
		invGotoxy(88,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPublicationYear()),18, true);
		
		
		invGotoxy(107,(firstLine));
		cout << "|" << endl;
		invGotoxy(109,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPagesNumbers()),17, true);
		
		invGotoxy(127,(firstLine));
		cout << "|" << endl;
		invGotoxy(129,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPrice()),23, true);
		
		
		invGotoxy(153,(firstLine));
		cout << "|" << endl;
		invGotoxy(155,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getStock()),17, true);
		invGotoxy(173,(firstLine));
		cout << "|" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" <<endl;
		
		firstLine += 2;
	}
		
		cout << "| Desea regresar al menu principal? S/N                                                                                                                                      |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                                                                                 |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;

	while(toupper(opt) != 'S'){
		invGotoxy(0,firstLine+2);
		cout << "| Su opcion:                                                                                                                |" << endl;	
		invGotoxy(13,firstLine+2);
		cin >> opt;	
	}
	
	switch(rol){
		case 1:{
			displayInventoryModuleOperator();
			break;
		}

		case 2:{
			displayInventoryModuleSupervisor();
			break;
		}

		case 3:{
			displayModule();
			break;
		}
	}
	
	
}


void InventoryModule::editEntryOfInventory(int rol){
	
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<Book> books = bfh.readALLInventory();
		
		string opt;
		
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                                          BIBLIOTECA EL PORVENIR                                                                            |" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                               EDITAR REGISTRO DEL LISTADO DE REGISTROS BIBLIOTECA                                                          |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		cout << "|           Titulo           |      Autor      |    Categorias    |     Editorial    | Anio de Publicacion | Numero de Paginas | Precio venta o Alquiler | Cantidad en Stock |" << endl;
		cout << "+----------------------------+-----------------+------------------+------------------+---------------------+-------------------+-------------------------+-------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < books.size(); x++){
		Book tmpB = books[x];
		
		invGotoxy(0,(firstLine));
		cout << "|" << endl;
		invGotoxy(2,(firstLine));
		cout <<	truncate(tmpB.getBookTitle(),26, true);
		
		
		invGotoxy(29,(firstLine));
		cout << "|" << endl;
		invGotoxy(31,(firstLine));
		cout <<	truncate(tmpB.getAutor(),15, true);
		
		
		invGotoxy(47,(firstLine));
		cout << "|" << endl;
		invGotoxy(49,(firstLine));
		cout <<	truncate(tmpB.getCategory(),16, true);
		
		
		invGotoxy(66,(firstLine));
		cout << "|" << endl;
		invGotoxy(68,(firstLine));
		cout <<	truncate(tmpB.getEditorial(),17, true);
		
		
		invGotoxy(86,(firstLine));
		cout << "|" << endl;
		invGotoxy(88,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPublicationYear()),18, true);
		
		
		invGotoxy(107,(firstLine));
		cout << "|" << endl;
		invGotoxy(109,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPagesNumbers()),17, true);
		
		invGotoxy(127,(firstLine));
		cout << "|" << endl;
		invGotoxy(129,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPrice()),23, true);
		
		
		invGotoxy(153,(firstLine));
		cout << "|" << endl;
		invGotoxy(155,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getStock()),17, true);
		invGotoxy(173,(firstLine));
		cout << "|" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" <<endl;
		
		firstLine += 2;
	}
		cout << "| Escriba el nombre del libro que desea editar o escriba cualquier palabra para volver al menu principal                                                                     |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Titulo del Libro:                                                                                                                                                          |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		invGotoxy(20,firstLine+2);
		cin.ignore();	
		
		getline(cin, opt);
		
		std::for_each(opt.begin(), opt.end(), [](char & c){
	    	c = ::tolower(c);
		});
		
		
		
		for(int y = 0; y < books.size();y++){
			if(opt == books[y].getBookTitle()){
				editEntry(books, y, false, rol);
			}
		}	
		
		displayModule();
}

void InventoryModule::editEntry(vector<Book> books, int index, bool isABorrow, int rol){
	
	
	vector<string> descVector;
	string title;
	string autor;
	string category;
	string description;
	string editorial;
	string anio;
	string pages;
	string price;
	string stock;
	
	char option;
	int counter;
	
	
	system("CLS");
	cout << "+------------------------------------------------------------------------+----------------------------+\n"
            "|                         BIBLIOTECA EL PORVENIR                         |         VALIDACIONES       |\n" 
            "+------------------------------------------------------------------------+----------------------------+\n"
            "|                         ENTRADA EN EL INVENTARIO                       |  VALIDACION DE FORMULARIO  |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"| Nombre del libro:                                                      | STATUS:                    |\n"
			"| Nombre del Autor:                                                      | STATUS:                    |\n"
			"| Categoria/s del libro:                                                 | STATUS:                    |\n"
			"| Descripcion del libro:                                                 | STATUS:                    |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"| Nombre de la editorial:                                                | STATUS:                    |\n"
			"| Anio de publicacion:                                                   | STATUS:                    |\n"
			"| Numero de paginas:                                                     | STATUS:                    |\n"
			"| Precio de venta/alquiler:                                              | STATUS:                    |\n"
			"| Cantidad de existencias en stock:                                      | STATUS:                    |\n"
			"+------------------------------------------------------------------------+----------------------------+\n";	
	if(!isABorrow){
		cout <<	"| Confirmar edicion S/N:                                                 | FORMULARIO:                |\n"
			    "+------------------------------------------------------------------------+----------------------------+\n" << endl;			
	}else{
		cout <<	"| Confirmar este libro para alquilar/vender S/N:                         | FORMULARIO:                |\n"
			    "+------------------------------------------------------------------------+----------------------------+\n" << endl;
	}
	
	Book preview = books[index];
	
	invGotoxy(20,5);
	cout << preview.getBookTitle()<<endl;
	
	
	invGotoxy(20,6);
	cout << preview.getAutor()<<endl;
	
	invGotoxy(20,7);
	cout << preview.getCategory() <<endl;
	
	invGotoxy(25,8);
	int counter2 = 8;
	vector<string> desc;
	desc = preview.getDescription();
	for(int u = 0; u < desc.size(); u++){
		if(u > 0){
			invGotoxy(25,8);	
			cout << desc[u]<<endl;
		}else{
			invGotoxy(2,++counter2);	
			cout << desc[u]<<endl;
		}		
	}
	
	invGotoxy(26,12);
	cout << preview.getEditorial()<<endl;  
	
	invGotoxy(23,13);
	cout << preview.getPublicationYear()<<endl;  
	
	invGotoxy(21,14);
	cout << preview.getPagesNumbers()<<endl;  
	
	invGotoxy(28,15);
	cout << preview.getPrice()<<endl;  
	
	invGotoxy(36,16);
	cout << preview.getStock()<<endl;  
	
	if(isABorrow){
		invGotoxy(49,18);
		cin >> option;
	}else{
		invGotoxy(25,18);
		cin >> option;
	}	

	if(toupper(option) == 'S' || tolower(option) == 's'){
		if(isABorrow){
			displayBorrowScreen(books, index, rol);
		}else{
			system("CLS");
			cout << "+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
					"|                         BIBLIOTECA EL PORVENIR                         |        INFORMACION ACTUAL       |         VALIDACIONES       |\n" 
					"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
					"|                         ENTRADA DE EL INVENTARIO                       |                                 |                            |\n"
					"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
					"| Nombre del libro:                                                      | PREV:                           | STATUS:                    |\n"
					"| Nombre del Autor:                                                      | PREV:                           | STATUS:                    |\n"
					"| Categoria/s del libro:                                                 | PREV:                           | STATUS:                    |\n"
					"| Descripcion del libro:                                                 | PREV:                           | STATUS:                    |\n"
					"|                                                                        |                                 |                            |\n"
					"|                                                                        |                                 |                            |\n"
					"|                                                                        |                                 |                            |\n"
					"| Nombre de la editorial:                                                | PREV:                           | STATUS:                    |\n"
					"| Anio de publicacion:                                                   | PREV:                           | STATUS:                    |\n"
					"| Numero de paginas:                                                     | PREV:                           | STATUS:                    |\n"
					"| Precio de venta/alquiler:                                              | PREV:                           | STATUS:                    |\n"
					"| Cantidad de existencias en stock:                                      | PREV:                           | STATUS:                    |\n"
					"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
					"| Confirmar este libro para alquilar/vender S/N:                         |                                 | FORMULARIO:                |\n"
					"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"<< endl;
				
			invGotoxy(81,5);
			cout << preview.getBookTitle()<<endl;
			
			invGotoxy(81,6);
			cout << preview.getAutor()<<endl;
			
			invGotoxy(81,7);
			cout << preview.getCategory()<<endl;
			
			invGotoxy(81,8);
			int counter2 = 8;
			vector<string> desc;
			desc = preview.getDescription();
			for(int u = 0; u < desc.size(); u++){
				if(u > 0){
					invGotoxy(81,8);	
					cout << desc[u]<<endl;
				}else{
					invGotoxy(75,++counter2);	
					cout << desc[u]<<endl;
				}		
			}
			
			
			invGotoxy(81,12);
			cout << preview.getEditorial()<<endl;  
			
			invGotoxy(81,13);
			cout << preview.getPublicationYear()<<endl;  
			
			invGotoxy(81,14);
			cout << preview.getPagesNumbers()<<endl;  
			
			invGotoxy(86,15);
			cout << preview.getPrice()<<endl;  
			
			invGotoxy(81,16);
			cout << preview.getStock()<<endl;  
			
			
			invGotoxy(20,5);
			cin.ignore();
			getline(cin, title);
			
			invGotoxy(20,6);
			getline(cin, autor);
			
			invGotoxy(25,7);
			getline(cin, category);
			
			invGotoxy(25,8);
			counter = 8;
			while (getline(cin, description))
			{	invGotoxy(2,++counter);
				if (description.empty() || counter > 10) {        	
					break;
				}
				descVector.push_back(description);
			}
			
			invGotoxy(26,12);
			getline(cin, editorial);
			
			invGotoxy(23,13);
			getline(cin, anio);
			
			invGotoxy(21,14);
			getline(cin, pages);
			
			invGotoxy(28,15);
			getline(cin, price);
			
			invGotoxy(36,16);
			getline(cin, stock);

			if(isABorrow){
				invGotoxy(49,18);
				cin >> option;
			}else{
				invGotoxy(30,18);
				cin >> option;
			}
		
			if(toupper(option) == 'S'){
				InventoryModule::editingVector = books;
				indexvector = index;
				InventoryModule::validateForm(title, autor, category, descVector, editorial, anio, pages, price, stock, true, rol);
			}else{
				editEntryOfInventory(rol);	
			}
		}
		
	}else{
		if(isABorrow){
			borrowABook(rol);
		}else{
			editEntryOfInventory(rol);	
		}
	}
	
	
}


void InventoryModule::deleteEntryOfInventory(){
	
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<Book> books = bfh.readALLInventory();
		
		string opt;
		
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                                          BIBLIOTECA EL PORVENIR                                                                            |" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                               ELIMINAR REGISTO DEL LISTADO DE REGISTROS BIBLIOTECA                                                         |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		cout << "|           Titulo           |      Autor      |    Categorias    |     Editorial     |  Anio Publicacion  | Numero de Paginas | Precio venta o Alquiler | Cantidad en Stock |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < books.size(); x++){
		Book tmpB = books[x];
		
		invGotoxy(0,(firstLine));
		cout << "|" << endl;
		invGotoxy(2,(firstLine));
		cout <<	truncate(tmpB.getBookTitle(),26, true);
		
		
		invGotoxy(29,(firstLine));
		cout << "|" << endl;
		invGotoxy(31,(firstLine));
		cout <<	truncate(tmpB.getAutor(),15, true);
		
		
		invGotoxy(47,(firstLine));
		cout << "|" << endl;
		invGotoxy(49,(firstLine));
		cout <<	truncate(tmpB.getCategory(),16, true);
		
		
		invGotoxy(66,(firstLine));
		cout << "|" << endl;
		invGotoxy(68,(firstLine));
		cout <<	truncate(tmpB.getEditorial(),17, true);
		
		
		invGotoxy(86,(firstLine));
		cout << "|" << endl;
		invGotoxy(88,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPublicationYear()),18, true);
		
		
		invGotoxy(107,(firstLine));
		cout << "|" << endl;
		invGotoxy(109,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPagesNumbers()),17, true);
		
		invGotoxy(127,(firstLine));
		cout << "|" << endl;
		invGotoxy(129,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPrice()),23, true);
		
		
		invGotoxy(153,(firstLine));
		cout << "|" << endl;
		invGotoxy(155,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getStock()),17, true);
		invGotoxy(173,(firstLine));
		cout << "|" << endl;
		cout << "+----------------------------+-----------------+---------------+--------------------+-------------------+-------------------+" <<endl;
		
		firstLine += 2;
	}
		cout << "| Escriba el nombre del libro que desea eliminar o escriba cualquier cosa para volver al menu principal                                                                      |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Titulo del Libro:                                                                                                                                                          |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		invGotoxy(20,firstLine+2);
		cin.ignore();	
		
		getline(cin, opt);
		
		std::for_each(opt.begin(), opt.end(), [](char & c){
	    	c = ::tolower(c);
		});
		
		for(int y = 0; y < books.size();y++){
			
			if(opt == books[y].getBookTitle()){
				vector<Book> aux = books;
				aux.erase(aux.begin()+y);
				
				char opt2;
				
				if(bfh.editOnInventory(aux)){
					while(toupper(opt2) != 'S'){
						invGotoxy(0,firstLine+2);
						cout << "| Libro eliminado en el inventario con exito, aceptar? S:                                       | FORMULARIO:  FINALIZADO    ";
						invGotoxy(58,firstLine+2);
						cin >> opt2;	
					}	
				}else{
					while(toupper(opt2) != 'S'){
					invGotoxy(0,firstLine+2);
					cout << "| Libro no eliminado en el inventario, aceptar S:                                                | FORMULARIO:  CON ERROR    ";
		
					invGotoxy(58,firstLine+2);
					cin >> opt2;	
					}
				}
				invGotoxy(0,0);
				InventoryModule::deleteEntryOfInventory();	
			}else{
				continue;
			}
		}	
		displayModule();
		
}

void InventoryModule::borrowABook(int rol){
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<Book> books = bfh.readALLInventory();
		
		string opt;
		
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                                          BIBLIOTECA EL PORVENIR                                                                            |" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                                  ALQUILER Y VENTA DE LIBROS DE LA BIBLIOTECA                                                               |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		cout << "|           Titulo           |      Autor      |    Categorias    |     Editorial     |  Anio Publicacion  | Numero de Paginas | Precio venta o Alquiler | Cantidad en Stock |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < books.size(); x++){
		Book tmpB = books[x];
		
		invGotoxy(0,(firstLine));
		cout << "|" << endl;
		invGotoxy(2,(firstLine));
		cout <<	truncate(tmpB.getBookTitle(),26, true);
		
		
		invGotoxy(29,(firstLine));
		cout << "|" << endl;
		invGotoxy(31,(firstLine));
		cout <<	truncate(tmpB.getAutor(),15, true);
		
		
		invGotoxy(47,(firstLine));
		cout << "|" << endl;
		invGotoxy(49,(firstLine));
		cout <<	truncate(tmpB.getCategory(),16, true);
		
		
		invGotoxy(66,(firstLine));
		cout << "|" << endl;
		invGotoxy(68,(firstLine));
		cout <<	truncate(tmpB.getEditorial(),17, true);
		
		
		invGotoxy(86,(firstLine));
		cout << "|" << endl;
		invGotoxy(88,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPublicationYear()),18, true);
		
		
		invGotoxy(107,(firstLine));
		cout << "|" << endl;
		invGotoxy(109,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPagesNumbers()),17, true);
		
		invGotoxy(127,(firstLine));
		cout << "|" << endl;
		invGotoxy(129,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPrice()),23, true);
		
		
		invGotoxy(153,(firstLine));
		cout << "|" << endl;
		invGotoxy(155,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getStock()),17, true);
		invGotoxy(173,(firstLine));
		cout << "|" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" <<endl;
		
		firstLine += 2;
	}

		cout << "| Escriba el nombre del libro que desea alquilar o vender o escriba cualquier cosa para volver al menu principal                                                                      |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Titulo del Libro:                                                                                                                                                          |" << endl;	
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		invGotoxy(20,firstLine+2);
		cin.ignore();	
		
		getline(cin, opt);
		
		std::for_each(opt.begin(), opt.end(), [](char & c){
	    	c = ::tolower(c);
		});
		
		for(int y = 0; y < books.size();y++){
			
			if(opt == books[y].getBookTitle()){
					editEntry(books, y, true, rol);
			}else{
				continue;
			}
		}	
		displayInventoryModuleOperator();

}

void InventoryModule::displayBorrowScreen(vector<Book> books, int index, int rol){
	system("CLS");
			cout << "+---------------------------------------------------------------------------------+------------------------+" << endl;
			cout << "|                              BIBLIOTECA EL PORVENIR                             |                        |" << endl;
			cout << "+---------------------------------------------------------------------------------+------------------------+" << endl;
			cout << "|                    ALQUILER Y VENTA DE LIBROS DE LA BIBLIOTECA                  |     VALIDACIONES       |" << endl;
			cout << "+---------------------------------------------------------------------------------+------------------------+" << endl;
			cout << "|                                                                                 |                        |" << endl;
			cout << "| Rellene los datos solicitados, tomar en cuenta que por prestamos el importe     |                        |" << endl;
			cout << "| total es Q.0.00, el precio solo sera tomado para ventas.                        |                        |" << endl;
			cout << "|                                                                                 |                        |" << endl;
			cout << "| Campos obligatorios marcados con *                                              |                        |" << endl;
			cout << "|                                                                                 |                        |" << endl;
			cout << "| Nombre del cliente (*):                                                         |  STATUS:               |" << endl;
			cout << "| Direccion del cliente:                                                          |                        |" << endl;
			cout << "| Telefono del cliente:                                                           |                        |" << endl;
			cout << "| NIT del cliente:                                                                |                        |" << endl;
			cout << "| Escriba [v] para venta o [a] para alquiler (*):                                 |                        |" << endl;
			cout << "| Libro Solicitado:                                                               |                        |" << endl;
			cout << "| Precio:                                                                         |                        |" << endl;
			cout << "| Stock disponible:                                                               |                        |" << endl;
			cout << "| Cantidad solicitada (*):                                                        |  STATUS:               |" << endl;
			cout << "| Fecha de devolucion (si es alquiler):                                           |  STATUS:               |" << endl;
			cout << "| Fecha del prestamo / venta:                                                     |                        |" << endl;
			cout << "| Correo para factura:                                                            |                        |" << endl;
			cout << "|                                                                                 |                        |" << endl;
			cout << "+---------------------------------------------------------------------------------+------------------------+" << endl;
			cout << "| Sub total:                                       Grand Total:                   | ESTADO:                |" << endl;
			cout << "+---------------------------------------------------------------------------------+------------------------+" << endl;
			cout << "| Informacion correcta? S/N:                                                                               |" << endl;
			cout << "+---------------------------------------------------------------------------------+------------------------+" << endl;

			string clientName;
			string clientAddress;
			string telefono;
			string nit;
			char transaction;
			string cantidad;
			string fechaDevolucion;
			string fechaPrestamo = date;
			string correo;

			char option;

		Book aux = books[index];
		cin.ignore();

		invGotoxy(20,16);
		cout << aux.getBookTitle() << endl;

		invGotoxy(20,18);
		cout << aux.getStock() << endl;

		invGotoxy(26,11);
		getline(cin, clientName);

		invGotoxy(25,12);
		getline(cin, clientAddress);

		invGotoxy(24,13);
		getline(cin, telefono);

		invGotoxy(19,14);
		getline(cin, nit);

		invGotoxy(50,15);
		cin >> transaction;
		
		cin.ignore();
		
		if(tolower(transaction) == 'v'){
			invGotoxy(10,17);
				cout << aux.getPrice() << endl;		
				
				invGotoxy(27,19);
				getline(cin, cantidad);
				
				if(cantidad == "" || cantidad == " "){
					cantidad = "0";
				}

				invGotoxy(40,20);
				cout << "Es venta" << endl;

				invGotoxy(30,21);
				cout << date << endl;

				invGotoxy(23,22);
				getline(cin, correo);
				
		}else if(transaction == 'a'){
				invGotoxy(10,17);
				cout << 0.00 << endl;

				invGotoxy(27,19);
				cout << 1 << endl;
				
				cantidad = "1";

				invGotoxy(40,20);
				getline(cin, fechaDevolucion);

				invGotoxy(30,21);
				cout << date << endl;

				invGotoxy(23,22);
				cout << "No aplica debido a prestamo" << endl;
			}

				double grandTotal;
				int cantidadParsed;
				
				invGotoxy(12,25);
				if(tolower(transaction) == 'v'){
					
					std::istringstream (trim(cantidad)) >> cantidadParsed;
					if(cantidadParsed == 0){
						grandTotal = 0;
						cout << 0.00 << endl;	
					}else{
						grandTotal = cantidadParsed * aux.getPrice();
						cout << grandTotal << endl;						
					}
				}else{
					std::istringstream (trim(cantidad)) >> cantidadParsed;
					grandTotal = 0;
					cout << 0.00 << endl;
				}
				
				invGotoxy(64,25);
				if(tolower(transaction) == 'v'){
					grandTotal += (grandTotal*0.12);
					cout << grandTotal << endl;
				}else{
					grandTotal = 0;
					cout << 0.00 << endl;
				}
				
				invGotoxy(29,27);
				cin >> option;
				
				if(tolower(option) == 's'){
					validateBorrowForm(aux, clientName, clientAddress, telefono, nit, transaction, cantidadParsed, fechaDevolucion, fechaPrestamo, correo, grandTotal, rol);	
				}else{
					borrowABook(rol);
				}
				
				

}

void InventoryModule::validateBorrowForm(Book book, string clientName, string ClientAddress, string telefono, string nit, char transaction, int cantidad, string fechaDevolucion, string fechaPrestamo, string correo, double grandTotal, int rol){
	
	bool cn = false;
	bool cc = false;
	bool fd = false;
	int errorCounter = 0;
	
	Selling selling = Selling();
	
	if(clientName.size() > 0 ) {
		selling.setClientName(clientName);
		invGotoxy(82,11);
		cout << "|  STATUS: CAMPO VALIDO  |" << endl;
	}else{
		invGotoxy(0,11);
		cout << "| Nombre del cliente (*):                                                         |  STATUS: CAMPO VACIO   |" << endl;
		cn = true;
		errorCounter += 1;
	}
	
	if(ClientAddress.size() > 0){
		selling.setClientAddress(ClientAddress);
	}else{
		selling.setClientAddress("Ciudad");
	}
	
	
	if(telefono.size() > 0){
		selling.setTelefono(telefono);
	}else{
		selling.setTelefono("Sin telefono");
	}
	
	if(nit.size() > 0){
		selling.setNit(nit);
	}else{
		selling.setNit("C/F");
	}
	
	
	selling.setTransaction(std::to_string(transaction));
	
	if(cantidad <= book.getStock()){
		if(cantidad != 0){
			selling.setCantidad(cantidad);
			invGotoxy(82,19);
			cout << "| STATUS: CAMPO VALIDO   |" << endl;	
		}else{
			cc = true;
			errorCounter += 1;
			invGotoxy(0,19);
			cout << "| Cantidad solicitada (*):                                                        |  STATUS: CANTIDAD ES 0 |" << endl;
		}
		
	}else{
		cc = true;
		errorCounter += 1;
		invGotoxy(0,19);
		cout << "| Cantidad solicitada (*):                                                        |  STATUS: STOCK EXCEDIDO|" << endl;
	}
	
	if(transaction == 'v'){
		selling.setFechaDevolucion("Sin fecha debido a venta");
		invGotoxy(0,20);
		cout << "| Fecha de devolucion (si es alquiler): Sin fecha debido a ser venta              |  STATUS: CAMPO VALIDO  |" << endl;
	}else{
		if(fechaDevolucion.size() > 0){
			selling.setFechaDevolucion(fechaDevolucion);
			invGotoxy(82,20);
			cout << "|  STATUS: CAMPO VALIDO  |" << endl;
		}else{
			fd = true;
			errorCounter += 1;
			invGotoxy(0,20);
			cout << "| Fecha de devolucion (si es alquiler):                                           |  STATUS: SIN FECHA     |" << endl;
		}	
	}
	
	
	
	if(fechaPrestamo.size() > 0){
		selling.setFechaPrestamo(fechaPrestamo);
	}else{
		selling.setFechaPrestamo("");
	}
	
	
	if(correo.size() > 0){
		selling.setCorreo(correo);
	}else{
		selling.setCorreo("Sin correo Registrado");
	}
	
	selling.setGrandTotal(grandTotal);
	selling.setRentBook(book);
	
	if(errorCounter > 0){
		fixFormBorrowData(cn,cc,fd, book, clientName, ClientAddress, telefono, nit, transaction, cantidad, fechaDevolucion, fechaPrestamo, correo, grandTotal, rol);
	}else{
		BinFilesHandler bfh = BinFilesHandler();
		string opt;
		
		if(bfh.writeBinacleFile(selling)){
			
			vector<Book> aux = bfh.readALLInventory();
			cin.ignore();
			for(int x = 0; x < aux.size(); x++){
				if(book.getBookTitle() == aux[x].getBookTitle()){
					book.setStock(book.getStock()-cantidad);
					aux[x] = book;
					
					if(bfh.editOnInventory(aux)){
						invGotoxy(0,27);
						cout << "| Se proceso la transaccion escriba 'S' para continuar:                                                    |" << endl;
						invGotoxy(56,27);
						cin >> opt;
					}else{
						invGotoxy(0,27);
						cout << "| No se ha logrado procesar la transaccion escriba culquier cosa para continuar:                           |" << endl;
						
						invGotoxy(81,27);
						cin >> opt;
					}
					if(opt.size() > 0 ){
						displayAllEntrys(1);
					}else{
						displayInventoryModuleOperator();
					}
					
				}else{
					continue;
				}
			}
			
		}else{
			invGotoxy(0,27);
			cout << "| No se ha logrado procesar la transaccion escriba culquier cosa para continuar:                           |" << endl;
			
			invGotoxy(81,27);
			cin >> opt;
			
			if(opt.size() > 0 ){
				displayInventoryModuleOperator();
			}else{
				displayInventoryModuleOperator();
			}
		}
	}
	
}


void InventoryModule::fixFormBorrowData(bool clientNameb, bool cantidadb, bool fechaDevolucionb, Book book, string clientName, string clientAddress, string telefono, string nit, char transaction, int cantidad, string fechaDevolucion, string fechaPrestamo, string correo, double grandTotal, int rol){
	
	string cnFix;
	string fdFix;
	int ccFix;
	
	cin.ignore();
	
	if(clientNameb){
		invGotoxy(26,11);
		getline(cin, cnFix);
	}else{
		cnFix = clientName;
	}
	
	if(cantidadb){
		invGotoxy(27,19);
		cin >> ccFix;
	}else{
		ccFix = cantidad;
	}
	
	if(fechaDevolucionb){
		invGotoxy(23,20);
		getline(cin, fdFix);
	}else{
		fdFix = fechaDevolucion;
	}
	
	char option;
	
	invGotoxy(0,27);
	cout << "| Informacion correcta? S/N:                                                                               |" << endl;
	
	invGotoxy(29,27);
	cin >> option;
				
	if(tolower(option) == 's'){
		validateBorrowForm(book, cnFix, clientAddress, telefono, nit, transaction, ccFix, fdFix, fechaPrestamo, correo, grandTotal, rol);	
	}else{
		borrowABook(rol);
	}
	
}


