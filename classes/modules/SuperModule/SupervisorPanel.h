#ifndef SUPERVISORPANEL_H
#define SUPERVISORPANEL_H

#include <iostream>
#include <string>

using namespace std;

class SupervisorPanel
{
	public:
		SupervisorPanel();
		void displayPanel();
		void setlogedUser(string);
		string getlogedUser();
	protected:
		string logedUser;
		int option;
		void setEnvironmentVariables();
};

#endif
