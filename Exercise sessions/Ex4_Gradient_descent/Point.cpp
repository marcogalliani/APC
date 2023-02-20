//
// Created by Marco Galliani on 26/10/22.
//

#include "Point.h"
#include <cmath>

Point::Point(const coords & c) : x(c) {}

size_t Point::get_dim(void) const{
    return x.size();
}

double Point::get_coord(size_t i) const {
    return x[i];
}

void Point::set_coord(size_t i, double val) {
    x[i]=val;
}

coords Point::getX() const {
    return x;
}

double Point::distance (const Point & p) const{
    double dist = 0.0;

    for (std::size_t i = 0; i < x.size (); ++i)
    {
        const double delta = x[i] - p.x[i];
        dist += delta * delta;
    }

    return sqrt (dist);
}

double Point::euclidean_norm(void) const {
    const std::vector<double> zero_vector (x.size (), 0.);
    const Point origin (zero_vector);
    return distance (origin);
}

double Point::infinity_norm(void) const {
    double max_value = std::abs (x[0]);

    for (std::size_t i = 1; i < x.size (); ++i)
    {
        const double next = std::abs (x[i]);
        if (next > max_value)
            max_value = next;
    }

    return max_value;
}

void Point::print (void) const
{
    for (auto it = x.begin (); it != x.end (); ++it)
    {
        std::cout << *it;
        std::cout << " ";
    }

    std::cout << std::endl;
}

