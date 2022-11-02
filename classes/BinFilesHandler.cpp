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
#include <algorithm>
#include <dirent.h>
#include <sys/stat.h>

#include "BinFilesHandler.h"
#include "User.h"
#include "io.h"


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
		ofstream fh("libraryFiles\\inventory.csv", ios::app);
		if(fh.is_open()){
			fh << "" << book.getBookTitle() << "," <<  book.getAutor() << "," <<  book.getLinealDescription() << "," <<  book.getEditorial() << "," <<  book.getPublicationYear() << "," <<  book.getPagesNumbers() << "," <<  book.getStock() << "," <<  book.getHashCode() << "," <<  book.getIsBorrowed() << "," <<  book.getBorrowedDate() << endl;
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
	   fstream fh("libraryFiles\\inventory.csv", ios::out);
	   vector<Book> offset = readALLInventory();
	   if(fh.is_open()){
	   		for(int y = 0; y < offset.size()+1; y++){
	   			fh.seekg((y)*sizeof(User));
	   			fh <<"";
	   		}
	   }	fh.close();
	}catch(bool ex){
	}
}

bool BinFilesHandler::editOnInventory(vector<Book> books){
	try{
		ofstream fh("libraryFiles\\inventory.csv", ios::app);
		cleanFile();
		if(fh.is_open()){
			for(int z = 0; z < books.size();z++){	
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


vector<Book> BinFilesHandler::readMasiveBulkCsv(){
	vector<Book> books;
	try{
		ifstream infile;
		string line = "";
		int c = 0;
		int w = 0;
		int z = 0;
		vector<Book> aux = readALLInventory();
		infile.open("libraryFiles\\masiveBulk\\template.csv", ios::in);
		
		while(getline(infile,line)){
			w++;
			
			if(w == 1){
				continue;
			}
			c=0;
			
			stringstream strstr(line);	
			string word="";
			
			Book book = Book();
			Book bookAux;
			if(w-1<aux.size()){
				bookAux = aux[z];
			}
			z++;
			
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
			
			if(bookAux.getBookTitle() == book.getBookTitle()){
				bookAux.setStock(bookAux.getStock()+book.getStock());
				books.push_back(bookAux);
			}else{
				books.push_back(book);	
			}
			
		}
		
		for(int x = 0; x < books.size(); x++){			
			Book tmp = books[x];
			Book tmp2 = aux[x];
			if(tmp.getBookTitle() == tmp2.getBookTitle()){
				continue;
			}else{
				books.push_back(aux[x]);	
			}
		}
		
		return books;
	}catch(bool ex){
		return books;
	}
}

bool BinFilesHandler::masiveBulk(){
	vector<Book> newAux = readMasiveBulkCsv();
	if(newAux.size() == 0){
		return false;
	}
	if(editOnInventory(newAux)){
		return true;
	}else{
		return false;
	}
}

std::string get_working_path()
{
   char temp[100];
   return ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") );
}

void BinFilesHandler::copytemplate(){
	try{
		string archivo = "libraryFiles\\masiveBulk\\template.csv";
		ifstream infile(archivo.c_str());
				
		if(!infile.good()){
			system("cd ..");
			system("copy template\\template.csv libraryFiles\\masiveBulk\\");	
			system("start libraryFiles\\masiveBulk");	
		}else{
			system("cd..");
			system("start libraryFiles\\masiveBulk");		
		}
		
	}catch(int x){
	}
}


bool BinFilesHandler::downloadInventory(){
	system("cd..");
	system("copy libraryFiles\\inventory.csv Downloads\\backups\\");
	system("start Downloads\\backups");	
	
	return true;
}
