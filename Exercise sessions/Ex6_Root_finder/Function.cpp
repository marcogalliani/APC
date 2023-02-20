//
// Created by Marco Galliani on 18/10/22.
//

#include "Function.h"
#include <cmath>
#include <iostream>
#include <vector>

double Function::eval(double x) const{
    double val =0.0;
    for (size_t i = 0; i < coefficients.size() ; ++i) {
        val+=coefficients[i]*pow(x,i);
    }
    return val;
}

Function Function::derivative() const{
    std::vector<double> dcoeffs;

    for (size_t i = 0; i <coefficients.size() ; ++i)
        dcoeffs.push_back((i+1)*coefficients[i+1]);

    return Function(dcoeffs);
}

void Function::print() const
{
    for (size_t i = 0; i < coefficients.size(); i++)
        std::cout << coefficients[i] << "  ";
    std::cout << std::endl;
}

Function::Function(const vector<double> &f_init) :coefficients(f_init){}




