#include "Book.h"

#include <iostream>
#include <sstream>
#include <string> 
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <vector>

Book::Book(){
}

Book::Book(string title, string _autor, string _category, vector<string> desc, string _editorial, int publicYear, int pages, double _price, int _stock, int hash, bool borrowed, string borrowDate){
	Book::bookTitle = title;
	Book::autor = _autor;
	Book::category = _category;
	Book::description = desc;	
	Book::editorial = _editorial;
	Book::publicationYear = publicYear;
	Book::pagesNumbers = pages;
	Book::price = _price;
	Book::stock = _stock;
	Book::hashcode = hash;
	Book::isBorrowed = borrowed;
	Book::borrowedDate = borrowDate;
}

void Book::setBookTitle(string title){
	Book::bookTitle = title;
}

string Book::getBookTitle(){
	return Book::bookTitle;
}

string Book::getConstBookTitle() const {
	return Book::bookTitle;
}

void Book::setAutor(string name){
	Book::autor = name;
}

string Book::getAutor(){
	return Book::autor;
}

void Book::setCategory(string cat){
	Book::category = cat;
}

string Book::getCategory(){
	return Book::category;
}

void Book::setDescription(vector<string> desc){
	Book::description = desc;
}

vector<string> Book::getDescription(){
	return Book::description;
}

string Book::getLinealDescription(){
	std::string output;

	for (std::string &s: description){
        output = output + s + " ";
    }

	return output;
}

void Book::setEditorial(string editorialName){
	Book::editorial = editorialName;
}

string Book::getEditorial(){
	return Book::editorial;
}

void Book::setPublicationYear(int year){
	Book::publicationYear = year;
}

int Book::getPublicationYear(){
	return Book::publicationYear;
}

void Book::setPagesNumbers(int pages){
	Book::pagesNumbers = pages;
}

int Book::getPagesNumbers(){
	return Book::pagesNumbers;
}


void Book::setPrice(double _price){
	Book::price = _price;
}

double Book::getPrice(){
	return Book::price;
}

double Book::getConstPrice() const{
	return Book::price;
}


void Book::setStock(int _stock){
	Book::stock = _stock;
}

int Book::getStock(){
	return Book::stock;
}

void Book::setHashCode(int hash){
	Book::hashcode = hash;
}

int Book::getHashCode(){
	return Book::hashcode;
}

void Book::setIsBorrowed(bool borrowed){
	Book::isBorrowed = borrowed;
}

bool Book::getIsBorrowed(){
	return Book::isBorrowed;
}

void Book::setBorrowedDate(string date){
	Book::borrowedDate = date;
}

string Book::getBorrowedDate(){
	return Book::borrowedDate;
}
