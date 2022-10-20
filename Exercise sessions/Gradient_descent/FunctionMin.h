//
// Created by Marco Galliani on 18/10/22.
//

#ifndef GRRAD_FUNCTIONMIN_H
#define GRRAD_FUNCTIONMIN_H

#include "Function.h"

class FunctionMin {
public:
    FunctionMin(const Function &f, double supLimit, double infLimit, double tolerance, double step, double max_it);

private:
    Function f;
    double sup_limit;
    double inf_limit;

    double tolerance;
    double step;
    double max_iterations;

    double solve(double x_init) const;

public:
    double solve() const;
    double solve_multistart(unsigned n_trials) const;
    double solve_domain_decomposition(unsigned n_intervals, unsigned n_trials) const;
};


#endif //GRRAD_FUNCTIONMIN_H
