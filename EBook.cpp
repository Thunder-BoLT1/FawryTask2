#include "EBook.h"

EBook::EBook(string isbn, string title, int year, double price, string fileType):Book(isbn, title, year, price) {
	FileType = fileType;
}

//Getters
string EBook::getFileType() { return FileType; }
double EBook::Buy(int quantity, string email, string address, MailService* mailService, ShippingService* shippingService) {
	(void)quantity; //EBooks have no quantity so this parameter will be neglected
	(void)shippingService; //EBooks won't be shipped
	(void)address;
	mailService->sendEMail(email);
	return getPrice();
 }