//
// Created by Marco Galliani on 20/10/22.
//

#ifndef LECT10_DISC_QUOTE_H
#define LECT10_DISC_QUOTE_H

#include <iostream>
#include "Quote.h"
#include <string>


class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string & book, double price,
               size_t qty, double disc):
            Quote(book, price), quantity(qty),
            discount(disc) { }
    virtual double net_price(std::size_t) const = 0; protected:
    size_t quantity = 0; // purchase size for the discount to // apply
    double discount = 0.0; // fractional discount to apply };
};


#endif //LECT10_DISC_QUOTE_H
