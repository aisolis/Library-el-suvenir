#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string.h>

#include "BinFilesHandler.h"
#include "User.h"


BinFilesHandler::BinFilesHandler(){
}


User BinFilesHandler::searchUser(User user){
		
	User aux;
	try{
		fstream fh("secrets\\keys.bin", ios::out | ios::in | ios::binary);
	
		if(fh.is_open()){
			fh.seekg((verifyHash(user.getUser()))*sizeof(User));
			fh.read((char*)&aux,sizeof(User));
			fh.close();		
		}else{
			throw (999);
		}
		
		aux.setPassword(std::to_string(verifyHash(aux.getPwd())));
		
	}catch(int err){
		aux.setUser("");
		aux.setPassword("");
	}
	
	return aux;
}

bool BinFilesHandler::writeUserFile(User user){
	
	try{
		fstream fh("secrets\\keys.bin", ios::out | ios::in | ios::binary);
		
		if(fh.is_open()){
			fh.seekg((verifyHash(user.getUser()))*sizeof(User));
			fh.write((char*)&user, sizeof(User));
			fh.close();
			
			return true;
		}else{
			throw (999);
		}	
		
		
	}catch(int err){
		return false;
	}
}

int BinFilesHandler::verifyHash (string str) {
    int h = 0;
    for (size_t i = 0; i < str.size(); ++i)
        h = h * 31 + static_cast<int>(str[i]);
        
    if(h > 0){
    	h = h/100000;
	}else{
		h = h*-1;
		h = h/100000;
	}
    return h;
}


bool BinFilesHandler::writeOnInventory(Book book){
	book.setHashCode(verifyHash(book.getBookTitle()));
	book.setIsBorrowed(false);
	book.setBorrowedDate("");

	try{
		fstream fh("libraryFiles\\inventory.csv", ios::out | ios::in | ios::app);
		if(fh.is_open()){
			fh << book.getBookTitle() << "," <<  book.getAutor() << "," <<  book.getLinealDescription() << "," <<  book.getEditorial() << "," <<  book.getPublicationYear() << "," <<  book.getPagesNumbers() << "," <<  book.getStock() << "," <<  book.getHashCode() << "," <<  book.getIsBorrowed() << "," <<  book.getBorrowedDate() << endl;
			fh.close();
			return true;
		}else{
			throw (999);
		}	

	}catch(bool ex){
		return false;
	}

	return true;
}
