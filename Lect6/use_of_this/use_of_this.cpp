#include <iostream>
#include "X.h"

int main() {
    X obj(3);
    std::cout << "Hello, World!" << std::endl;
    //we get random values because we're losing the values passed. See the implementation
    //X_fixed.cpp solves the problems using "this" operator

    std::cout << obj.getMember() << std::endl;
    obj.setMember(10);
    std::cout << obj.getMember() << std::endl;
    return 0;
}
