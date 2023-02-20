#include <iostream>

#include "LinearInterpolation.h"
#include "StepwiseInterpolation.h"
#include "NearestNeighborInterpolation.h"

int
main (void)
{
    std::vector<Point> points {
    Point (1.0, 0.0),
      Point (2.0, 3.0),
      Point (3.0, 1.0),
      Point (4.0, 2.0),
      Point (5.0, 4.0)
      };

    double x = 4.0;
    //std::cin >> x;

    /* TO BE COMPLETED */

    LinearInterpolation method1(points);
    std::cout << "Linear: y = " << method1.interpolate(x) << std::endl;

    StepwiseInterpolation method2(points);
    std::cout << "Stepwise: y = " << method2.interpolate(x) << std::endl;

    NearestNeighborInterpolation method3(points);
    std::cout << "NearestNeighbor: y = " << method3.interpolate(x) << std::endl;


    //We can initialize a pointer of class interpolation
    Interpolation* p_method;

    //It can be initialize with each child class object
    p_method = &method1;

    std::cout << "Pointer: y = " << p_method->interpolate(x) << std::endl;
    //it understand automatically that the interpolate method we want to use is the one of the pointed object

    //if we would have not used virtual and override this wouldn't happened

    return 0;
}
