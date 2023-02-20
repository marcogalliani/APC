//
// Created by Marco Galliani on 18/10/22.
//

#include "FunctionMin.h"
#include <iostream>
#include <cmath>
#include <random>

FunctionMin::FunctionMin(const Function &f, const vector<double> &supLimit, const vector<double> &infLimit,
                         double tolerance, double step, double maxIterations) : f(f), sup_limits(supLimit),
                                                                                inf_limits(infLimit),
                                                                                tolerance(tolerance), step(step),
                                                                                max_iterations(maxIterations) {}


Point FunctionMin::compute_gradient (const Point & P0) const
{
    std::vector<double> grad;

    for (std::size_t j = 0; j < P0.get_dim(); ++j)
        grad.push_back (f.derivative(j).eval(P0));

    return Point (grad);
}

Point FunctionMin::solve(const Point & P) const{
    /*Function df=f.derivative();

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
    return x0;*/

    if (debug)
    {
        for (double ii: inf_limits)
            std::cout << ii << " ";
        std::cout << std::endl;

        for (double ss: sup_limits)
            std::cout << ss << " ";
        std::cout << std::endl;
    }

    Point P0 (P.getX());
    double f0 = f.eval (P0);
    bool converged = false;

    debug_info("Starting gradient");    //if (debug) {std::cout << "Starting gradient" << std::endl;}

    for (unsigned int iter = 0; iter < max_iterations && ! converged; ++iter)
    {
        if (debug)
        {
            std::cout << "P0: ";
            P0.print ();
        }

        for (std::size_t j = 0; j < P0.get_dim(); ++j)
        {
            const double grad_j = f.derivative(j).eval(P0);
            debug_info ("grad_j", grad_j);
            double new_x = P0.get_coord (j) - grad_j * step;
            debug_info ("new_x", new_x);

            if (grad_j > 0)
                new_x = std::max (inf_limits[j], new_x);
            else
                new_x = std::min (sup_limits[j], new_x);

            debug_info ("new_x", new_x);
            P0.set_coord (j, new_x);

            if (debug)
                P0.print();
        }

        //compute function in the new point
        const double f1 = f.eval (P0);
        debug_info ("f1", f1);

        //update gradient in the new point
        const Point grad = compute_gradient (P0);

        if (debug)
        {
            std::cout << "grad" << std::endl;
            grad.print ();
        }

        debug_info ("delta f", std::abs (f1 - f0));
        debug_info ("infinity_norm", grad.infinity_norm ());
        converged = (std::abs (f1 - f0) < tolerance) ||
                    (grad.infinity_norm () < tolerance);

        f0 = f1;
    }

    return P0;
}

Point FunctionMin::solve() const{
   // return solve((sup_limit-inf_limit)/2);
    std::vector<double> initial_coords;

    //compute domain mid point
    for (std::size_t i = 0; i < sup_limits.size (); ++i)
        initial_coords.push_back ((sup_limits[i] + inf_limits[i]) / 2);
    const Point P (initial_coords);

    return solve (P);
}


/*double FunctionMin::solve_multistart(unsigned n_trials) const{

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
*/

void FunctionMin::debug_info (const std::string& s) const
{
    if (debug)
        std::cout << s << " " << std::endl;
}

void FunctionMin::debug_info (const std::string& s, double val) const
{
    if (debug)
        std::cout << s << " " << val << std::endl;
}




