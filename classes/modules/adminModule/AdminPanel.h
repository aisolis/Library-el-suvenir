#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <iostream>
#include <string>

using namespace std;

class AdminPanel
{
	public:
		AdminPanel();
		void displayPanelAdmin();
		void setlogedUser(string);
		string getlogedUser();
	private:
		string logedUser;
		int option;
		void setEnvironmentVariables();
};

#endif
