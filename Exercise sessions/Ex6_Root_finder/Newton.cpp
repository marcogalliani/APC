//
// Created by Marco Galliani on 26/10/22.
//

#include "Newton.h"



Newton::Newton(const Function &f, real tolerance, int maxit, checkT terminationCriterion, real x0) : RootFinder(f, tolerance, maxit, terminationCriterion), x_init(x0){}

real Newton::find_root(int &nit) {
    real v = f.eval(x_init);
    real xnew;

    nit = 0;
    bool conv = false;

    for (int k = 1; k <= maxit && !conv; ++k, ++nit) {
        const Function df=f.derivative();
        double derv = df.eval(x_init);
        if (!derv) {
            std::cerr << "ERROR: Division by 0 occurred in Newton algorithm"
                      << std::endl;
            exit(1);
        }

        xnew = x_init - v / derv;
        v = f.eval(xnew);
        conv = converged(fabs(xnew - x_init), fabs(v), tolerance);
        if (!conv)
            x_init = xnew;
    }
    return xnew;
}
