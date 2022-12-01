#include "LinearInterpolation.h"

/* TO BE COMPLETED */

LinearInterpolation::LinearInterpolation (const std::vector<Point> & p): Interpolation(p){}


double LinearInterpolation::interpolate (double x) const{
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
            const double x1 = previous->get_x(); // (*previous).get_x()
            const double x2 = current->get_x();
            const double y1 = previous->get_y();
            const double y2 = current->get_y();

            result = y1 + (y2-y1)*(x-x1)/(x2-x1);


        }

    }


    return result;
}
