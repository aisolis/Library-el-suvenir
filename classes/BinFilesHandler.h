#ifndef BINFILESHANDLER_H
#define BINFILESHANDLER_H

#include <iostream>

#include "User.h"

using namespace std;

class BinFilesHandler
{
	public:
		BinFilesHandler();
		User searchUser(User);
		bool writeUserFile(User);
	private:
		verifyHash(string);
};

#endif
