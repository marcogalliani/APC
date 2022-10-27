//
// Created by Marco Galliani on 18/10/22.
//

#ifndef GRRAD_FUNCTION_H
#define GRRAD_FUNCTION_H

#include <iostream>
#include <vector>
#include "Monomials.h"
#include "Point.h"

using std::vector;

// polynomial function
class Function {

private:
    vector<Monomials> polynomial;

public:
    double eval(const Point & p) const;

    Function derivative(int direction) const;

    void addMonomial (const Monomials & m);
};


#endif //GRRAD_FUNCTION_H
