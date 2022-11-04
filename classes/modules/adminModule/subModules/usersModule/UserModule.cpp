#include "UserModule.h"
#include "../../../../BinFilesHandler.h"
#include "../../../../User.h"
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


const std::string WHITESPACEU = " \n\r\t\f\v";
 
std::string ultrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACEU);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string urtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACEU);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string utrim(const std::string &s) {
    return urtrim(ultrim(s));
}

COORD userCoord = {0,0};

void userGotoxy(int x, int y){
	userCoord.X = x;
	userCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),userCoord);
}


UserModule::UserModule(){
	
}

void UserModule::displayModuleSupervisor(){
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                              BIBLIOTECA EL PORVENIR                                                 |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                MODULO DE USUARIOS                                                   |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Supervisor                                                                           |" << endl;
		cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Listar todos los usuarios                                                                                        |" << endl;
		cout << "| 2) Volver al menu anterior                                                                                          |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		userGotoxy(13,19);
		cin >> parser;


		std::istringstream (parser) >> optionMenu;
		
		switch(optionMenu){
			case 1:{
				displayUsers(2);
				break;
			}

			case 2:{
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
		
	userGotoxy(0,30);
}

void UserModule::displayModule(){
	int optionMenu;
	string parser;

	system("CLS");
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                              BIBLIOTECA EL PORVENIR                                                 |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "|                                                MODULO DE USUARIOS                                                   |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Bienvenido nuevamente estimado Administrador                                                                        |" << endl;
		cout << "| Por favor elija una opcion del siguiente menu:                                                                      |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "| 1) Agregar nuevos usuarios                                                                                          |" << endl;
		cout << "| 2) Editar un usuario                                                                                                |" << endl;
		cout << "| 3) Eliminar un usuario                                                                                              |" << endl;
		cout << "| 4) Listar todos los usuarios                                                                                        |" << endl;
		cout << "| 5) Regresar al menu anterior                                                                                        |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "|                                                                                                                     |" << endl;
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Para ingresar presiona enter...                                                                                     |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                                                                          |" << endl;	
		cout << "+---------------------------------------------------------------------------------------------------------------------+" << endl;

		userGotoxy(13,19);
		cin >> parser;


		std::istringstream (parser) >> optionMenu;
		
		switch(optionMenu){
			case 1:{
				addNewUsers();
				break;
			}

			case 2:{
				updateUsers();
				break;
			}
			
			case 3:{
				deleteUsers();
				break;
			}
			
			case 4:{
				displayUsers(3);
				break;
			}
			
			case 5:{
				AdminPanel ap = AdminPanel();
				ap.displayPanelAdmin();
				break;
			}
			
			
			default:{
				displayModule();
				break;
			}
		}
		
	userGotoxy(0,30);	
}


void UserModule::addNewUsers(){
	system("CLS");
	string usuario;
	string password;
	string rol;
	char opt;
	
	cout << "+------------------------------------------------------------------------+----------------------------+\n"
            "|                         BIBLIOTECA EL PORVENIR                         |         VALIDACIONES       |\n" 
            "+------------------------------------------------------------------------+----------------------------+\n"
            "|                      AGREGAR USUARIO AL SISTEMA                        |  VALIDACION DE FORMULARIO  |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"|                                                                        |                            |\n"
			"| Por favor introduzca el nombre de usuario, el usuario sera validado al |                            |\n"
			"| confirmar la creacion del mismo, si el usuario es unico se procedera a |                            |\n"
			"| la creacion.                                                           |                            |\n"
			"|                                                                        |                            |\n"
			"|                               Roles disponibles                        |                            |\n"
			"|                                                                        |                            |\n"
			"|             0) Operador     1) supervisor   2) Administrador           |                            |\n"
			"|                                                                        |                            |\n"
			"| Nombre de usuario:                                                     | STATUS:                    |\n"
			"| Contraseï¿½a:                                                            | STATUS:                    |\n"
			"| Rol:                                                                   | STATUS:                    |\n"
			"|                                                                        |                            |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"| Confirmar creacion S/N:                                                | FORMULARIO:                |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
	<< endl;
	
	cin.ignore();
	
	userGotoxy(21,14);
	getline(cin, usuario);
	
	userGotoxy(14,15);
	getline(cin, password);
	
	userGotoxy(7,16);
	getline(cin, rol);
	
	userGotoxy(26,19);
	
	cin >> opt;
	
	if(tolower(opt) == 's'){
		validateForm(usuario, password, rol, false);
	}else{
		displayModule();
	}
}



void UserModule::validateForm(string user, string pwd, string rol, bool isEdit){
	
	bool userb;
	bool pwdb;
	bool rolb;
	
	User userObj = User();
	int errorCounter = 0;
	
	BinFilesHandler bfh = BinFilesHandler();
	User aux = bfh.searchUser(user);
	
	
	if(user.size() > 0){
		if(!isEdit){
			if(aux.getUser().size() > 0){
			userGotoxy(0,14);
			cout << "| Nombre de usuario:                                                     | STATUS ERR: USUARIO TOMADO |\n" << endl;
			
			userb = true;
			errorCounter += 1;
			}else{
				userGotoxy(73,14);
				cout << "| STATUS OK: CAMPO VALIDO!   |";
				userObj.setUser(user);
			}	
		}else{
			userObj.setUser(user);
		}
	}else{
		userGotoxy(73,14);
		cout << "| STATUS ERROR: CAMPO VACIO! |";
		
		userb = true;
		errorCounter += 1;
		
	}
	
	
	if(pwd.size() > 0){
		if(isEdit){
			userGotoxy(107,15);
			cout << "| STATUS OK: CAMPO VALIDO!   |";
		}else{
			userGotoxy(73,15);
			cout << "| STATUS OK: CAMPO VALIDO!   |";
		}
		userObj.setPassword(pwd);
	}else{
		if(isEdit){
			userGotoxy(107,15);
			cout << "| STATUS ERROR: CAMPO VACIO! |";
		}else{
			userGotoxy(73,15);
			cout << "| STATUS ERROR: CAMPO VACIO! |";
			
			pwdb = true;
			errorCounter += 1;	
		}
	}
	
	
	
	if(rol.size() > 0){
		int rolParsed;
		std::istringstream (utrim(rol)) >> rolParsed;
		
		if(rolParsed == 1 || rolParsed == 2 || rolParsed == 3 ){
			if(isEdit){
				userGotoxy(107,16);
				cout << "| STATUS: OK: CAMPO VALIDO!  |";
			}else{
				userGotoxy(83,16);
				cout<<"OK: CAMPO VALIDO!  ";
			}
			userObj.setRol(rolParsed);		
		}else{
			if(isEdit){
				userGotoxy(0,16);
				  cout << "| Rol:                                                                   |";
				userGotoxy(107,16);
				cout << "| STATUS ERROR: ROL INVALIDO |\n";
			}else{
				userGotoxy(0,16);
				cout << "| Rol:                                                                   | STATUS ERROR: ROL INVALIDO |";
			}	
			
			errorCounter += 1;
			rolb = true;
		}
		
	}else{
		if(isEdit){
			userGotoxy(0,16);
			cout << "| Rol:                                                                   |";
			userGotoxy(107,16);
			cout << "| STATUS: ERROR: CAMPO VACIO!|";
		}else{
			userGotoxy(0,16);
			cout << "| Rol:                                                                   | STATUS ERROR: CAMPO VACIO! |";	
		}	
		
		errorCounter += 1;
		rolb = true;
	}
	
	if(errorCounter > 0){
		if(isEdit){
			userGotoxy(0,19);
			cout << "| Confirmar esta edicion S/N:                                            |                                 | FORMULARIO:                |\n";
			userGotoxy(121,19);
			cout << "INVALIDO";
			fixFormData(userb, pwdb, rolb, user, pwd, rol, true);
		}else{
			userGotoxy(0,19);
			cout << "| Confirmar Creacion: S/N:                                               | FORMULARIO:                |";	
			userGotoxy(87,19);
			cout << "INVALIDO";
			fixFormData(userb, pwdb, rolb, user, pwd, rol, false);
		}
		
	}else{
		if(isEdit){
			User aux = editingVector[indexvector];
			editingVector[indexvector] = userObj;
			
			char opt2;
			
			if(bfh.editOnUser(editingVector)){
				while(toupper(opt2) != 'S'){
					userGotoxy(0,19);
					cout << "| Usuario editado en el inventario con exito, aceptar? S:                |                                 | FORMULARIO:  FINALIZADO    |";
		
					userGotoxy(58,19);
					cin >> opt2;	
				}	
			}else{
				while(toupper(opt2) != 'S'){
				userGotoxy(0,19);
				cout << "| Usuario no editado en el inventario con exito, aceptar? S:              |                                 | FORMULARIO:  CON ERROR    |";
	
				userGotoxy(56,18);
				cin >> opt2;	
				}
			}
			userGotoxy(0,0);
			UserModule::updateUsers();
		}else{
			userGotoxy(87,19);
			cout << "VALIDO";
			
			char opt2;
			
			if(bfh.writeUserFile(userObj)){
			userGotoxy(0,19);
				cout << "| Usuario agregado al listado con exito, agregar otro? S/N:               | FORMULARIO:  FINALIZADO   |";
	
				userGotoxy(60,19);
				cin >> opt2;
	
				if(toupper(opt2) == 'S' || tolower(opt2) == 's'){
					userGotoxy(0,0);
					UserModule::addNewUsers();
				}else{
					displayModule();
				}
			}else{
				cout << "| Usuario no agregado al listado con exito, aceptar? 'S':                  | FORMULARIO:  CON ERROR   |";	
				
				userGotoxy(58,19);
				cin >> opt2;
				
				if(toupper(opt2) == 'S' || tolower(opt2) == 's'){
					userGotoxy(0,0);
					UserModule::displayModule();
				}else{
					displayModule();
				}
			}
		}
		
	}
	
}

void UserModule::fixFormData(bool userb, bool pwdb, bool rolb, string user, string pwd, string rol, bool isEdit){
	
	
	string userFix;
	string pwdFix;
	string rolFix;
	
	char optionFix;
	
	cin.ignore();
	
	if(userb){
		userGotoxy(21,14);
		getline(cin, userFix);
	}else{
		userFix = user;
	}
	
	if(pwdb){
		userGotoxy(14,15);
		getline(cin, pwdFix);
	}else{
		pwdFix = pwd;
	}
	
	if(rolb){
		userGotoxy(7,16);
		getline(cin, rolFix);
	}else{
		rolFix = rol;
	}
	
	userGotoxy(26,19);
	cin >> optionFix;
	
	
	if(isEdit){
		if(tolower(optionFix) == 's'){
			userGotoxy(0,19);
			UserModule::validateForm(userFix, pwdFix, rolFix, true);
		}		
	}else{
		if(tolower(optionFix) == 's'){
			userGotoxy(0,19);
			UserModule::validateForm(userFix, pwdFix, rolFix, false);
		}	
	}
	
}


void UserModule::updateUsers(){
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<User> users = bfh.readAllUsers();
		
		string opt;
		
		cout << "+------------------------------------------------------------+" << endl;
		cout << "|                   BIBLIOTECA EL PORVENIR                   |" << endl;
		cout << "+------------------------------------------------------------+" << endl;
		cout << "|               ACTUALIZAR DE USUARIOS BIBLIOTECA            |" << endl;
		cout << "+-------------------------+---------------+------------------+" << endl;
		cout << "|    Nombre de Usuario    |      Rol      |      Hashcode    |" << endl;
		cout << "+-------------------------+---------------+------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < users.size(); x++){
		User tmpB = users[x];
		
		userGotoxy(0,(firstLine));
		cout << "|" << endl;
		userGotoxy(2,(firstLine));
		cout <<	tmpB.getUser();
		
		
		userGotoxy(26,(firstLine));
		cout << "|" << endl;
		userGotoxy(28,(firstLine));
		switch(tmpB.getRol()){
			case 1:{
				cout <<	"Operador";		
				break;
			}
			
			case 2:{
				cout << "Supervisor";
				break;
			}
			
			case 3:{
				cout << "Administrador";
				break;
			}
			
			default:{
				break;
			}
		}		
		
		userGotoxy(42,(firstLine));
		cout << "|" << endl;
		userGotoxy(44,(firstLine));
		cout <<	tmpB.getId();
		userGotoxy(61,(firstLine));
		cout << "|" << endl;
		cout << "+-------------------------+---------------+------------------+" <<endl;
		
		firstLine += 2;
	}
	
		cout << "| Escriba el nombre del usuario a edita o escriba 'cancelar' |" << endl;	
		cout << "| para volver al modulo de administracion de usuarios.       |" << endl;	
		cout << "+------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                 |" << endl;	
		cout << "+------------------------------------------------------------+" << endl;
		
		
		bool errorUser = false;
	restart:
		
		if(errorUser){
			userGotoxy(0,firstLine+3);			
			cout << "| Su opcion:                                                 |" << endl;	
			userGotoxy(13,firstLine+3);			
			getline(cin, opt);
			cout << "|USUARIO NO ENCONTRADO, POR FAVOR INTENTE NUEVAMENTE         |" << endl;	
			cout << "+------------------------------------------------------------+" << endl;	
		}
		
		cin.ignore();
		
		userGotoxy(13,firstLine+3);
		getline(cin, opt);
		
		std::for_each(opt.begin(), opt.end(), [](char & c){
	    c = ::tolower(c);
		});
		
		
		
		for(int y = 0; y < users.size();y++){
			
			string userCompare = users[y].getUser();
			
			std::for_each(userCompare.begin(), userCompare.end(), [](char & c){
		    	c = ::tolower(c);
			});
			
			if(opt == userCompare){
				editEntry(users, y);
			}else{
				continue;
			}
		}	
		
		displayModule();
		
			
}


void UserModule::editEntry(vector<User> users, int index){
	
	string defuser;
	string pwd;
	string rol;
	
	char option;
	int counter;
	
	
	system("CLS");
	cout << "+------------------------------------------------------------------------+----------------------------+\n"
            "|                         BIBLIOTECA EL PORVENIR                         |         VALIDACIONES       |\n" 
            "+------------------------------------------------------------------------+----------------------------+\n"
            "|                      EDITAR USUARIO DEL SISTEMA                        |  VALIDACION DE FORMULARIO  |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"|                                                                        |                            |\n"
			"| A continuacion se muestra el usuario a ser editador, por favor revise  |                            |\n"
			"| y confirme que desea editar este usuario, la contraseña por motivos de |                            |\n"
			"| Seguridad no es mostrada.                                              |                            |\n"
			"|                                                                        |                            |\n"
			"|                               Roles disponibles                        |                            |\n"
			"|                                                                        |                            |\n"
			"|             1) Operador     2) supervisor   3) Administrador           |                            |\n"
			"|                                                                        |                            |\n"
			"| Nombre de usuario:                                                     | STATUS:                    |\n"
			"| Contrasenia:                                                           | STATUS:                    |\n"
			"| Rol:                                                                   | STATUS:                    |\n"
			"|                                                                        |                            |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
			"| Quieres editar esta entrada S/N?:                                      | FORMULARIO:                |\n"
			"+------------------------------------------------------------------------+----------------------------+\n"
	<< endl;
	
	User preview = users[index];
	
	defuser = preview.getUser();
	userGotoxy(21,14);
	cout << preview.getUser()<<endl;
	
	userGotoxy(15,15);
	cout << "************" <<endl;
	
	userGotoxy(7,16);
	cout << preview.getRol()<<endl;
	
	userGotoxy(36,19);
	cin >> option;

	if(toupper(option) == 'S' || tolower(option) == 's'){
		system("CLS");
		cout << "+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
	            "|                         BIBLIOTECA EL PORVENIR                         |        INFORMACION ACTUAL       |         VALIDACIONES       |\n" 
	            "+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
	            "|                      EDITAR USUARIO DEL INVENTARIO                     |                                 |                            |\n"
				"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
				"|                                                                        |                                 |                            |\n"
				"| A continuacion se muestra el usuario a ser editador, por favor revise  |                                	|                            |\n"
				"| y confirme que desea editar este usuario, la contraseña por motivos de |                                 |                            |\n"
				"| Seguridad no es mostrada.                                              |                                 |                            |\n"
				"|                                                                        |                                 |                            |\n"
				"|                            Roles disponibles                           |                                 |                            |\n"
				"|                                                                        |                                 |                            |\n"
				"|             1) Operador     2) supervisor   3) Administrador           |                                 |                            |\n"
				"|                                                                        |                                 |                            |\n"
				"| Nombre de usuario:                                                     | PREV:                           | STATUS: NO MODIFICABLE     |\n"
				"| Contrasenia:                                                           | PREV:                           | STATUS:                    |\n"
				"| Rol:                                                                   | PREV:                           | STATUS:                    |\n"
				"|                                                                        |                                 |                            |\n"
				"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
				"| Confirmar esta edicion S/N:                                            |                                 | FORMULARIO:                |\n"
				"+------------------------------------------------------------------------+---------------------------------+----------------------------+\n"
		<< endl;
		
		userGotoxy(21,14);
		cout << preview.getUser()<<endl;
		
		userGotoxy(81,14);
		cout << preview.getUser()<<endl;
		
		userGotoxy(81,15);
		cout << "************" <<endl;
		
		cin.ignore();
		
		userGotoxy(81,16);
		cout << preview.getRol() <<endl;
		
		userGotoxy(16,15);
		getline(cin, pwd);
		
		userGotoxy(7,16);
		getline(cin, rol);
		
		userGotoxy(30,19);
		cin >> option;
	
		if(toupper(option) == 'S' || tolower(option) == 's'){
			UserModule::editingVector = users;
			UserModule::indexvector = index;
			UserModule::validateForm(defuser, pwd, rol, true);
		}else{
			updateUsers();	
		}
	}else{
		updateUsers();
	}
	
	
}



void UserModule::displayUsers(int rol){
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<User> users = bfh.readAllUsers();
		
		char opt;
		
		cout << "+------------------------------------------------------------+" << endl;
		cout << "|                   BIBLIOTECA EL PORVENIR                   |" << endl;
		cout << "+------------------------------------------------------------+" << endl;
		cout << "|               LISTADO DE USUARIOS BIBLIOTECA               |" << endl;
		cout << "+-------------------------+---------------+------------------+" << endl;
		cout << "|    Nombre de Usuario    |      Rol      |      Hashcode    |" << endl;
		cout << "+-------------------------+---------------+------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < users.size(); x++){
		User tmpB = users[x];
		
		userGotoxy(0,(firstLine));
		cout << "|" << endl;
		userGotoxy(2,(firstLine));
		cout <<	tmpB.getUser();
		
		
		userGotoxy(26,(firstLine));
		cout << "|" << endl;
		userGotoxy(28,(firstLine));
		switch(tmpB.getRol()){
			case 1:{
				cout <<	"Operador";		
				break;
			}
			
			case 2:{
				cout << "Supervisor";
				break;
			}
			
			case 3:{
				cout << "Administrador";
				break;
			}
			
			default:{
				break;
			}
		}		
		
		userGotoxy(42,(firstLine));
		cout << "|" << endl;
		userGotoxy(44,(firstLine));
		cout <<	tmpB.getId();
		userGotoxy(61,(firstLine));
		cout << "|" << endl;
		cout << "+-------------------------+---------------+------------------+" <<endl;
		
		firstLine += 2;
	}
		
		cout << "| Desea regresar al menu principal? S/N                      |" << endl;	
		cout << "+------------------------------------------------------------+" << endl;
		cout << "| Su opcion:                                                 |" << endl;	
		cout << "+------------------------------------------------------------+" << endl;

	while(toupper(opt) != 'S'){
		userGotoxy(0,firstLine+2);
		cout << "| Su opcion:                                                 |" << endl;	
		userGotoxy(13,firstLine+2);
		cin >> opt;	
	}
	switch(rol){
		case 2:{
			displayModuleSupervisor();
			break;
		}
		case 3:{
			displayModule();	
			break;
		}
	}
	
}

void UserModule::deleteUsers(){
restart:
	system("CLS");
		BinFilesHandler bfh = BinFilesHandler();
	
		vector<User> users = bfh.readAllUsers();
		
		string opt = "";
		
		cout << "+------------------------------------------------------------+" << endl;
		cout << "|                   BIBLIOTECA EL PORVENIR                   |" << endl;
		cout << "+------------------------------------------------------------+" << endl;
		cout << "|               ELIMINACION DE USUARIOS BIBLIOTECA           |" << endl;
		cout << "+-------------------------+---------------+------------------+" << endl;
		cout << "|    Nombre de Usuario    |      Rol      |      Hashcode    |" << endl;
		cout << "+-------------------------+---------------+------------------+" << endl;
		
		int firstLine = 7;
		int modifier = 2;
	for(int x = 0; x < users.size(); x++){
		User tmpB = users[x];
		
		userGotoxy(0,(firstLine));
		cout << "|" << endl;
		userGotoxy(2,(firstLine));
		cout <<	tmpB.getUser();
		
		
		userGotoxy(26,(firstLine));
		cout << "|" << endl;
		userGotoxy(28,(firstLine));
		switch(tmpB.getRol()){
			case 1:{
				cout <<	"Operador";		
				break;
			}
			
			case 2:{
				cout << "Supervisor";
				break;
			}
			
			case 3:{
				cout << "Administrador";
				break;
			}
			
			default:{
				break;
			}
		}		
		
		userGotoxy(42,(firstLine));
		cout << "|" << endl;
		userGotoxy(44,(firstLine));
		cout <<	tmpB.getId();
		userGotoxy(61,(firstLine));
		cout << "|" << endl;
		cout << "+-------------------------+---------------+------------------+" <<endl;
		
		firstLine += 2;
	}
		cout << "| Escriba el nombre del usuario que desea eliminar o escriba |" << endl;	
		cout << "| cualquier palabra para regresar al menu principal.         |" << endl;	
		cout << "+------------------------------------------------------------+" << endl;
		cout << "| Nombre de usuario:                                         |" << endl;	
		cout << "+------------------------------------------------------------+" << endl;
		userGotoxy(21,firstLine+3);
		cin.ignore();	
		
		getline(cin, opt);
		
		std::for_each(opt.begin(), opt.end(), [](char & c){
	    	c = ::tolower(c);
		});
		
		for(int x = 0; x < users.size(); x++){
			
			string userCompare = users[x].getUser();
			
			std::for_each(userCompare.begin(), userCompare.end(), [](char & c){
		    	c = ::tolower(c);
			});
			
			
			if(opt == userCompare){
				vector<User> aux = users;
				aux.erase(aux.begin()+x);
				
				char opt2;
				
				if(bfh.editOnUser(aux)){
					while(toupper(opt2) != 'S'){
						userGotoxy(0,firstLine+3);
						cout << "| Usuario eliminado del programa con exito, aceptar? S:      |";
			
						userGotoxy(56,firstLine+3);
						cin >> opt2;	
					}
					deleteUsers();	
				}else{
					while(toupper(opt2) != 'S'){
						userGotoxy(0,firstLine+3);
						cout << "| Usuario no eliminado del programa con exito, aceptar? S:   |";
			
						userGotoxy(56,firstLine+3);
						cin >> opt2;
					}
					deleteUsers();
				}
			}
		}
		displayModule();
}
