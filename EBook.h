#ifndef EBOOK_H
#define EBOOK_H
#include "Book.h"

class EBook: public Book
{
	string FileType;
public:
	EBook(string, string , int, double , string);

	//Getters
	string getFileType();
	virtual double Buy(int, string, string,  MailService*, ShippingService*);
};

#endif

