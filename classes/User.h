#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
	private:
		char user[50];
		char password[50];
		int rol;
		long id;
		
	public:
		User();
		User(string,string);
		User(string);
		User(string,string,int,long);
		
		void setPassword(string);
		string getPwd();
		
		string getUser();
		void setUser(string);
		
		int getRol();
		void setRol(int);
		
		long getId();
		void setId(long);
};

#endif
