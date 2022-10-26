//
// Created by Marco Galliani on 26/10/22.
//

#include "Bisection.h"

real Bisection::find_root(int &nit){


    real u = f.eval(inf_limit);  // Evaluate f on boundary a
    real l = inf_limit - sup_limit; // Interval length
    real r;         // Residual
    real c = inf_limit + l;   // Middle point

    nit = 0;
    r = f.eval(c);

    if (u * f.eval(sup_limit) >= 0.0) {
        std::cout << "Error Function has same sign at both endpoints" << std::endl;
        return -std::numeric_limits<double>::infinity();
    }

    while (!(converged(fabs(l), fabs(r), tolerance))
           && (nit <= maxit)) {

        (u * r < 0.) ? (sup_limit = c) : (inf_limit= c, u = r);

        l *= 0.5;
        c = inf_limit + l;
        r = f.eval(c);
        ++nit;
    }
    return c;
}

Bisection::Bisection(const Function &f, real tolerance, int maxit, checkT terminationCriterion, real infLimit,
                     real supLimit) : RootFinder(f, tolerance, maxit, terminationCriterion), inf_limit(infLimit),
                                      sup_limit(supLimit) {}
