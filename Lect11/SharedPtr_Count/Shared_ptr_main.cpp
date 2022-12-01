#include <iostream>
#include <memory>

using std::shared_ptr;
using std::make_shared;

int main()
{
    //create a smart ptr, pointing an int initialized at value 2
    shared_ptr<int> p1 = make_shared<int>(2);

    //print how many pointers point to the element pointed by p1
    std::cout << p1.use_count() << std::endl;

    //create another smart pointer pointing to the element pointed by p1
    shared_ptr<int> p2(p1);

    //print how many pointers point to the element pointed by p1 and p2: it should be 2 in each case
    std::cout << p1.use_count() << "; " << p2.use_count() << std::endl;

    //create a smart ptr, pointing an int initialized at value 10
    shared_ptr<int> p3 = make_shared<int>(10);

    //print how many pointers point to the element pointed by p3
    std::cout << p3.use_count() << std::endl;


    //p1 now points to the element pointed by p3. Count of p2 decreases by 1, count of p3 increases by 1 (p1 points to the same
    // element of p3 and so it has the count)
    p1 = p3;
    std::cout << p1.use_count() << "; " 
              << p2.use_count() << "; " 
              << p3.use_count() << std::endl;

    return 0;
}
