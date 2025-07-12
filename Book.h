#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include "MailService.h"
#include "ShippingService.h"

using namespace std;
class Book
{	
	static int Count; //This will be used to create Unique ISBN
	string ISBN, Title;
	int Year;
	double Price;
public:
	Book(string, string, int, double);
	//Setters
	void setPrice(double);
	//We don't Need setters for other values as they won'y change for any book after it's creation
	//Getters
	string getISBN() const;
	string getTitle() const;
	int getYear() const;
	double getPrice() const;
	//Virtual functions
	virtual double Buy(int , string, string, MailService*, ShippingService*) = 0; //Pure virtual function must be overidden in children classed
};

ostream& operator <<(ostream&, Book&);
#endif

