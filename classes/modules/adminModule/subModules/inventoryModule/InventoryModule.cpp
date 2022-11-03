#include "InventoryModule.h"
#include "../../../../Book.h"
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
					displayAllEntrys();
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
					addEntryToInventory();
				break;
			}

			case 2:{
					displayAllEntrys();
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
					addEntryToInventory();
				break;
			}

			case 2:{
					displayAllEntrys();
				break;
			}
			
			case 3:{
					editEntryOfInventory();
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

void InventoryModule::addEntryToInventory(){
	
	
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
		InventoryModule::validateForm(title, autor, category, descVector, editorial, anio, pages, price, stock, false);
	}else{
		displayModule();	
	}
	
	
}

void InventoryModule::validateForm(string title, string autor, string category, vector<string> desc, string editorial, string anio, string pages, string price, string stock, bool isEdit){
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
	 		fixFormData(b1,b2,b3,b4,b5,b6,b7,b8,b9, title, autor, category, desc, editorial, anio, pages, price, stock, true);	
		}else{
			fixFormData(b1,b2,b3,b4,b5,b6,b7,b8,b9, title, autor, category, desc, editorial, anio, pages, price, stock, false);
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
			InventoryModule::editEntryOfInventory();	
		}else{

			char opt2;
			
			vector<Book> booksTovalidate = bfh.readALLInventory();
			
			for(int x = 0; x < booksTovalidate.size(); x++){
				Book aux = booksTovalidate[x];
				if(book.getBookTitle() == aux.getBookTitle()){
					throwAlert(booksTovalidate, x);
				}
			}
	
			if(bfh.writeOnInventory(book)){
				invGotoxy(0,18);
				cout << "| Libro agregado al inventario con exito, agregar otro? S/N:              | FORMULARIO:  FINALIZADO   |";
	
				invGotoxy(61,18);
				cin >> opt2;
	
				if(toupper(opt2) == 'S' || tolower(opt2) == 's'){
					invGotoxy(0,0);
					InventoryModule::addEntryToInventory();	
				}else{
					displayModule();
				}
			}		
		}

	
	}
	
}

void InventoryModule::throwAlert(vector<Book> books, int index){
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
	
	editEntry(books, index);
	
}

void InventoryModule::fixFormData(bool title, bool autor, bool category, bool desc, bool editorial, bool anio, bool pages, bool price, bool stock, string a, string b,string c, vector<string> d, string e, string f, string g, string h, string i, bool editMode){
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
			InventoryModule::validateForm(titleFix, autorFix, categoryFix, descVector, editorialFix, anioFix, pagesFix, priceFix, stockFix, true);
		}		
	}else{
		if(toupper(optionFix) == 'S' || tolower(optionFix) == 's'){
			invGotoxy(0,18);
			InventoryModule::validateForm(titleFix, autorFix, categoryFix, descVector, editorialFix, anioFix, pagesFix, priceFix, stockFix, false);
		}	
	}
	

}

void InventoryModule::displayAllEntrys(){
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
	
	displayModule();
	
}


void InventoryModule::editEntryOfInventory(){
	
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<Book> books = bfh.readALLInventory();
		
		string opt;
		
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                                          BIBLIOTECA EL PORVENIR                                                                            |" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                               EDITAR REGISTRO DEL LISTADO DE REGISTROS BIBLIOTECA                                                          |" << endl;
		cout << "+----------------------------+-----------------+------------------+-------------------+--------------------+-------------------+-------------------------+-------------------+" << endl;
		cout << "|           Titulo           |      Autor      |    Categorias    |     Editorial     | A�o de Publicacion | Numero de Paginas | Precio venta o Alquiler | Cantidad en Stock |" << endl;
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
				editEntry(books, y);
			}
		}	
		
		displayModule();
}

void InventoryModule::editEntry(vector<Book> books, int index){
	
	
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
			"| Confirmar edicion S/N:                                                 | FORMULARIO:                |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
	<< endl;
	
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
	
	invGotoxy(23,15);
	cout << preview.getPrice()<<endl;  
	
	invGotoxy(36,16);
	cout << preview.getStock()<<endl;  
	
	invGotoxy(25,18);
	cin >> option;

	if(toupper(option) == 'S' || tolower(option) == 's'){
		system("CLS");
		cout << "+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
	            "|                         BIBLIOTECA EL PORVENIR                         |        INFORMACION ACTUAL       |         VALIDACIONES       |\n" 
	            "+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
	            "|                      EDITAR ENTRADA AL INVENTARIO                      |                                 |                            |\n"
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
				"| Confirmar esta edicion S/N:                                            |                                 | FORMULARIO:                |\n"
				"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
		<< endl;
		
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
		
		invGotoxy(81,15);
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
		
		invGotoxy(30,18);
		cin >> option;
	
		if(toupper(option) == 'S' || tolower(option) == 's'){
			InventoryModule::editingVector = books;
			indexvector = index;
			InventoryModule::validateForm(title, autor, category, descVector, editorial, anio, pages, price, stock, true);
		}else{
			editEntryOfInventory();	
		}
	}else{
		editEntryOfInventory();
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
		cout << "|           Titulo           |      Autor      |    Categorias    |     Editorial     | A�o de Publicacion | Numero de Paginas | Precio venta o Alquiler | Cantidad en Stock |" << endl;
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
