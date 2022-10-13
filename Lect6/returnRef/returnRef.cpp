#include <iostream>

#include "BaseKO.h"
#include "BaseOK.h"

using std::cout;
using std::endl;

int main() {
    int a, b, c;
    a = 0;
    b = 1;
    c = 2;
    a = b = c; //a=b; b=c;

    cout << "Base type" << endl;
    cout << a << " "  << b << " " << c << endl;

    a = 0;
    b = 1;
    c = 2;
    (a = b) = c; // a=b; a=c;

    cout << a << " "  << b << " " << c << endl;

    BaseKO a_objko(0);
    BaseKO b_objko(1);
    BaseKO c_objko(2);


    a_objko = b_objko = c_objko;
    cout << "BaseKO" << endl;
    cout << a_objko.get_x() << " "
         << b_objko.get_x() << " " << c_objko.get_x() << endl;

    a_objko.set_x(0);
    b_objko.set_x(1);
    c_objko.set_x(2);

    (a_objko = b_objko) = c_objko; //we obtain a different result from the desired result
    //This derives from the implementation: we implemented the operator = to return a copy, not a refernce
    cout << a_objko.get_x() << " "
         << b_objko.get_x() << " " << c_objko.get_x() << endl;


    BaseOK a_objok(0);
    BaseOK b_objok(1);
    BaseOK c_objok(2);


    a_objok = b_objok = c_objok;
    cout << "BaseOK" << endl;
    cout << a_objok.get_x() << " "
         << b_objok.get_x() << " " << c_objok.get_x() << endl;

    a_objok.set_x(0);
    b_objok.set_x(1);
    c_objok.set_x(2);

    (a_objok = b_objok) = c_objok; //desired result
    //The operator = return a reference
    // IMPORTANT: GENERAL ASSIGNMENT OPERATOR HAVE TO RETURN A REFERENCE, NOT A COPY
    cout << a_objok.get_x() << " "
         << b_objok.get_x() << " " << c_objok.get_x() << endl;


    return 0;
}
