#include "DemoBook.h"

DemoBook::DemoBook(string isbn, string tilte, int year, double price) :Book(isbn, tilte, year, price){

}

double DemoBook::Buy(int quantity, string email, string address, MailService* mailService, ShippingService* shippingService) {
	(void)quantity;
	(void)email;
	(void)address;
	(void)mailService;
	(void)shippingService;
	throw -3;
	return 0;
}