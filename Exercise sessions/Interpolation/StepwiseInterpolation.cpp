#include "StepwiseInterpolation.h"

/* TO BE COMPLETED */

StepwiseInterpolation::StepwiseInterpolation (const std::vector<Point> & points): Interpolation(points){}


double
StepwiseInterpolation::interpolate (double x) const{
    double result(err_val);

    std::vector<Point>::const_iterator previous = points.cbegin();
    std::vector<Point>::const_iterator current = previous+1;

    if (range_check(x)) {

        while (current != points.cend() && current->get_x() < x) {
            ++current;
            ++previous;
        }

        if (current != points.cend()) {
            //compute y
            result = previous->get_y();

        }

    }
    return result;

}


