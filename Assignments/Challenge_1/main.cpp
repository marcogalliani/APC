//
//  main.cpp
//  Determinant2
//
//  Created by ing.conti on 07/10/22.
//

#include <iostream>
#include "Matrix.h"

int main(int argc, const char * argv[]) {
    
    // see this file for declaration,
    #include "TestValues.h"

    m1.print();

    m1.complementary(1,1).print();

    m1.print();

    double det = m1.determinant();
    std::cout << det << std::endl;

    return 0;
}
