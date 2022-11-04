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
#include <ctime>

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


/*****************************************************/
//            Users
/*****************************************************/

User BinFilesHandler::searchUser(User user){
		
	User ret;
	try{
		
		vector<User> users = readAllUsers();
		
		for(int x = 0; x < users.size(); x++){
			User aux = users[x];
			if(aux.getUser() == user.getUser()){
				ret = aux;
				break;
			}else{
				ret.setUser("");
			}
		}
	}catch(int err){}
	return ret;
}

void BinFilesHandler::cleanFile(){
	try{
	   fstream fh("libraryFiles\\inventory.bin", ios::out);
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

bool BinFilesHandler::writeUserFile(User user){
	
	try{
		ofstream fh("secrets\\keys.bin", ios::app);
		if(fh.is_open()){
			fh << "" << user.getUser() << "," <<  user.getPwd() << "," << user.getRol() << "," <<  verifyHash(user.getUser()) << endl;
			fh.close();
			return true;
		}else{
			throw (999);
		}	

	}catch(bool ex){
		return false;
	}
	
}


bool BinFilesHandler::editOnUser(vector<User> users){
	try{
		ofstream fh("secrets\\keys.bin", ios::app);
		cleanUserFile();
		if(fh.is_open()){
			for(int z = 0; z < users.size();z++){	
				fh << users[z].getUser() << "," <<  users[z].getPwd() << "," << users[z].getRol() << "," <<  users[z].getId()<< std::endl;
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

void BinFilesHandler::cleanUserFile(){
	try{
	   fstream fh("secrets\\keys.bin", ios::out);
	   vector<User> offset = readAllUsers();
	   if(fh.is_open()){
	   		for(int y = 0; y < offset.size()+1; y++){
	   			fh.seekg((y)*sizeof(User));
	   			fh <<"";
	   		}
	   }	fh.close();
	}catch(bool ex){
	}
}

vector<User> BinFilesHandler::readAllUsers(){
	vector<User> users;
	try{
		ifstream infile;
		string line = "";
		int c = 0;
		int w = 0;

		infile.open("secrets\\keys.bin", ios::in);
		
		while(getline(infile,line)){
			w++;
			c=0;
			
			stringstream strstr(line);	
			string word="";
			
			User user = User();
			while(getline(strstr, word, ',')){
				c++;
				switch(c){
					case 1:{
						user.setUser(word);
						break;
					}
					case 2:{
						user.setPassword(word);
						break;
					}
					case 3:{
						int rolParsed;
						std::istringstream (word) >> rolParsed;
						user.setRol(rolParsed);
						break;
					}
					case 4:{
						int idParsed;
						std::istringstream (word) >> idParsed;
						user.setId(idParsed);
						break;
					}
					default:{
						break;
					}
				}
			}
			users.push_back(user);
		}
		
		return users;
	}catch(bool ex){
		return users;
	}
}

/*****************************************************/
//            Inventory
/*****************************************************/

bool BinFilesHandler::writeOnInventory(Book book){
	book.setHashCode(verifyHash(book.getBookTitle()));
	book.setIsBorrowed(false);
	book.setBorrowedDate("sin prestar");

	try{
		ofstream fh("libraryFiles\\inventory.bin", ios::app);
		if(fh.is_open()){
			fh << "" << book.getBookTitle() << "," <<  book.getAutor() << "," << book.getCategory() << "," <<  book.getLinealDescription() << "," <<  book.getEditorial() << "," <<  book.getPublicationYear() << "," <<  book.getPagesNumbers() << "," << book.getPrice() << "," <<  book.getStock() << "," <<  book.getHashCode() << "," <<  book.getIsBorrowed() << "," <<  book.getBorrowedDate() << endl;
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

bool BinFilesHandler::editOnInventory(vector<Book> books){
	try{
		ofstream fh("libraryFiles\\inventory.bin", ios::app);
		cleanFile();
		if(fh.is_open()){
			for(int z = 0; z < books.size();z++){	
				fh << books[z].getBookTitle() << "," <<  books[z].getAutor() << "," << books[z].getCategory() << "," <<  books[z].getLinealDescription() << "," <<  books[z].getEditorial() << "," <<  books[z].getPublicationYear() << "," <<  books[z].getPagesNumbers() << "," << books[z].getPrice() << "," << books[z].getStock() << "," <<  books[z].getHashCode() << "," <<  books[z].getIsBorrowed() << "," <<  books[z].getBorrowedDate() << std::endl;
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

		infile.open("libraryFiles\\inventory.bin", ios::in);
		
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
						book.setCategory(word);
						break;
					}
					case 4:{
						vector<string> desc;
						desc.push_back(word);
						book.setDescription(desc);
						break;
					}
					case 5:{
						book.setEditorial(word);
						break;
					}
					case 6:{
						int publicationYear;
						std::istringstream (word) >> publicationYear;
						book.setPublicationYear(publicationYear);
						break;
					}
					case 7:{
						int pages;
						std::istringstream (word) >> pages;
						book.setPagesNumbers(pages);
						break;
					}
					case 8:{
						double price;
						price = std::stod(word);
						book.setPrice(price);
						break;
					}
					case 9:{
						int stock;
						std::istringstream (word) >> stock;
						book.setStock(stock);
						break;
					}
					case 10:{
						int hashcode;
						std::istringstream (word) >> hashcode;
						book.setHashCode(hashcode);
						break;
					}
					case 11:{
						bool borrowed;
						if(word == "0"){
							borrowed = false;
						}else{
							borrowed = true;
						}
						book.setIsBorrowed(borrowed);
						break;
					}
					case 12:{
						book.setBorrowedDate(word);
						break;
					}
					default:{
						break;
					}
				}
			}
			if(book.getStock() > 0){
				books.push_back(book);	
			}else{
				continue;
			}
			
		}
		
		return books;
	}catch(bool ex){
		return books;
	}
}


/*****************************************************/
//            Masive
/*****************************************************/

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
			if(w-1 < aux.size()){
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
						book.setCategory(word);
						break;
					}
					case 4:{
						vector<string> desc;
						desc.push_back(word);
						book.setDescription(desc);
						break;
					}
					case 5:{
						book.setEditorial(word);
						break;
					}
					case 6:{
						int publicationYear;
						std::istringstream (word) >> publicationYear;
						book.setPublicationYear(publicationYear);
						break;
					}
					case 7:{
						int pages;
						std::istringstream (word) >> pages;
						book.setPagesNumbers(pages);
						break;
					}
					case 8:{
						double price;
						price = std::stod(word);
						book.setPrice(price);
						break;
					}
					case 9:{
						int stock;
						std::istringstream (word) >> stock;
						book.setStock(stock);
						break;
					}
					case 10:{
						int hashcode;
						std::istringstream (word) >> hashcode;
						book.setHashCode(hashcode);
						break;
					}
					case 11:{
						bool borrowed;
						if(word == "0"){
							borrowed = false;
						}else{
							borrowed = true;
						}
						book.setIsBorrowed(borrowed);
						break;
					}
					case 12:{
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
			Book tmp2;
			if(x < aux.size()){
				tmp2 = aux[x];	
				if(tmp.getBookTitle() == tmp2.getBookTitle()){
				continue;
				}else{
					books.push_back(aux[x]);	
				}
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
				
		if(infile.good()){
			//system("DEL /F /A libraryFiles\\masiveBulk\\template.csv");
		}
		system("cd..");
		system("copy template\\template.csv libraryFiles\\masiveBulk\\");	
		system("start libraryFiles\\masiveBulk");	
		
		
	}catch(int x){
	}
}


bool BinFilesHandler::downloadInventory(){
	try{
		string archivo = "libraryFiles\\masiveBulk\\template.csv";
		ifstream infile(archivo.c_str());
		
		if(infile.good()){
			system("DEL /F /A Downloads\\backups\\inventory.bin");
		}
		
		system("cd..");
		system("copy libraryFiles\\inventory.bin Downloads\\backups\\");
		system("start Downloads\\backups");	
		
	}catch(int x){
		
	}
	
	return true;
}

/*****************************************************/
//            Sellings
/*****************************************************/



bool BinFilesHandler::writeBinacleFile(Selling sell){

	try{
		ofstream fh("libraryFiles\\binacle.bin", ios::app);
		if(fh.is_open()){
			Book aux = sell.GetRentBook();
			fh << "" << sell.getClientName() << "," << sell.getClientAddress() << "," << sell.getTelefono() << "," << sell.getNit() << "," << sell.getTransaction() << "," << aux.getBookTitle() << "," << sell.getGrandTotal() << "," << sell.getCantidad() << "," << sell.getFechaDevolucion() << "," << sell.getFechaPrestamo() << "," << sell.getCorreo() << endl;
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


vector<Selling> BinFilesHandler::listAllSellings(){
	vector<Selling> sellings;
	try{
		ifstream infile;
		string line = "";
		int c = 0;
		int w = 0;

		infile.open("libraryFiles\\binacle.bin", ios::in);
		
		while(getline(infile,line)){
			w++;
			c=0;
			
			stringstream strstr(line);	
			string word="";
			
			Selling selling = Selling();
			
			while(getline(strstr, word, ',')){
				c++;
				switch(c){
					case 1:{
						selling.setClientName(word);
						break;
					}
					case 2:{
						selling.setClientAddress(word);
						break;
					}
					case 3:{
						selling.setTelefono(word);
						break;
					}
					case 4:{
						selling.setNit(word);
						break;
					}
					case 5:{
						selling.setRTransaction(word);
						break;
					}
					case 6:{
						Book auxB = Book();
						auxB.setBookTitle(word);
						selling.setRentBook(auxB);
						break;
					}
					case 7:{	
						double price;
						price = std::stod(word);
						selling.setGrandTotal(price);
						break;
					}
					case 8:{
						int cantidadParsed;
						std::istringstream (word) >> cantidadParsed;
						selling.setCantidad(cantidadParsed);
						break;
					}
					case 9:{
						selling.setFechaDevolucion(word);
						break;
					}
					case 10:{
						selling.setFechaPrestamo(word);
						break;
					}
					case 11:{
						selling.setCorreo(word);
						break;
					}
					default:{
						break;
					}
				}
			}
			sellings.push_back(selling);
		}
		
		return sellings;
	}catch(bool ex){
		return sellings;
	}
}

/*****************************************************/
//            Reports
/*****************************************************/


void BinFilesHandler::generateInventoryReportByAutorAndBookTitle(){
	try{
		time_t now = time(0);
		tm * time = localtime(&now);
		int year = 1900 + time->tm_year;
		
		string fileName = "generated-" + std::to_string(time->tm_mday) + "-" + std::to_string(time->tm_mon) + "-" + std::to_string(year);
		
		string command = "MKDIR Reports\\" + fileName;
		system(command.c_str());
		
		string command2 = "copy template\\generateInventoryReportByAutorAndBookTitle.html Reports\\" + fileName;
		system(command2.c_str());
		
		ofstream fh("Reports\\"+fileName+"\\generateInventoryReportByAutorAndBookTitle.html", ios::app);
		
		vector<Book> books =  readALLInventory();
		
		if(fh.is_open()){
			for(int z = 0; z < books.size();z++){	
				fh << "<tr><td>" << books[z].getBookTitle() << "</td><td>" <<  books[z].getAutor() << "</td></tr>" << std::endl;
			}	
			fh << "<tr><th>" << "TOTAL DE LIBROS EN EL SISTEMA: " << "</td><th>" <<  books.size() << "</th></tr>" << std::endl;		
			fh << "</table></body></html>" << endl;
			fh.close();
			
			string commandOpenfile = "start Reports\\" + fileName;
			system(commandOpenfile.c_str());		
		}else{
			throw (999);
		}	
			

	}catch(bool ex){
	}
}


void BinFilesHandler::generateInventoryReportByBookTitleSorted(){
	try{
		time_t now = time(0);
		tm * time = localtime(&now);
		int year = 1900 + time->tm_year;
		
		string fileName = "generated-" + std::to_string(time->tm_mday) + "-" + std::to_string(time->tm_mon) + "-" + std::to_string(year);
		
		string command = "MKDIR Reports\\" + fileName;
		system(command.c_str());
		
		string command2 = "copy template\\generateInventoryReportByBookTitleSorted.html Reports\\" + fileName;
		system(command2.c_str());
		
		ofstream fh("Reports\\"+fileName+"\\generateInventoryReportByBookTitleSorted.html", ios::app);
		
		vector<Book> books =  readALLInventory();
		sort(books.begin(), books.end(), [](const Book& bookA, const Book& bookB){
			return bookA.getConstBookTitle() < bookB.getConstBookTitle();
		});
		
		if(fh.is_open()){
			for(int z = 0; z < books.size();z++){	
				fh << "<tr><td>" << books[z].getBookTitle() << "</td><td>" <<  books[z].getAutor() << "</td></tr>" << std::endl;
			}	
			fh << "<tr><th>" << "TOTAL DE LIBROS EN EL SISTEMA: " << "</td><th>" <<  books.size() << "</th></tr>" << std::endl;		
			fh << "</table></body></html>" << endl;
			fh.close();
			
			string commandOpenfile = "start Reports\\" + fileName;
			system(commandOpenfile.c_str());		
		}else{
			throw (999);
		}	
			

	}catch(bool ex){
	}
}


void BinFilesHandler::generateInventoryReportByPrice(){
	try{
		time_t now = time(0);
		tm * time = localtime(&now);
		int year = 1900 + time->tm_year;
		
		string fileName = "generated-" + std::to_string(time->tm_mday) + "-" + std::to_string(time->tm_mon) + "-" + std::to_string(year);
		
		string command = "MKDIR Reports\\" + fileName;
		system(command.c_str());
		
		string command2 = "copy template\\generateInventoryReportByPrice.html Reports\\" + fileName;
		system(command2.c_str());
		
		ofstream fh("Reports\\"+fileName+"\\generateInventoryReportByPrice.html", ios::app);
		
		vector<Book> books =  readALLInventory();
		
		sort(books.begin(), books.end(), [](Book bookA, Book bookB){		
			return bookA.getPrice() < bookB.getPrice();		
		});
		
		if(fh.is_open()){
			for(int z = 0; z < books.size();z++){	
				fh << "<tr><td>" << books[z].getBookTitle() << "</td><td>" <<  books[z].getAutor() << "</td><td>" << books[z].getCategory() << "</td><td>" <<  books[z].getLinealDescription() << "</td><td>" <<  books[z].getEditorial() << "</td><td>" <<  books[z].getPublicationYear() << "</td><td>" <<  books[z].getPagesNumbers() << "</td><td>" << books[z].getPrice() << "</td><td>" << books[z].getStock() << "</td></tr>" << std::endl;
			}	
			fh << "<tr><th>" << "TOTAL DE LIBROS EN EL SISTEMA: " << "</td><th>" <<  books.size() << "</th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th></tr>" << std::endl;		
			fh << "</table></body></html>" << endl;
			fh.close();
			
			string commandOpenfile = "start Reports\\" + fileName;
			system(commandOpenfile.c_str());	
		}else{
			throw (999);
		}	
			

	}catch(bool ex){
	}
}


void BinFilesHandler::generateInventoryReportBySellings(){
	try{
		time_t now = time(0);
		tm * time = localtime(&now);
		int year = 1900 + time->tm_year;
		
		string fileName = "generated-" + std::to_string(time->tm_mday) + "-" + std::to_string(time->tm_mon) + "-" + std::to_string(year);
		
		string command = "MKDIR Reports\\" + fileName;
		system(command.c_str());
		
		string command2 = "copy template\\generateInventoryReportBySellings.html Reports\\" + fileName;
		system(command2.c_str());
		
		ofstream fh("Reports\\"+fileName+"\\generateInventoryReportBySellings.html", ios::app);
		
		vector<Selling> sellings =  listAllSellings();
		
		if(fh.is_open()){
			for(int z = 0; z < sellings.size();z++){	
				Book aux = sellings[z].GetRentBook();
				fh << "<tr><td>" << sellings[z].getClientName() << "</td><td>" << sellings[z].getClientAddress() << "</td><td>" << sellings[z].getTelefono() << "</td><td>" << sellings[z].getNit() << "</td><td>" << sellings[z].getTransaction() << "</td><td>" << aux.getBookTitle() << "</td><td>" << sellings[z].getGrandTotal() << "</td><td>" << sellings[z].getCantidad() << "</td><td>" << sellings[z].getFechaPrestamo() << "</td><td>" << sellings[z].getFechaDevolucion() << "</td><td>" << sellings[z].getCorreo() << "</td></tr>" << std::endl;
			}	
			fh << "<tr><th>" << "TOTAL DE VENTAS/ALQUILERES EN EL SISTEMA: " << "</td><th>" <<  sellings.size() << "</th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th> <th> </th> </tr>" << std::endl;		
			fh << "</table></body></html>" << endl;
			fh.close();
			
			string commandOpenfile = "start Reports\\" + fileName;
			system(commandOpenfile.c_str());	
		}else{
			throw (999);
		}	
			

	}catch(bool ex){
	}
}
























