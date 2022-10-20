//============================================================================
// Name        : Inheritance2.cpp
// Author      : user
// Version     :
// Copyright   :
//============================================================================

#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

double print_total(const Quote &item, size_t n);
double print_total2(const Quote item, size_t n);

int main() {

	Quote basic("123", 1);
	Bulk_quote bulk("123", 1, 10, 0.1);

	// basic has type Quote; bulk has type Bulk_quote

	print_total(basic, 20); // calls Quote version of net_price

	print_total(bulk, 20); // calls Bulk_quote version of net_price

	print_total2(bulk, 20); // calls Quote version of net_price!!!

	cout << bulk.net_price(20)<<std::endl;

	return 0;
}

// calculate and print the price for the given number of copies,
// applying any discounts
double print_total(const Quote &item, size_t n)
{
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	cout << "ISBN: " << item.isbn() // calls Quote::isbn
	<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

double print_total2(const Quote item, size_t n)
{
	// calls always Quote::net_price
	double ret = item.net_price(n);
	cout << "ISBN: " << item.isbn() // calls Quote::isbn
	<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
