#ifndef BINFILESHANDLER_H
#define BINFILESHANDLER_H

#include <iostream>

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
		vector<Book> readALLInventory();
	private:
		verifyHash(string);
};

#endif
