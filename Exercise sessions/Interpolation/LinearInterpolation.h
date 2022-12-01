#ifndef LINEAR_INTERPOLATION_HH
#define LINEAR_INTERPOLATION_HH

#include <vector>
#include "Interpolation.h"

class LinearInterpolation : public Interpolation{

public:

  explicit LinearInterpolation (const std::vector<Point> & p); //explicit avoid implicit conversions

  virtual double interpolate (double) const override; //Let's specify function implementation

};

#endif // LINEAR_INTERPOLATION_HH
