#ifndef PAPERBOOK_H
#define PAPERBOOK_H
#include "Book.h"

class PaperBook: public Book
{
	int Stock;
public:
	PaperBook(string, string, int, double, int);

	//Setters
	void setStock(int);
	//Getters
	int getStock();

	virtual double Buy(int quantity, string email, string, MailService* mailService, ShippingService* shippingService);
};

#endif

