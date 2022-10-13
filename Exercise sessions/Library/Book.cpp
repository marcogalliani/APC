//
// Created by Danilo Ardagna on 2019-09-28.
//

#include "Book.h"

/* YOUR CODE GOES HERE */

Book::Book(unsigned code, unsigned year, unsigned pages, const string &author, const string &title, bool available): code(code),
    year(year), pages(pages), author(author), title(title), available(available){}

unsigned int Book::getCode() const{
    return code;
}

unsigned int Book::getYear() const{
    return year;
}

unsigned int Book::getPages() const{
    return pages;
}

const string Book::getAuthor() const{
    return author;
}

void Book::setAvailable(bool av){
    available=av;
}

bool Book::isAvailable() const{
    return available;
}

const string Book::getTitle() const{
    return title;
}

bool Book::equal_to(const string &aut, const string &t) const{
    return author==aut && title==t;
}

void Book::print() const{
    cout << code << "\n"
         << author << "\n"
         << title << "\n"
         << pages << "\n"
         << year << "\n";

    if (available)
        cout << "Available";
    else
        cout << "Not available";

    cout << endl;
}
