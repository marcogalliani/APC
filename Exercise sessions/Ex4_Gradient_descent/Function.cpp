//
// Created by Marco Galliani on 18/10/22.
//

#include "Function.h"
#include <cmath>
#include <iostream>
#include <vector>

void Function::addMonomial (const Monomials & m){
    polynomial.push_back(m);
}


double Function::eval(const Point & p) const{
    double val =0.0;
    for (auto m:polynomial) {
        val+=m.eval(p);
    }
    return val;
}

Function Function::derivative(int direction) const{
    Function df;

    for (auto m:polynomial)
        df.polynomial.push_back(m.derivative(direction));

    return df;
}







