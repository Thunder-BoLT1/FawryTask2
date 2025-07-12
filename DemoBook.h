#ifndef DEMOBOOK_H
#define DEMOBOOK_H
#include "Book.h"

class DemoBook: public Book
{
public:
	DemoBook(string, string, int, double);
	virtual double Buy(int quantity, string email, string, MailService* mailService, ShippingService* shippingService);
};

#endif

