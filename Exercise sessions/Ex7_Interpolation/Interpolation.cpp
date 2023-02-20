#include "Interpolation.h"

/* TO BE COMPLETED */
bool Interpolation::range_check(double x) const {
    bool b1 = (x >= points.front().get_x()); //points[0]
    bool b2 = (x <= points.back().get_x()); //points[points.size()-1]
    return b1 and b2;
}
