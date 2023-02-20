//
// Created by Danilo Ardagna on 2019-09-28.
//

#ifndef LIBRARYINITIALCODE_BOOK_H
#define LIBRARYINITIALCODE_BOOK_H


#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Book {
private:
    unsigned code;
    unsigned year;
    unsigned pages;
    string author;
    string title;
    bool available;

public:
    /* YOUR CODE GOES HERE */
    Book(unsigned code, unsigned year, unsigned pages, const string &author, const string &title, bool available);

    unsigned int getCode() const;

    unsigned int getYear() const;

    unsigned int getPages() const;

    const string getAuthor() const;

    void setAvailable(bool av);

    bool isAvailable() const;

    const string getTitle() const;

    bool equal_to(const string &aut, const string &t) const;

    void print() const;
};


#endif //LIBRARYINITIALCODE_BOOK_H
