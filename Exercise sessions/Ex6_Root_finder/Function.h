//
// Created by Marco Galliani on 18/10/22.
//

#ifndef GRRAD_FUNCTION_H
#define GRRAD_FUNCTION_H

#include <iostream>
#include <vector>

using std::vector;

// polynomial function
class Function {

private:
    vector<double> coefficients;

public:
    Function( const vector<double> & f_init);
    double eval(double x) const;
    Function derivative() const;
    void print() const;
};


#endif //GRRAD_FUNCTION_H
