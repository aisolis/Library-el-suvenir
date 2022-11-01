#include "InventoryModule.h"
#include "../../../../Book.h"
#include "../../../../BinFilesHandler.h"
#include "../../AdminPanel.h"

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

void InventoryModule::displayModule(){
	
	int optionMenu;

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
		cin >> optionMenu;

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
					BinFilesHandler bfh = BinFilesHandler();
					system("CLS");
					bfh.cleanFile();
				break;
			}
		}
		
	invGotoxy(0,30);
}

void InventoryModule::addEntryToInventory(){
	
	
	vector<string> descVector;
	string title;
	string autor;
	string description;
	string editorial;
	string anio;
	string pages;
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
			"| Descripcion del libro:                                                 | STATUS:                    |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"| Nombre de la editorial:                                                | STATUS:                    |\n"
			"| Anio de publicacion:                                                   | STATUS:                    |\n"
			"| Numero de paginas:                                                     | STATUS:                    |\n"
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
	counter = 7;
	while (getline(cin, description))
    {	invGotoxy(2,++counter);
        if (description.empty()) {        	
            break;
        }
        descVector.push_back(description);
    }
	
	invGotoxy(26,11);
	getline(cin, editorial);
	
	invGotoxy(23,12);
	getline(cin, anio);
	
	invGotoxy(21,13);
	getline(cin, pages);
	
	invGotoxy(36,14);
	getline(cin, stock);
	
	invGotoxy(28,16);
	cin >> option;

	if(toupper(option) == 'S' || tolower(option) == 's'){
		invGotoxy(0,18);
		InventoryModule::validateForm(title, autor, descVector, editorial, anio, pages, stock, false);
	}else{
		displayModule();	
	}
	
	
}

void InventoryModule::validateForm(string title, string autor, vector<string> desc, string editorial, string anio, string pages, string stock, bool isEdit){
	Book book = Book();

	int errorCount;
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	bool b4 = false;
	bool b5 = false;
	bool b6 = false;
	bool b7 = false;
	
	if(title.size() > 0){
		book.setBookTitle(title);
		invGotoxy(83,5);
		cout<<"OK: CAMPO VALIDO   ";
	}else{
		invGotoxy(0,5);
		cout << "| Nombre del libro:                                                      | STATUS: ERROR: CAMPO VACIO!|";
		errorCount += 1;
		b1 = true;
	}

	if(autor.size() > 0){
		book.setAutor(autor);
		invGotoxy(83,6);
		cout<<"OK: CAMPO VALIDO   ";
	}else{
		invGotoxy(0,6);
		cout << "| Nombre del Autor:                                                      | STATUS: ERROR: CAMPO VACIO!|";
		errorCount += 1;
		b2 = true;
	}

	if(desc.size() > 0){
		book.setDescription(desc);
		invGotoxy(83,7);
		cout<<"OK: CAMPO VALIDO   ";
	}else{
		invGotoxy(0,7);
		cout << "| Descripcion del libro:                                                 | STATUS: ERROR: CAMPO VACIO!|\n"
		        "|                                                                        |                            |\n"
				"|                                                                        |                            |";
		errorCount += 1;
		b3 = true;
	}

	if(editorial.size() > 0){
		book.setEditorial(editorial);
		invGotoxy(83,11);
		cout<<"OK: CAMPO VALIDO   ";
	}else{
		invGotoxy(0,11);
		cout << "| Nombre de la editorial:                                                | STATUS: ERROR: CAMPO VACIO!|";
		errorCount += 1;
		b4 =  true;
	}

	if(anio.size() > 0){
		int parsedYear;
		std::istringstream (trim(anio)) >> parsedYear;
		if(parsedYear !=0){
			book.setPublicationYear(parsedYear);
			invGotoxy(83,12);
			cout<<"OK: CAMPO VALIDO   ";
		}else{
			invGotoxy(0,12);
			cout << "| Anio de publicacion:                                                   | STATUS: ERROR: SOLO NUMEROS|";
			errorCount += 1;
			b5 = true;	
		}
	}else{
		invGotoxy(0,12);
		cout << "| Anio de publicacion:                                                   | STATUS: ERROR: CAMPO VACIO!|";
		errorCount += 1;
		b5 = true;	
	}

	if(pages.size() > 0){
		int parsedPage;
		std::istringstream (trim(pages)) >> parsedPage;
		if(parsedPage !=0){
			book.setPagesNumbers(parsedPage);
			invGotoxy(83,13);
			cout<<"OK: CAMPO VALIDO   ";
		}else{
			invGotoxy(0,13);
			cout << "| Numero de paginas:                                                     | STATUS: ERROR: SOLO NUMEROS|";
			errorCount += 1;	
			b6 = true;	
		}
	}else{
		invGotoxy(0,13);
		cout << "| Numero de paginas:                                                     | STATUS: ERROR: CAMPO VACIO!|";
		errorCount += 1;
		b6 = true;	
	}

	if(stock.size() > 0){
		int parsedStock;
		std::istringstream (trim(stock)) >> parsedStock;
		book.setStock(parsedStock);
		if(parsedStock !=0){
			book.setStock(parsedStock);
			invGotoxy(83,14);
			cout<<"OK: CAMPO VALIDO   ";
		}else{
			invGotoxy(0,14);
			cout << "| Cantidad de existencias en stock:                                      | STATUS: ERROR: SOLO NUMEROS|";
			errorCount += 1;
			b7 = true;	
		}
	}else{
		invGotoxy(0,14);
		cout << "| Cantidad de existencias en stock:                                      | STATUS: ERROR: CAMPO VACIO!|";
		errorCount += 1;
		b7 = true;	
	}

	if(errorCount > 0){
		invGotoxy(0,16);
		cout << "| Confirmar Creacion: S/N:                                               | FORMULARIO:                |";

		invGotoxy(87,16);
		cout << "INVALIDO";
		fixFormData(b1,b2,b3,b4,b5,b6,b7, title, autor, desc, editorial, anio, pages, stock);

	}else{
		invGotoxy(87,16);
		cout << "VALIDO";
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
					invGotoxy(0,16);
					cout << "| Libro editado en el inventario con exito, aceptar? S:                   | FORMULARIO:  FINALIZADO   |";
		
					invGotoxy(56,16);
					cin >> opt2;	
				}	
			}else{
				while(toupper(opt2) != 'S'){
				invGotoxy(0,16);
				cout << "| Libro no editado en el inventario, aceptar S:                            | FORMULARIO:  CON ERROR   |";
	
				invGotoxy(56,16);
				cin >> opt2;	
				}
			}
			invGotoxy(0,0);
			InventoryModule::editEntryOfInventory();	
		}else{

			char opt2;
	
			if(bfh.writeOnInventory(book)){
				invGotoxy(0,16);
				cout << "| Libro agregado al inventario con exito, agregar otro? S/N:              | FORMULARIO:  FINALIZADO   |";
	
				invGotoxy(61,16);
				cin >> opt2;
	
				if(toupper(opt2) == 'S' || tolower(opt2) == 's'){
					invGotoxy(0,0);
					InventoryModule::addEntryToInventory();	
				}
			}		
		}

	
	}
	
}

void InventoryModule::fixFormData(bool title, bool autor, bool desc, bool editorial, bool anio, bool pages, bool stock, string a, string b, vector<string> c, string d, string e, string f, string g){
	vector<string> descVector;
	string titleFix;
	string autorFix;
	string descriptionFix;
	string editorialFix;
	string anioFix;
	string pagesFix;
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
	
	if(desc){
		invGotoxy(25,7);
		counterFix = 7;
		while (getline(cin, descriptionFix))
		{	invGotoxy(2,++counterFix);
			if (descriptionFix.empty()) {        	
				break;
			}
			descVector.push_back(descriptionFix);
		}
	}else{
		descVector = c;
	}
	
	if(editorial){
		invGotoxy(26,11);
		getline(cin, editorialFix);
	}else{
		editorialFix = d;
	}
	
	if(anio){
		invGotoxy(23,12);
		getline(cin, anioFix);
	}else{
		anioFix = e;
	}
	
	if(pages){
		invGotoxy(21,13);
		getline(cin, pagesFix);
	}else{
		pagesFix = f;
	}
	
	if(stock){
		invGotoxy(36,14);
		getline(cin, stockFix);
	}else{
		stockFix = g;
	}

	invGotoxy(28,16);
	cin >> optionFix;

	if(toupper(optionFix) == 'S' || tolower(optionFix) == 's'){
		invGotoxy(0,18);
		InventoryModule::validateForm(titleFix, autorFix, descVector, editorialFix, anioFix, pagesFix, stockFix, false);
	}

}

void InventoryModule::displayAllEntrys(){
		system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<Book> books = bfh.readALLInventory();
		
		char opt;
		
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                              BIBLIOTECA EL PORVENIR                                                       |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                           LISTADO DE REGISTROS BIBLIOTECA                                                 |" << endl;
		cout << "+----------------------------+-----------------+---------------+--------------------+-------------------+-------------------+" << endl;
		cout << "|           Titulo           |      Autor      |   Editorial   | A�o de Publicacion | Numero de Paginas | Cantidad en Stock |" << endl;
		cout << "+----------------------------+-----------------+---------------+--------------------+-------------------+-------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < books.size(); x++){
		Book tmpB = books[x];
		
		invGotoxy(0,(firstLine));
		cout << "|" << endl;
		invGotoxy(2,(firstLine));
		cout <<	truncate(tmpB.getBookTitle(),23, true);
		
		
		invGotoxy(29,(firstLine));
		cout << "|" << endl;
		invGotoxy(31,(firstLine));
		cout <<	truncate(tmpB.getAutor(),23, true);
		
		
		invGotoxy(47,(firstLine));
		cout << "|" << endl;
		invGotoxy(49,(firstLine));
		cout <<	truncate(tmpB.getEditorial(),23, true);
		
		
		invGotoxy(63,(firstLine));
		cout << "|" << endl;
		invGotoxy(65,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPublicationYear()),23, true);
		
		
		invGotoxy(84,(firstLine));
		cout << "|" << endl;
		invGotoxy(86,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPagesNumbers()),23, true);
		
		
		invGotoxy(104,(firstLine));
		cout << "|" << endl;
		invGotoxy(106,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getStock()),23, true);
		invGotoxy(124,(firstLine));
		cout << "|" << endl;
		cout << "+----------------------------+-----------------+---------------+--------------------+-------------------+-------------------+" <<endl;
		
		firstLine += 2;
	}
		
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Desea regresar al menu principal? S/N                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                                |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;

	while(toupper(opt) != 'S'){
		invGotoxy(0,firstLine+3);
		cout << "| Su opcion:                                                                                                                |" << endl;	
		invGotoxy(13,firstLine+3);
		cin >> opt;	
	}
	
	displayModule();
	
}


void InventoryModule::editEntryOfInventory(){
	
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<Book> books = bfh.readALLInventory();
		
		string opt;
		
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                              BIBLIOTECA EL PORVENIR                                                       |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                           LISTADO DE REGISTROS BIBLIOTECA                                                 |" << endl;
		cout << "+----------------------------+-----------------+---------------+--------------------+-------------------+-------------------+" << endl;
		cout << "|           Titulo           |      Autor      |   Editorial   | A�o de Publicacion | Numero de Paginas | Cantidad en Stock |" << endl;
		cout << "+----------------------------+-----------------+---------------+--------------------+-------------------+-------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < books.size(); x++){
		Book tmpB = books[x];
		
		invGotoxy(0,(firstLine));
		cout << "|" << endl;
		invGotoxy(2,(firstLine));
		cout <<	truncate(tmpB.getBookTitle(),23, true);
		
		
		invGotoxy(29,(firstLine));
		cout << "|" << endl;
		invGotoxy(31,(firstLine));
		cout <<	truncate(tmpB.getAutor(),23, true);
		
		
		invGotoxy(47,(firstLine));
		cout << "|" << endl;
		invGotoxy(49,(firstLine));
		cout <<	truncate(tmpB.getEditorial(),23, true);
		
		
		invGotoxy(63,(firstLine));
		cout << "|" << endl;
		invGotoxy(65,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPublicationYear()),23, true);
		
		
		invGotoxy(84,(firstLine));
		cout << "|" << endl;
		invGotoxy(86,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getPagesNumbers()),23, true);
		
		
		invGotoxy(104,(firstLine));
		cout << "|" << endl;
		invGotoxy(106,(firstLine));
		cout <<	truncate(std::to_string(tmpB.getStock()),23, true);
		invGotoxy(124,(firstLine));
		cout << "|" << endl;
		cout << "+----------------------------+-----------------+---------------+--------------------+-------------------+-------------------+" <<endl;
		
		firstLine += 2;
	}
		cout << "| Escriba el nombre del libro que desea editar o escriba cancelar para volver al menu principal                             |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Titulo del Libro:                                                                                                         |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------------+" << endl;
		invGotoxy(20,firstLine+2);
		cin.ignore();	
		
		getline(cin, opt);
		
		if(opt != "cancelar"){
			for(int y = 0; y < books.size();y++){
				if(opt == books[y].getBookTitle()){
					editEntry(books, y);
				}
			}	
		}else{
			displayModule();
		}
		
}

void InventoryModule::editEntry(vector<Book> books, int index){
	
	
	vector<string> descVector;
	string title;
	string autor;
	string description;
	string editorial;
	string anio;
	string pages;
	string stock;
	
	char option;
	int counter;
	
	
	system("CLS");
	cout << "+------------------------------------------------------------------------+----------------------------+\n"
            "|                         BIBLIOTECA EL PORVENIR                         |         VALIDACIONES       |\n" 
            "+------------------------------------------------------------------------+----------------------------+\n"
            "|                      EDITAR ENTRADA AL INVENTARIO                      |  VALIDACION DE FORMULARIO  |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"| Nombre del libro:                                                      | STATUS:                    |\n"
			"| Nombre del Autor:                                                      | STATUS:                    |\n"
			"| Descripcion del libro:                                                 | STATUS:                    |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"|                                                                        |                            |\n"
			"| Nombre de la editorial:                                                | STATUS:                    |\n"
			"| Anio de publicacion:                                                   | STATUS:                    |\n"
			"| Numero de paginas:                                                     | STATUS:                    |\n"
			"| Cantidad de existencias en stock:                                      | STATUS:                    |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"| Editar esta entrada S/N:                                               | FORMULARIO:                |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
	<< endl;
	
	Book preview = books[index];
	
	invGotoxy(20,5);
	cout << preview.getBookTitle()<<endl;
	
	
	invGotoxy(20,6);
	cout << preview.getAutor()<<endl;
	
	invGotoxy(25,7);
	int counter2 = 7;
	vector<string> desc;
	for(int u = 0; u < desc.size(); u++){
		if(u > 0){
			invGotoxy(25,7);	
			cout << desc[u]<<endl;
		}else{
			invGotoxy(2,++counter2);	
			cout << desc[u]<<endl;
		}		
	}
	
	invGotoxy(26,11);
	cout << preview.getEditorial()<<endl;  
	
	invGotoxy(23,12);
	cout << preview.getPublicationYear()<<endl;  
	
	invGotoxy(21,13);
	cout << preview.getPagesNumbers()<<endl;  
	
	invGotoxy(36,14);
	cout << preview.getStock()<<endl;  
	
	invGotoxy(27,16);
	cin >> option;

	if(toupper(option) == 'S' || tolower(option) == 's'){
		system("CLS");
		cout << "+------------------------------------------------------------------------+----------------------------+\n"
	            "|                         BIBLIOTECA EL PORVENIR                         |         VALIDACIONES       |\n" 
	            "+------------------------------------------------------------------------+----------------------------+\n"
	            "|                      EDITAR ENTRADA AL INVENTARIO                      |  VALIDACION DE FORMULARIO  |\n"
				"+------------------------------------------------------------------------+----------------------------+\n"
				"| Nombre del libro:                                                      | STATUS:                    |\n"
				"| Nombre del Autor:                                                      | STATUS:                    |\n"
				"| Descripcion del libro:                                                 | STATUS:                    |\n"
				"|                                                                        |                            |\n"
				"|                                                                        |                            |\n"
				"|                                                                        |                            |\n"
				"| Nombre de la editorial:                                                | STATUS:                    |\n"
				"| Anio de publicacion:                                                   | STATUS:                    |\n"
				"| Numero de paginas:                                                     | STATUS:                    |\n"
				"| Cantidad de existencias en stock:                                      | STATUS:                    |\n"
				"+------------------------------------------------------------------------+----------------------------+\n"
				"| Confirmar esta edicion S/N:                                            | FORMULARIO:                |\n"
				"+------------------------------------------------------------------------+----------------------------+\n"
		<< endl;
		
		invGotoxy(22,5);
		cin.ignore();
		getline(cin, title);
		
		invGotoxy(20,6);
		getline(cin, autor);
		
		invGotoxy(25,7);
		counter = 7;
		while (getline(cin, description))
	    {	invGotoxy(2,++counter);
	        if (description.empty() || counter) {        	
	            break;
	        }
	        descVector.push_back(description);
	    }
		
		invGotoxy(26,11);
		getline(cin, editorial);
		
		invGotoxy(23,12);
		getline(cin, anio);
		
		invGotoxy(21,13);
		getline(cin, pages);
		
		invGotoxy(36,14);
		getline(cin, stock);
		
		invGotoxy(30,16);
		cin >> option;
	
		if(toupper(option) == 'S' || tolower(option) == 's'){
			InventoryModule::editingVector = books;
			indexvector = index;
			InventoryModule::validateForm(title, autor, descVector, editorial, anio, pages, stock, true);
		}else{
			editEntryOfInventory();	
		}
	}else{
		editEntryOfInventory();
	}
	
	
}
