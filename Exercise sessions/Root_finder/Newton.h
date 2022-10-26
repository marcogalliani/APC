//
// Created by Marco Galliani on 26/10/22.
//

#ifndef ROOTFINDERALLINONE_NEWTON_H
#define ROOTFINDERALLINONE_NEWTON_H

#include "RootFinder.h"

typedef double real;

class Newton : public RootFinder{
protected:
    real x_init;

public:
    Newton(const Function &f, real tolerance, int maxit, checkT terminationCriterion, real x0);
    real find_root(int &nit);



};


#endif //ROOTFINDERALLINONE_NEWTON_H
