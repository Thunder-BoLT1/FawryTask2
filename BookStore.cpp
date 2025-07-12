#include "BookStore.h"

BookStore::BookStore(int currYear, MailService* mailService, ShippingService* shippingService) { 
	this->currYear = currYear; 
	this->mailService = mailService;
	this->shippingService = shippingService;
}

//These are all overloaded to account for diffrent types
//For PaperBooks
bool BookStore::addBook(string isbn, string title, int year, double price, int stock) {
	if (Inventory.find(isbn) != Inventory.end()) return false; //Book already exists
	Book* newBook = new PaperBook(isbn, title, year, price, stock);
	Inventory[isbn] = newBook;
	return true;
}
//For EBooks
bool BookStore::addBook(string isbn, string title, int year, double price, string fileType) {
	if (Inventory.find(isbn) != Inventory.end()) return false; //Book already exists
	Book* newBook = new EBook(isbn, title, year, price, fileType);
	Inventory[isbn] = newBook;
	return true;
}
//For DemoBooks
bool BookStore::addBook(string isbn, string title, int year, double price) {
	if (Inventory.find(isbn) != Inventory.end()) return false; //Book already exists
	Book* newBook = new DemoBook(isbn, title, year, price);
	Inventory[isbn] = newBook;
	return true;
}

vector<Book*> BookStore::removeOutdated(int yearsCount) {
	int n = Inventory.size();
	vector<Book*> outDatedBooks;
	auto it = Inventory.begin();
	while(it != Inventory.end()) {
		if (currYear - it->second->getYear() >= yearsCount) {
			Book* outDatedBook = it->second;
			it = Inventory.erase(it);
			outDatedBooks.push_back(outDatedBook);
		}
		else it++;
	}
	return outDatedBooks;
}

double BookStore::BuyBook(string isbn, int quantity, string email, string address) {
	if (Inventory.find(isbn) == Inventory.end()) throw -1;
	double totalPrice = 0;
	try {
		totalPrice = Inventory[isbn]->Buy(quantity, email, address, mailService, shippingService);
	}
	catch (int ErrorCode) {
		throw; // To be Handled all at once in a higher level
	}
	return totalPrice;
}

void BookStore::printAllBooks() const {
	for (const auto& pair : Inventory) {
		cout << *pair.second << endl;
	}
}