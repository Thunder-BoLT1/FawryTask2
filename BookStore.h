#ifndef INVENTORY_H
#define	INVENTORY_H
#include <unordered_map>
#include <vector>
#include "PaperBook.h"
#include "EBook.h"
#include "DemoBook.h"
#include "MailService.h"
#include "ShippingService.h"
class BookStore
{
	unordered_map<string, Book*> Inventory; // Because each book has a unique ISBN i will use it as a key in a hashmap for better performance Average O(1)operaions :D
	//Assoscitaion relation because of weak relation both the book store and these companies are separate entities but needs thier operations
	MailService* mailService;
	ShippingService* shippingService;
	int currYear;
public:
	BookStore(int, MailService *, ShippingService *);
	//These are all overloaded to account for diffrent types
	//For PaperBooks
	bool addBook(string, string, int, double, int);
	//For EBooks
	bool addBook(string, string, int, double, string);
	//For DemoBooks
	bool addBook(string, string, int, double);
	vector<Book*> removeOutdated(int);

	double BuyBook(string, int, string, string);

	//This function was not asked but I will add it to test the logic by printing the existing books (all books stream operators were overloaded for clean code)
	void printAllBooks() const;
};

#endif

