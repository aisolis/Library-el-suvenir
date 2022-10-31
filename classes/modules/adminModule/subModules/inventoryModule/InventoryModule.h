#ifndef INVENTORYMODULE_H
#define INVENTORYMODULE_H

#include <iostream>
#include <string>

using namespace std;

class InventoryModule
{
	public:
		InventoryModule();
		void addEntryToInventory();
		void deleteEntryOfInventory();
		void searchEntryOfInventory();
		void displayAllEntrys();
	protected:
};

#endif
