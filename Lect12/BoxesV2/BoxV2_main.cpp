#include <vector>

#include "Box.h"

using std::cout;
using std::endl;

int main()
{
    cout << endl;

    // first box
    Box b1(10,10,10);
    double v1 = b1.volume();
    cout << "volume of box 1 (10x10x10) is: " << v1 << endl;
    cout << "box id: " << b1.getid() << endl;
    cout << "count: " << Box::getcount() << endl;
    cout << endl;

    // second box
    Box b2(10,20,30);
    double v2 = b2.volume();
    cout << "volume of box 2 (10x20x30) is: " << v2 << endl;
    cout << "box id: " << b2.getid() << endl;
    cout << "count: " << Box::getcount() << endl;
    cout << endl;

    // third box
    Box b3(b1);
    double v3 = b3.volume();
    cout << "box 3 is equal to box 1" << endl;
    cout << "volume of box 3 is: " << v3 << endl;
    cout << "box id: " << b3.getid() << endl;
    cout << "count: " << Box::getcount() << endl;
    cout << endl;

    cout << "now box 3 is equal to box 1" << endl;
    b3 = b2;
    double v3_new = b3.volume();
    cout << "new volume of box 3 is: " << v3_new << endl;
    cout << "new box id: " << b3.getid() << endl;
    cout << "count: " << Box::getcount() << endl;
    cout << endl;

    //previous part as V1

    //following part differs

    //Here initializing the vector of boxes, we just created 3 new boxes with volumes equal to box 1,2,3
    std::vector<Box> boxes = {b1, b2, b3};
    cout << "\nid of new boxes: " << endl;

    //Here we're creating more boxes with volumes equal to box 1,2,3
    for (const Box& b : boxes)

        cout << b.getid() << endl;
    cout << "count: " << Box::getcount() << endl;

    return 0;
}
