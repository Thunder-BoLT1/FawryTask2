#include "Tester.h"

Tester::Tester() {

	MailService* myMailService = new MailService;
	ShippingService* myShippingService = new ShippingService;

	BookStore* myBookStore = new BookStore(2025, myMailService, myShippingService);

	//because of verloaded functions it's smart to detect the type
	cout << "============== Adding Books ==============" << endl;
	myBookStore->addBook("A1", "C++ Fundementals", 2015, 20.3, 5); //PaperBook
	myBookStore->addBook("A2", "Modern C++ Fundementals", 2024, 43.99, 1); //PaperBook
	myBookStore->addBook("B1", "JAVA Fundementals", 2018, 35.2, "PDF"); //EBook
	myBookStore->addBook("C1", "SQL Fundementals", 2023, 20.3); //DemoBook;

	myBookStore->printAllBooks();
	cout << "============== Removed OutDated Books ==============" << endl;
	vector<Book*> outDatedBooks = myBookStore->removeOutdated(8);
	for (int i = 0; i < outDatedBooks.size(); i++) {
		cout << *outDatedBooks[i] << endl;
		delete outDatedBooks[i]; //to prevent memoryleaks
	}
	cout << "============== Remaning Books ==============" << endl;
	myBookStore->printAllBooks();


	double totalPrice = 0;

	cout << "============== Buying non-existing book ==============" << endl;
	try {
		totalPrice = myBookStore->BuyBook("A1", 2, "mazen.00ahmd@gmail.com", "EL Shiek Zayed");
		cout << "Your Total Price is = " << totalPrice << endl;
	}
	catch (int ErrorCode) {
		if (ErrorCode == -1) cout << "This Book doesn't Exist" << endl;
		else if (ErrorCode == -2) cout << "No Enough Stock Available " << endl;
		else if (ErrorCode == -3) cout << "DemoBooks are not for Sale" << endl;
	}

	cout << "============== Buying More Quantity than the existing for a  book ==============" << endl;
	try {
		totalPrice = myBookStore->BuyBook("A2", 2, "mazen.00ahmd@gmail.com", "EL Shiek Zayed");
		cout << "Your Total Price is = " << totalPrice << endl;
	}
	catch (int ErrorCode) {
		if (ErrorCode == -1) cout << "This Book doesn't Exist" << endl;
		else if (ErrorCode == -2) cout << "No Enough Stock Available " << endl;
		else if (ErrorCode == -3) cout << "DemoBooks are not for Sale" << endl;
	}

	cout << "============== Buying a DemoBook ==============" << endl;
	try {
		totalPrice = myBookStore->BuyBook("C1", 2, "mazen.00ahmd@gmail.com", "EL Shiek Zayed");
		cout << "Your Total Price is = " << totalPrice << endl;
	}
	catch (int ErrorCode) {
		if (ErrorCode == -1) cout << "This Book doesn't Exist" << endl;
		else if (ErrorCode == -2) cout << "No Enough Stock Available " << endl;
		else if (ErrorCode == -3) cout << "DemoBooks are not for Sale" << endl;
	}

	cout << "============== Buying a book ==============" << endl;
	try {
		totalPrice = myBookStore->BuyBook("B1", 2, "mazen.00ahmd@gmail.com", "EL Shiek Zayed");
		cout << "Your Total Price is = " << totalPrice << endl;
	}
	catch (int ErrorCode) {
		if (ErrorCode == -1) cout << "This Book doesn't Exist" << endl;
		else if (ErrorCode == -2) cout << "No Enough Stock Available " << endl;
		else if (ErrorCode == -3) cout << "DemoBooks are not for Sale" << endl;
	}

}	