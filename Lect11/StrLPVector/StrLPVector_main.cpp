#include <iostream>
#include "StrLPVector.h"

int main()
{
    //initialize the smart_ptr inside StrLPVector with {"a", "list", "of", "words"}
    StrLPVector sv1({"a", "list", "of", "words"});

    //initialize sv2 with sv1 (using synthetized (copy)constructor)
    StrLPVector sv2(sv1);

    //use method front of vectors to print the front of each inner dynamic vector
    std::cout << "sv1.front() is: " << sv1.front() << std::endl;
    std::cout << "sv2.front() is: " << sv2.front() << std::endl;

    //initialize sv3 with sv2 (using synthetized assignement operartor)
    StrLPVector sv3 = sv2;
    //add an element to inner dynamic vector of sv3
    sv3.push_back("new element");

    //use method front of vectors to print the back of each inner dynamic vector (that is the same since all private smart_ptr
    // point to the same vector)
    std::cout << "sv1.back() is: " << sv1.back() << std::endl;
    std::cout << "sv2.back() is: " << sv2.back() << std::endl;
    std::cout << "sv3.back() is: " << sv3.back() << std::endl;
}
