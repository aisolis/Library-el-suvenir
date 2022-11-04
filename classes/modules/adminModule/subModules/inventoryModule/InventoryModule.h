#ifndef INVENTORYMODULE_H
#define INVENTORYMODULE_H

#include <iostream>
#include <string>
#include <vector>

#include "../../../../Book.h"
#include "../../../../Selling.h"

using namespace std;

class InventoryModule
{
	public:
		InventoryModule();
		void addEntryToInventory(int);
		void deleteEntryOfInventory();
		void editEntryOfInventory(int);
		void displayAllEntrys(int);
		void displayModule();

		void displayInventoryModuleSupervisor();
		void displayInventoryModuleOperator();

		void borrowABook(int);
	private:
		void validateForm(string, string, string, vector<string>, string, string, string, string, string, bool, int);
		void fixFormData(bool, bool, bool, bool, bool, bool, bool, bool, bool, string, string, string, vector<string>, string, string, string, string, string,bool, int);
		void editEntry(vector<Book>, int, bool, int);
		vector<Book> editingVector;
		int indexvector;
		void throwAlert(vector<Book>, int, int);
		void displayBorrowScreen(vector<Book>, int, int);
		void validateBorrowForm(Book, string, string, string, string, char, int, string, string, string, double, int);
		void fixFormBorrowData(bool, bool, bool, Book, string, string, string, string, char, int, string, string, string, double, int);
};

#endif

