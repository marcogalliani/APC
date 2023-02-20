//
// Created by Marco Galliani on 26/10/22.
//

#include "Robust.h"
#include "Bisection.h"
#include "Newton.h"

real Robust::find_root(int &nit_bis, int &nit_newt) {
    // Call bisection method (with a greater desired tolerance)
    real tol_bis = cfratio * tolerance;
    real x_bis = Bisection(f,tol_bis,maxit,termination_criterion,inf_limit,sup_limit).find_root(nit_bis);

    /*
      Call a Newton algorithm which uses as an initial value
      the solution given by bisection method
    */
    return Newton(f,tol_bis,maxit,termination_criterion,x_bis).find_root(nit_newt);

}

Robust::Robust(const Function &f, real tolerance, int maxit, checkT terminationCriterion, int cfratio, int inf, int sup) : RootFinder(f,
                                                                                                                    tolerance,
                                                                                                                    maxit,
                                                                                                                    terminationCriterion),
                                                                                                         cfratio(cfratio),
                                                                                                         inf_limit(inf),
                                                                                                         sup_limit(sup)
                                                                                                         {}
