#ifndef REPORTSMODULE_H
#define REPORTSMODULE_H

#include <iostream>
#include <string>

using namespace std;


class ReportsModule
{
	public:
		ReportsModule();
		void displayModule();
	private:
		void throwAlert(int);
};

#endif
