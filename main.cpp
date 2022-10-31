#include <iostream>

#include "classes/loginForm.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
	
	system("color 02");
		
	LoginForm lf = LoginForm();
	
	switch(lf.initializeLogin()){
		case 0:
			system("CLS");
		break;
		
		case 1:
			system("CLS");
		break;
		
		case 2:
			system("CLS");
		break;
		
		default:
			system("CLS");
		break;	
	}
	
}
