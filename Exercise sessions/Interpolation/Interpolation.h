#ifndef INTERPOLATION_HH
#define INTERPOLATION_HH

#include <vector>
#include <iostream>
#include "Point.h"

class Interpolation
{
   /* TO BE COMPLETED */
protected:
  std::vector<Point> points; // sorted_vector

  static constexpr double err_val = std::numeric_limits<double>::quiet_NaN(); //library numeric_limits provide this const

  bool range_check(double x) const;

public:
    Interpolation(const std::vector<Point> &p): points(p){};

    virtual double interpolate (double) const =0; // make it pure virtual

    //with abstract classes we need to define a destructor
    //virtual ~Interpolation(){std::cout << "Parente" << std::endl}


};

#endif // INTERPOLATION_HH
