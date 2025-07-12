#include "PaperBook.h"

PaperBook::PaperBook(string isbn, string title, int year, double price, int stock):Book(isbn, title, year, price) {
	setStock(stock);
}

void PaperBook::setStock(int stock) {
	if (stock >= 0) Stock = stock;
}

int PaperBook::getStock() { return Stock; }

double PaperBook::Buy(int quantity, string email, string address, MailService* mailService, ShippingService* shippingService) {
	(void)mailService; //PaperBooks won't use mailService
	(void)email;
	if (getStock() < quantity) throw -2;
	this->setStock(this->getStock()-quantity); //Reduce Quantity
	shippingService->ShipProduct(address);
	return getPrice() * quantity;
}