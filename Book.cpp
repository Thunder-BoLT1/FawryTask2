#include "Book.h"


Book::Book(string isbn, string title, int year, double price) {
	ISBN = isbn;
	Title = title;
	Year = year;
	setPrice(price);
}

void Book::setPrice(double price) {
	if (price >= 0) Price = price;
}

string Book::getISBN() const { return ISBN; }

string Book::getTitle() const { return Title; }

int Book::getYear() const { return Year; }

double Book::getPrice() const { return Price; }

ostream& operator <<(ostream& o, Book& book) {
	o << book.getISBN() << " " << book.getTitle() << " " << book.getYear() << " " << book.getPrice();
	return o;
}
