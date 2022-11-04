#ifndef BINFILESHANDLER_H
#define BINFILESHANDLER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Book.h"
#include "Selling.h"

using namespace std;

class BinFilesHandler
{
	public:
		BinFilesHandler();
		
		vector<User> readAllUsers();
		User searchUser(User);
		bool writeUserFile(User);
		void cleanUserFile();
		bool editOnUser(vector<User>);
		
		bool writeOnInventory(Book);
		bool editOnInventory(vector<Book>);
		vector<Book> readALLInventory();
		void cleanFile();
		
		bool masiveBulk();
		void copytemplate();
		bool downloadInventory();
		
		bool writeBinacleFile(Selling);
		vector<Selling> listAllSellings();
		
		void generateInventoryReportByAutorAndBookTitle();
		void generateInventoryReportByBookTitleSorted();
		void generateInventoryReportByPrice();
		void generateInventoryReportBySellings();
	private:
		bool compareByAuthor(const Book& a, const Book& b);
		verifyHash(string);
		vector<Book> readMasiveBulkCsv();
		
};

#endif
