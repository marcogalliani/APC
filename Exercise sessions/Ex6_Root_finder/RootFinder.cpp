//
// Created by Marco Galliani on 26/10/22.
//

#include "RootFinder.h"

bool RootFinder::converged(real increment, real residual, real tol) {
    switch (termination_criterion) {
        case INCREMENT:return (increment < tolerance);
        case RESIDUAL:return (residual < tolerance);
        case BOTH:return ((increment < tolerance) && (residual < tolerance));
        default:return false;
    }
}

RootFinder::RootFinder(const Function &f, real tolerance, int maxit, checkT terminationCriterion) : f(f), tolerance(
        tolerance), maxit(maxit), termination_criterion(terminationCriterion) {}
