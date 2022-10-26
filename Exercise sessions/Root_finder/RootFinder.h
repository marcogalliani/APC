//
// Created by Marco Galliani on 26/10/22.
//

#ifndef ROOTFINDERALLINONE_ROOTFINDER_H
#define ROOTFINDERALLINONE_ROOTFINDER_H

#include "Function.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>

typedef double real;

enum checkT {
    INCREMENT, //! Check the difference between subsequent iterates
    RESIDUAL,  //! Check the residual
    BOTH       //! Check both conditions
};


class RootFinder {
protected:
    Function f;
    real tolerance;
    int maxit;
    checkT termination_criterion;

public:
    RootFinder(const Function &f, real tolerance, int maxit, checkT terminationCriterion);

    bool converged(real increment, real residual,
                   real tol);
};


#endif //ROOTFINDERALLINONE_ROOTFINDER_H
