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

#include <algorithm>


const std::string WHITESPACE1 = " \n\r\t\f\v";
 
std::string ltrim1(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE1);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim1(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE1);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim1(const std::string &s) {
    return rtrim1(ltrim1(s));
}

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
			fh << trim1(book.getBookTitle()) << "," <<  book.getAutor() << "," <<  book.getLinealDescription() << "," <<  book.getEditorial() << "," <<  book.getPublicationYear() << "," <<  book.getPagesNumbers() << "," <<  book.getStock() << "," <<  book.getHashCode() << "," <<  book.getIsBorrowed() << "," <<  book.getBorrowedDate() << std::endl;
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

void BinFilesHandler::cleanFile(){
	try{
	   fstream fh("libraryFiles\\inventory.csv");
	   vector<Book> offset = readALLInventory();
	   if(fh.is_open()){
	   		for(int y = 0; y < offset.size()+1; y++){
	   			fh << "" << "," <<  "" << "," <<  "" << "," <<  "" << "," <<  "" << "," <<  "" << "," <<  "" << "," <<  "" << "," <<  "" << "," <<  "" << std::endl;
	   		}
	   }	fh.close();
	}catch(bool ex){
	}
}

bool BinFilesHandler::editOnInventory(vector<Book> books){
	try{
		fstream fh("libraryFiles\\inventory.csv");
		cleanFile();
		if(fh.is_open()){
			for(int z = 0; z < books.size();z++){
				//fh.seekg((offset.size()+1)*sizeof(Book));	
				fh << books[z].getBookTitle() << "," <<  books[z].getAutor() << "," <<  books[z].getLinealDescription() << "," <<  books[z].getEditorial() << "," <<  books[z].getPublicationYear() << "," <<  books[z].getPagesNumbers() << "," <<  books[z].getStock() << "," <<  books[z].getHashCode() << "," <<  books[z].getIsBorrowed() << "," <<  books[z].getBorrowedDate() << std::endl;
			}			
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
		ifstream infile;
		string line = "";
		int c = 0;
		int w = 0;

		infile.open("libraryFiles\\inventory.csv", ios::in);
		
		while(getline(infile,line)){
			w++;
			c=0;
			
			stringstream strstr(line);	
			string word="";
			
			Book book = Book();
			while(getline(strstr, word, ',')){
				c++;
				switch(c){
					case 1:{
						book.setBookTitle(word);
						break;
					}
					case 2:{
						book.setAutor(word);
						break;
					}
					case 3:{
						vector<string> desc;
						desc.push_back(word);
						book.setDescription(desc);
						break;
					}
					case 4:{
						book.setEditorial(word);
						break;
					}
					case 5:{
						int publicationYear;
						std::istringstream (word) >> publicationYear;
						book.setPublicationYear(publicationYear);
						break;
					}
					case 6:{
						int pages;
						std::istringstream (word) >> pages;
						book.setPagesNumbers(pages);
						break;
					}
					case 7:{
						int stock;
						std::istringstream (word) >> stock;
						book.setStock(stock);
						break;
					}
					case 8:{
						int hashcode;
						std::istringstream (word) >> hashcode;
						book.setHashCode(hashcode);
						break;
					}
					case 9:{
						bool borrowed;
						if(word == "0"){
							borrowed = false;
						}else{
							borrowed = true;
						}
						book.setIsBorrowed(borrowed);
						break;
					}
					case 10:{
						book.setBorrowedDate(word);
						break;
					}
					default:{
						break;
					}
				}
			}
			books.push_back(book);
		}
		
		return books;
	}catch(bool ex){
		return books;
	}
}
