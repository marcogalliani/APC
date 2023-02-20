//
// Created by Marco Galliani on 26/10/22.
//

#ifndef GRADIENT_DESCENT_POINT_H
#define GRADIENT_DESCENT_POINT_H

#include <iostream>
#include <vector>

typedef std::vector<double> coords;

class Point {


protected:
    coords x;
public:
    explicit Point(const coords & c);

    size_t get_dim(void) const;

    double get_coord (size_t i) const;
    void set_coord (size_t i, double val);

    coords getX() const;

    double distance (const Point & p) const;

    double euclidean_norm (void) const;
    double infinity_norm (void) const;

    void print (void) const;
};


#endif //GRADIENT_DESCENT_POINT_H
