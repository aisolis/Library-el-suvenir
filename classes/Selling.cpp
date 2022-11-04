#include "Selling.h"

Selling::Selling(){
	
}

Selling::Selling(string _clientName, string _clientAddress, string _telefono, string _nit, string _transaction, int _cantidad, string _fechaDevolucion, string _fechaPrestamo, string _correo, Book _book, double _grandTotal){
	Selling::clientName = _clientName;
	Selling::clientAddress = _clientAddress;
	Selling::telefono = _telefono;
	Selling::nit = _nit;
	Selling::transaction = _transaction;
	Selling::cantidad = _cantidad;
	Selling::fechaDevolucion = _fechaDevolucion;
	Selling::fechaPrestamo = _fechaPrestamo;
	Selling::correo = _correo;
	Selling::book = _book;
	Selling::grandtotal = _grandTotal;	
}


void Selling::setClientName(string cName){
	Selling::clientName = cName;	
}

string Selling::getClientName(){
	return Selling::clientName;
}



void Selling::setClientAddress(string cAddress){
	Selling::clientAddress = cAddress;
}

string Selling::getClientAddress(){
	return Selling::clientAddress;	
}



void Selling::setTelefono(string ct){
	Selling::telefono = ct;	
}

string Selling::getTelefono(){
	return Selling::telefono;
}



void Selling::setNit(string cn){
	Selling::nit = cn;
}

string Selling::getNit(){
	return Selling::nit;
}



void Selling::setTransaction(string t){
	if(t == "v"){
		Selling::transaction = "Venta";
	}else{
		Selling::transaction = "Alquiler";
	}
}

string Selling::getTransaction(){
	return Selling::transaction;
}




void Selling::setCantidad(int c){
	Selling::cantidad = c;
}

int Selling::getCantidad(){
	return Selling::cantidad;
}




void Selling::setFechaDevolucion(string fd){
	Selling::fechaDevolucion = fd;
}

string Selling::getFechaDevolucion(){
	return Selling::fechaDevolucion;
}



void Selling::setFechaPrestamo(string fp){
	Selling::fechaPrestamo = fp;
}

string Selling::getFechaPrestamo(){
	return Selling::fechaPrestamo;
}



void Selling::setCorreo(string cc){
	Selling::correo = cc;	
}

string Selling::getCorreo(){
	return Selling::correo;
}




void Selling::setGrandTotal(double gt){
	Selling::grandtotal = gt;
}

double Selling::getGrandTotal(){
	return Selling::grandtotal;
}




void Selling::setRentBook(Book bookn){
	Selling::book = bookn;
}


Book Selling::GetRentBook(){
	return Selling::book;
}
