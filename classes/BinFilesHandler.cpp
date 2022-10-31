#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <fstream>

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
	book.setBorrowedDate("sin prestar");

	try{
		fstream fh("libraryFiles\\inventory.csv");
		if(fh.is_open()){
			vector<Book> offset = readALLInventory();
			fh.seekg((offset.size()+1)*sizeof(Book));
			fh << book.getBookTitle() << "," <<  book.getAutor() << "," <<  book.getLinealDescription() << "," <<  book.getEditorial() << "," <<  book.getPublicationYear() << "," <<  book.getPagesNumbers() << "," <<  book.getStock() << "," <<  book.getHashCode() << "," <<  book.getIsBorrowed() << "," <<  book.getBorrowedDate() << std::endl;
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

vector<Book> BinFilesHandler::readALLInventory(){
	vector<Book> books;
	try{
		fstream fh("libraryFiles\\inventory.csv");
		if(fh.is_open()){
			std::string line;
			
			while(getline(fh,line)){

				std::string bookTitle;
				std::string autor;
				std::string description;
				std::string editorial;
				std::string tpublicationYear;
				std::string tpagesNumbers;
				std::string tstock;
				std::string thashcode;
				std::string tborrowed;
				
				int publicationYear;
				int pagesNumbers;
				int stock;
				int hashcode;
				int borrowedBool;
				bool isBorrowed;
				std::string borrowedDate;

				getline(fh,bookTitle,',');
				getline(fh,autor,',');
				getline(fh,description,',');
				getline(fh,tpublicationYear,',');
				getline(fh,tpagesNumbers,',');
				getline(fh,tstock,',');
				getline(fh,thashcode,',');
				getline(fh,tborrowed,',');
				getline(fh,borrowedDate,',');

				std::istringstream (tpublicationYear) >> publicationYear;
				std::istringstream (tpagesNumbers) >> pagesNumbers;
				std::istringstream (tstock) >> stock;
				std::istringstream (thashcode) >> hashcode;
				std::istringstream (tborrowed) >> borrowedBool;
				
				if(borrowedBool == 0){
					isBorrowed = false;
				}else{
					isBorrowed = true;
				}

				vector<string> temps;

				temps.push_back(description);

				Book book = Book(bookTitle,autor,temps,editorial,publicationYear,pagesNumbers,stock,hashcode,isBorrowed,borrowedDate);
				books.push_back(book);

			}
			fh.close();
			return books;
		}else{
			throw (999);
		}	

	}catch(bool ex){
		return books;
	}
}
