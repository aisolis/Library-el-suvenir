#include "User.h"
#include <iostream>
#include <string.h>

using namespace std;

User::User() {
	
}

User::User(string _user, string _password) {
	strcpy(user, _user.c_str());
	strcpy(password, _password.c_str());
}

User::User(string _user) {
	strcpy(user, _user.c_str());
}


User::User(string _user, string _password, int _rol, long _id) {
	strcpy(user, _user.c_str());
	strcpy(password, _password.c_str());
	rol = _rol;
	id = _id;
}
	
string User::getUser(){
	 return user;
}	

void User::setPassword(string pwd){
	strcpy(password, pwd.c_str());
}

string User::getPwd(){
	 return password;
}	

void User::setUser(string username){
	strcpy(user, username.c_str());
}

int User::getRol(){
	 return rol;
}	

void User::setRol(int role){
	rol = role;
}

long User::getId(){
	 return id;
}	

void User::setId(long idp){
	id = idp;
}

