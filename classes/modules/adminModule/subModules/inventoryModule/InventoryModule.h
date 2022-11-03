#ifndef INVENTORYMODULE_H
#define INVENTORYMODULE_H

#include <iostream>
#include <string>
#include <vector>

#include "../../../../Book.h"

using namespace std;

class InventoryModule
{
	public:
		InventoryModule();
		void addEntryToInventory();
		void deleteEntryOfInventory();
		void editEntryOfInventory();
		void displayAllEntrys();
		void displayModule();

		void displayInventoryModuleSupervisor();
		void displayInventoryModuleOperator();

		void borrowABook();
	private:
		void validateForm(string, string, string, vector<string>, string, string, string, string, string, bool);
		void fixFormData(bool, bool, bool, bool, bool, bool, bool, bool, bool, string, string, string, vector<string>, string, string, string, string, string,bool);
		void editEntry(vector<Book>, int, bool);
		vector<Book> editingVector;
		int indexvector;
		void throwAlert(vector<Book>, int);
		void displayBorrowScreen(vector<Book>, int);
};

#endif

