#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <iostream>

using namespace std;


class LoginForm
{
	public:
		LoginForm();
		int initializeLogin();
		string getUserLoged();
	private:
		bool loginUser(string,string);
		string verifypwdHash(string);
		int userPermission;
		string userLoged;
};

#endif
