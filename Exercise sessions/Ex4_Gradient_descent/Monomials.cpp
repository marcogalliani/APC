//
// Created by Marco Galliani on 26/10/22.
//

#include "Monomials.h"
#include <cmath>

Monomials::Monomials(double coeff, const std::vector<double> &powers) : coeff(coeff), powers(powers) {}

double Monomials::getCoeff() const {
    return coeff;
}

const std::vector<double> &Monomials::getPowers() const {
    return powers;
}

double Monomials::eval(const Point & p) const {
    double val = 1;

    for (int i = 0; i < powers.size(); ++i) {
        val *= pow(p.get_coord(i),powers[i]);
    }
    return coeff*val;
}

Monomials Monomials::derivative(int direction) const{
    std::vector<double> pow_adj=powers;
    pow_adj[direction]-=1;
    return Monomials(coeff*powers[direction],pow_adj);
}


