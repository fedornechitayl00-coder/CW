#include "Product.h"
#include <string>

Product::Product()
{
	title = "Undefined";
	price = 0;
	termSave = 0;
	madeDate = Date(2000, 1, 1);
}

Product::Product(std::string title, float price, Date madeDate, int termSave)
{
	this->title = title;
	this->price = price;
	this->termSave = termSave;
	this->madeDate = madeDate;
}

void Product::setTitle(std::string title)
{
	this->title = title;
}

std::string Product::getTitle() const
{
	return title;
}

void Product::setPrice(float price)
{
	this->price = price;
}

float Product::getPrice() const
{
	return price;
}

Date Product::getMadeDate() const
{
	return madeDate;
}

int Product::getTerm() const
{
	return termSave;
}

bool Product::isExpired() const
{
	return madeDate + termSave < Date();
}

std::ostream& operator<<(std::ostream& out, const Product& obj)
{
	out << "_____________________________________________\n"
		<< "Title: " << obj.title << "\nPrice: " << obj.price
		<< "\nMade date: " << obj.madeDate << "\n Expired date: " << (obj.termSave + obj.madeDate) << std::endl
		<< (obj.isExpired() ? "EXPIRED PRODUCT" : " ") << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Product& obj)
{
	std::cout << "Input title: ";
	getline(in, obj.title);
	std::cout << "Input price: ";
	in >> obj.price;
	std::cout << "Input date of Manufactury: ";
	in >> obj.madeDate;
	std::cout << "Input term in days: ";
	in >> obj.termSave;
	return in;
}
