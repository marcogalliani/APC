#include <iostream>
#include "Complex.h"

int main()
{
    Complex c1(5, 2);
    std::cout << "c1 = ";
    c1.print();

    Complex c2(6, 3);
    std::cout << "c2 = ";
    c2.print();

    Complex c3 = c1;
    std::cout << "c3 = ";
    c3.print();

    Complex c4(2, 0);
    std::cout << "c4 (polar coordinates) = ";
    c4.print_polar();

    Complex c5 = c1 + c2;
    std::cout << "c5 = c1 + c2 = ";
    c5.print();

    c5 = c2 - c4;
    std::cout << "c5 = c2 - c4 = ";
    c5.print();

    c5 = c2 * c4;
    std::cout << "c2 (polar coordinates) = ";
    c2.print_polar();
    std::cout << "c5 = c2 * c4 (polar coordinates) = ";
    c5.print_polar();

    return 0;
}
//Correct output:
/*c1 = (5) + (2)i
        c2 = (6) + (3)i
        c3 = (5) + (2)i
c4 (polar coordinates) = 2[cos(0) + i*sin(0)]
c5 = c1 + c2 = (11) + (5)i
        c5 = c2 - c4 = (4) + (3)i
c2 (polar coordinates) = 6.7082[cos(0.463648) + i*sin(0.463648)]
c5 = c2 * c4 (polar coordinates) = 13.4164[cos(0.463648) + i*sin(0.463648)]
*/