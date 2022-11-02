#ifndef BINFILESHANDLER_H
#define BINFILESHANDLER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Book.h"

using namespace std;

class BinFilesHandler
{
	public:
		BinFilesHandler();
		User searchUser(User);
		bool writeUserFile(User);
		bool writeOnInventory(Book);
		bool editOnInventory(vector<Book>);
		vector<Book> readALLInventory();
		void cleanFile();
		bool masiveBulk();
		void copytemplate();
	private:
		verifyHash(string);
		vector<Book> readMasiveBulkCsv();
		
};

#endif
