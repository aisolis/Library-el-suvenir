#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{
	public:
		Book();
		Book(string,string,vector<string>,string,int,int,int,int,bool,string);
		
		void setBookTitle(string);
		string getBookTitle();
		
		void setAutor(string);
		string getAutor();
		
		void setDescription(vector<string>);
		vector<string> getDescription();
		string getLinealDescription();
		
		void setEditorial(string);
		string getEditorial();
		
		void setPublicationYear(int);
		int getPublicationYear();
		
		void setPagesNumbers(int);
		int getPagesNumbers();
		
		void setStock(int);
		int getStock();
		
		void setHashCode(int);
		int getHashCode();
		
		void setIsBorrowed(bool);
		bool getIsBorrowed();
		
		void setBorrowedDate(string);
		string getBorrowedDate();
		
	private:
		string bookTitle;
		string autor;
		vector<string> description;
		string editorial;
		int publicationYear;
		int pagesNumbers;
		int stock;
		int hashcode;
		bool isBorrowed;
		string borrowedDate;
};

#endif
