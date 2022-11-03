#include <iostream>

#include "classes/loginForm.h"
#include "classes/modules/adminModule/adminPanel.h"
#include "classes/modules/SuperModule/SupervisorPanel.h"
#include "classes/modules/OperatorModule/OperatorPanel.h"
#include <windows.h>

COORD mainCoord = {0,0};

void mainGotoxy(int x, int y){
	mainCoord.X = x;
	mainCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),mainCoord);
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

HWND WINAPI GetConsoleWindowNT(void)
{
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    GetConsoleWindowT GetConsoleWindow;
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
    ,TEXT("GetConsoleWindow"));

    if(GetConsoleWindow == NULL){
        return NULL;
    }
    return GetConsoleWindow();
}

int main(int argc, char** argv) {
	HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,0,0,1500,1000,TRUE);
	
	system("color 02");
		
	LoginForm lf = LoginForm();
	
	switch(lf.initializeLogin()){
		case 1:{
			system("CLS");
			OperatorPanel op = OperatorPanel();
			op.setlogedUser(lf.getUserLoged());
 			op.displayPanel();
			break;
		}
		
		case 2:{
			system("CLS");
			SupervisorPanel sp = SupervisorPanel();
			sp.setlogedUser(lf.getUserLoged());
 			sp.displayPanel();
			break;
		}
		
		case 3:{
			system("CLS");
			AdminPanel ap = AdminPanel();
			ap.setlogedUser(lf.getUserLoged());
 			ap.displayPanelAdmin();
			break;
		}
		
		default:
			exit(0);
		break;	
	}
	
}
