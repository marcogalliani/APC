//
// Created by Marco Galliani on 26/10/22.
//

#ifndef GRADIENT_DESCENT_MONOMIALS_H
#define GRADIENT_DESCENT_MONOMIALS_H

#include <vector>
#include <iostream>
#include "Point.h"

class Monomials {
private:
    double coeff;
    std::vector<double> powers;

public:
    Monomials(double coeff, const std::vector<double> &powers);

    double getCoeff() const;

    const std::vector<double> &getPowers() const;

    double eval(const Point & p) const;

    Monomials derivative(int direction) const;

    void print() const;
};


#endif //GRADIENT_DESCENT_MONOMIALS_H
