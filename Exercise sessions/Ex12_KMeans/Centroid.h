#ifndef CENTROID_H_
#define CENTROID_H_

#include <iostream>
#include <vector>

#include "Point.h"


// a centroid is a point --> derived class

class Centroid : public Point
{
public:
  // constructor relies on the root class constructor
  Centroid (std::vector<double> const & coords): Point (coords) {};

  // avoiding copies with &
  void update_coords (std::vector<Point *> const &);
};

#endif /* CENTROID_H_ */
