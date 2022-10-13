#include <iostream>
#include "Book.h"
#include "Library.h"


int main() {
    Book b1(1, 2014, 1399, "S. B. Lippman", "C++ primer", true);

    Book b2(2, 2013, 1361, "B. Stroustrup", "The C++ programming language", true);


    b1.print();
    b2.print();

    Library lib;

    lib.addBook(b1);
    lib.addBook(b2);

    lib.rentBook("S. B. Lippman", "C++ primer");

    lib.print();
    cout << "****************+"<< endl;
    cout << "Stato prestito: "<< lib.rentBook("S. B. Lippman", "C++ primer")<<endl;
    lib.print();
    cout << "****************+"<< endl;

    cout << "Stato restituzione: "<< lib.returnBook(1) << endl;
    lib.print();
    cout << "****************+"<< endl;

    cout << "Stato restituzione: "<< lib.returnBook(1)<<endl;
    lib.print();

    cout << "****************+"<< endl;

    cout << "Oldest book" << endl;

    lib.printOldest();
    return 0;

}