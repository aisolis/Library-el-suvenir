#include <iostream>

#include "classes/loginForm.h"
#include "classes/modules/adminModule/adminPanel.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
	
	system("color 02");
		
	LoginForm lf = LoginForm();
	
	switch(lf.initializeLogin()){
		case 0:{
			system("CLS");
			AdminPanel ap1 = AdminPanel();
 			//ap1.displayPanelAdmin();
			break;
		}
		
		case 1:{
			system("CLS");
			AdminPanel ap2 = AdminPanel();
			ap2.setlogedUser(lf.getUserLoged());
 			ap2.displayPanelAdmin();
			break;
		}
		
		case 2:{
			system("CLS");
			AdminPanel ap3 = AdminPanel();
 			//ap3.displayPanelAdmin();
			break;
		}
		
		default:
			system("CLS");
		break;	
	}
	
}
