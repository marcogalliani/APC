#include <iostream>
#include "Tensor.h"

int main() {

    //Initialising
    std::cout << "Initializing t0"<< std::endl;
    Tensor t0({}); // Fatal error
    std::cout << "Initializing t1"<< std::endl;
    Tensor t1({1});
    std::cout << "Initializing t2"<< std::endl;
    Tensor t2({2,2});
    std::cout << "Initializing t3"<< std::endl;
    Tensor t3({3,3,3});

    //setting values
    std::cout << "Setting t1"<< std::endl;
    t1.set(1,0); //OK
    std::cout << "Setting t2"<< std::endl;
    t2.set(-2,0,1); //OK
    t2.set(1,0,0); //OK
    t2.set(2,0,0); //OK
    std::cout << "Setting t3"<< std::endl;

    //getting values
    t3.set(3,2,2,2); //OK
    std::cout << "t1[0]: " << t1.get(0) << std::endl; //OK
    std::cout << "t2[0](error): " <<t2.get(0) << std::endl; // Out of bound index
    std::cout << "t2[0][0]: " <<t2.get(0,0) << std::endl; // OK
    std::cout << "t3[2][2][2]: " <<t3.get(2,2,2) << std::endl; // OK
    std::cout << "t3[3][3][3](error): " <<t3.get(3,3,3) << std::endl; // Out of bound index
    std::cout << "t1[1](error): " << t1.get(1) << std::endl; // Out of bound index
    std::cout << "t2[1][0](error): " << t2.get(1,0) << std::endl; // Out of bound index

    //computing norms
    std::cout << "t1 norms " << std::endl;
    std::cout << "Euclidean norm " << t1.norm("2") << std::endl; //OK
    std::cout << "Frobenius norm " << t1.norm("frob") << std::endl; // Error
    std::cout << "Frobenius norm " << t1.norm("fro") << std::endl; // Error
    std::cout << "Infinity norm " << t1.norm("inf") << std::endl; // OK
    std::cout << "t2  Frobenius norm " << t2.norm("fro") << std::endl;


    Tensor t4({3,3,3});
    t4= t3*3;

    std::cout << "t1 : "<< std::endl;
    t1.print();
    std::cout << std::endl;
    std::cout << "t2 : "<< std::endl;
    t2.print();
    std::cout << std::endl;
    std::cout << "t3 : "<< std::endl;
    t3.print();
    std::cout << std::endl;
    std::cout << "t4 : "<< std::endl;
    t4.print();
    std::cout << std::endl;
    return 0;
}
