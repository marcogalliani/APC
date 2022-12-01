#include "NearestNeighborInterpolation.h"

/* TO BE COMPLETED */

NearestNeighborInterpolation::NearestNeighborInterpolation (const std::vector<Point> & points): Interpolation(points){}

double
NearestNeighborInterpolation::interpolate (double x) const{
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
            const double previous_distance = x-previous->get_x();
            const double current_distance = current->get_x()-x;
            bool previous_closest=previous_distance<current_distance;
            if(previous_closest)
                result = previous->get_y();
            else
                result = current->get_y();

            //result= previous_closest ? previous->get_y() : current->get_y();

        }

    }
    return result;

}
