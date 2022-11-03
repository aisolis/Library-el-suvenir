#ifndef OPERATORPANEL_H
#define OPERATORPANEL_H

#include <iostream>
#include <string>

using namespace std;

class OperatorPanel
{
	public:
		OperatorPanel();
		void displayPanel();
		void setlogedUser(string);
		string getlogedUser();
	protected:
		string logedUser;
		int option;
		void setEnvironmentVariables();
};

#endif
