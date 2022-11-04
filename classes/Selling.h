#ifndef SELLING_H
#define SELLING_H

#include <iostream>
#include <string>

#include "book.h"

using namespace std;

class Selling
{
	public:
		
		Selling();
		
		Selling(string, string, string, string, string, int, string, string, string, Book, double);
		
		void setClientName(string);
		string getClientName();
		
		void setClientAddress(string);
		string getClientAddress();
		
		void setTelefono(string);
		string getTelefono();
		
		void setNit(string);
		string getNit();
		
		void setTransaction(string);
		string getTransaction();
		
		void setCantidad(int);
		int getCantidad();
		
		void setFechaDevolucion(string);
		string getFechaDevolucion();
		
		void setFechaPrestamo(string);
		string getFechaPrestamo();
		
		void setCorreo(string);
		string getCorreo();
		
		void setGrandTotal(double);
		double getGrandTotal();
		
		void setRentBook(Book);
		Book GetRentBook();
		
	private:
		string clientName;
		string clientAddress;
		string telefono;
		string nit;
		string transaction;
		int cantidad;
		string fechaDevolucion;
		string fechaPrestamo;
		string correo;
		Book book;
		double grandtotal;
};

#endif
