//
// Created by Marco Galliani on 18/10/22.
//

#ifndef GRRAD_FUNCTIONMIN_H
#define GRRAD_FUNCTIONMIN_H

#include "Function.h"

class FunctionMin {

private:
    static constexpr bool debug = true;

    Function f;
    std::vector<double> sup_limits;
    std::vector<double> inf_limits;

    double tolerance;
    double step;
    double max_iterations;

    Point compute_gradient(const Point & p) const;

    Point solve(const Point & p) const;

    /*void next_inf_limit (std::vector<double> & cur_inf_limit,
                         const std::vector<double> & internal_steps) const;*/

public:
    FunctionMin(const Function &f, const vector<double> &supLimit, const vector<double> &infLimit, double tolerance,
                double step, double maxIterations);


    Point solve(void) const;
    //Point solve_multistart(unsigned n_trials) const;
    //Point solve_domain_decomposition(unsigned n_intervals, unsigned n_trials) const;

    void debug_info (const std::string& s) const;

    void debug_info (const std::string& s1, double val) const;
};


#endif //GRRAD_FUNCTIONMIN_H
