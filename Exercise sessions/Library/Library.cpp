//
// Created by Danilo Ardagna on 2019-09-28.
//

#include "Library.h"

/* YOUR CODE GOES HERE */
int Library::find(const string &author, const string &title) const {
    int i;
    for (i=0; i<books.size();i++){
        if (books[i].equal_to(author,title))
            return i;
    }
    return -1;
}

int Library::findAvailableBook(const string &author, const string &title) const {
    int i;
    for (i=0; i<books.size();i++){
        if (books[i].equal_to(author,title) && books[i].isAvailable())
            return i;
    }
    return -1;
}

void Library::addBook(const Book &book) {
    books.push_back(book);
}

int Library::rentBook(const string &author, const string &title) {
    if (findAvailableBook(author,title)!=-1) {
        books[findAvailableBook(author, title)].setAvailable(false);
        return books[findAvailableBook(author, title)].getCode();
    }
    else
        return -1;
}

bool Library::returnBook(unsigned int code) {
    int flag=0,i;
    for ( i=0; i < books.size() && flag==0; ++i) {
        if(code==books[i].getCode())
            if (books[i].isAvailable()==1)
                return false;
            flag = 1;

    }
    if(flag==1) {
        books[i-1].setAvailable(true);
        return true;
    }
    else
        return false;
}

void Library::print() const {
    for (int i = 0; i < books.size() ; ++i) {
        books[i].print();
    }
}

void Library::printOldest() const {
    Book oldest=books[0];
    for (int i = 0; i <books.size(); ++i) {
        if(oldest.getYear()>books[i].getYear())
            oldest=books[i];
    }
    oldest.print();
}
