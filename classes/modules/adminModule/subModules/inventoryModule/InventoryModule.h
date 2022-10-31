#ifndef INVENTORYMODULE_H
#define INVENTORYMODULE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InventoryModule
{
	public:
		InventoryModule();
		void addEntryToInventory();
		void deleteEntryOfInventory();
		void searchEntryOfInventory();
		void displayAllEntrys();
	private:
		void validateForm(string, string, vector<string>, string, string, string, string);
		void fixFormData(bool, bool, bool, bool, bool, bool, bool, string, string, vector<string>, string, string, string, string);
};

#endif
