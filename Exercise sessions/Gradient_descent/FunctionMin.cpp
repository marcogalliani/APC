//
// Created by Marco Galliani on 18/10/22.
//

#include "FunctionMin.h"
#include <iostream>
#include <cmath>
#include <random>


FunctionMin::FunctionMin(const Function &f, double supLimit, double infLimit, double tolerance, double step,double max_it) : f(f),
                                                                                                               sup_limit(supLimit),
                                                                                                               inf_limit(infLimit),
                                                                                                               tolerance(tolerance),
                                                                                                               step(step),
                                                                                                               max_iterations(max_it){}

double FunctionMin::solve(double x_init) const{
    Function df=f.derivative();

    double x0=x_init;
    double f0=f.eval(x0);

    bool converged = ((sup_limit-inf_limit)<tolerance)|| std::abs(df.eval(x0))<tolerance;

    for (int i = 0; i < max_iterations && !converged; ++i) {
        //evaluate derivative
        const double deriv = df.eval(x0);
        //compute next point
        double x1 = x0-step*deriv;

        if(deriv>0)
            x1=std::max(inf_limit,x1);
        else
            x1=std::max(sup_limit,x1);
        //compute new function value
        const double f1=f.eval(x1);
        //check convergence
        converged = std::abs(x1-x0)<tolerance|| std::abs(df.eval(x1))<tolerance || std::abs(f1-f0)<tolerance;

        //update x0,f0;
        x0=x1;
        f0=f1;
    }
    return x0;
}

double FunctionMin::solve() const{
    return solve((sup_limit-inf_limit)/2);
}


double FunctionMin::solve_multistart(unsigned n_trials) const{

    std::default_random_engine generator(4850); //we pass the seed
    std::uniform_real_distribution<double> distribution(inf_limit,sup_limit);

    double x_min = solve();
    double f_min = f.eval(x_min);

    for (unsigned n = 1; n < n_trials ; ++n) {
        const double x_guess = distribution(generator);

        double x_new = solve(x_guess);
        double f_new = f.eval(x_new);

        if (f_new<f_min){
            x_min = x_new;
            f_min = f_new;
        }
    }

    return x_min;
}

double FunctionMin::solve_domain_decomposition(unsigned n_intervals, unsigned n_trials) const{

    const double internal_step = (sup_limit-inf_limit)/n_intervals;

    double internal_inf = inf_limit;
    double x_min = inf_limit;

    for (unsigned i = 1; i < n_intervals; ++i) {
        FunctionMin minf_int=FunctionMin(f,internal_inf,internal_inf+internal_step,tolerance,step,max_iterations);
        const double x_iter = minf_int.solve_multistart(n_trials);

        if (f.eval(x_iter)<f.eval(x_min))
            x_min = x_iter;

        internal_inf+=internal_step;
    }

    return x_min;
}
