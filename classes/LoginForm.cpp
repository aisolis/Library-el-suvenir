#include "LoginForm.h"
#include "User.h"
#include "BinFilesHandler.h"
#include "modules\\adminModule\\AdminPanel.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>


using namespace std;


LoginForm::LoginForm(){
}

COORD coord = {0,0};

void gotoxy(int x, int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

string getpass(bool show_asterisk=true)
{
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;
  unsigned char ch=0;

  DWORD con_mode;
  DWORD dwRead;

  HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);

  GetConsoleMode( hIn, &con_mode );
  SetConsoleMode( hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  while(ReadConsoleA( hIn, &ch, 1, &dwRead, NULL) && ch !=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                     cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

/*======================*/

int LoginForm::initializeLogin() {

	bool badLoginError = false;
reset:
	/*
		0 = normal user
		1 = supervisor user
		2 = admin user
	*/
	
	string user,password;
	
	system("CLS");	
	cout << "+------------------------------------------------------------------------+" << endl;
	cout << "|                         Biblioteca EL PORVENIR                         |" << endl;
	cout << "+------------------------------------------------------------------------+" << endl;
	cout << "| Para acceder al sistema por favor ingresa tus credenciales             |" << endl;
	cout << "| La clave por seguridad esta oculta                                     |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| Usuario:                                                               |" << endl;
	cout << "| Password:                                                              |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "+----------------------------------------------------------------------- +" << endl;
	cout << "| Para ingresar presiona enter...                                        |" << endl;
	cout << "+------------------------------------------------------------------------+" << endl;
	
	if(badLoginError){
		cout << "| ERROR: Usuario o contrasena incorrecta, verifique e intente...         |" << endl;
		cout << "+------------------------------------------------------------------------+" << endl;	
	}
	
	
	gotoxy(11,6);
	cin >> user;
	gotoxy(12,7);
	password=getpass(false);
	
	
	gotoxy(0,11);
	
	if(loginUser(user, password)){
		badLoginError = false;
		return LoginForm::userPermission;
	}else{
		badLoginError = true;
		goto reset;
	}
	
}

 bool LoginForm::loginUser(string user, string pwd){
 	
 	
 	User username = User(user, pwd);
 	BinFilesHandler bh = BinFilesHandler();
 	
 	User aux = bh.searchUser(username);
 	
 	
 	if(verifypwdHash(aux.getPwd()) == verifypwdHash(pwd)){
 		LoginForm::userLoged = aux.getUser();
 		switch(aux.getRol()){
 			
 			case 1:{
 				LoginForm::userPermission = 1;
 				break;
 			}
 			
 			case 2:{
 				LoginForm::userPermission = 2;

				break;
			 }
 			
 			case 3:{
 				LoginForm::userPermission = 3;

				break;
			 }
			
		 }
 		return true;
	 }else{
	 	return false;
	 }	 
 } 
 
 
 string LoginForm::verifypwdHash (string str) {
    int h = 0;
    for (size_t i = 0; i < str.size(); ++i)
        h = h * 31 + static_cast<int>(str[i]);
        
    if(h > 0){
    	h = h/100000;
	}else{
		h = h*-1;
		h = h/100000;
	}
	
    return std::to_string(h);
}


string LoginForm::getUserLoged(){
	return userLoged;
}









