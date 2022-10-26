//
// Created by Marco Galliani on 26/10/22.
//

#ifndef ROOTFINDERALLINONE_BISECTION_H
#define ROOTFINDERALLINONE_BISECTION_H

#include "RootFinder.h"

class Bisection : public RootFinder{

protected:
    real inf_limit;
    real sup_limit;

public:
    Bisection(const Function &f, real tolerance, int maxit, checkT terminationCriterion, real infLimit, real supLimit);
    real find_root(int &nit);

};


#endif //ROOTFINDERALLINONE_BISECTION_H
