#ifndef USERMODULE_H
#define USERMODULE_H

#include <iostream>
#include <string>
#include <vector>

#include "../../../../User.h"

class UserModule
{
	public:
		UserModule();
		void displayModule();
		void addNewUsers();
		void updateUsers();
		void displayUsers(int);
		void deleteUsers();

		void displayModuleSupervisor();
	private:
		void validateForm(string, string, string, bool);
		void fixFormData(bool, bool, bool, string, string, string, bool);
		vector<User> editingVector; 
		void editEntry(vector<User>, int);
		int indexvector;
};

#endif
