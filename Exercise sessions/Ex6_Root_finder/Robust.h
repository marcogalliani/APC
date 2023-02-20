//
// Created by Marco Galliani on 26/10/22.
//

#ifndef ROOTFINDERALLINONE_ROBUST_H
#define ROOTFINDERALLINONE_ROBUST_H

#include "RootFinder.h"

class Robust : public RootFinder {
protected:
    int cfratio;
    int inf_limit;
    int sup_limit;
public:
    Robust(const Function &f, real tolerance, int maxit, checkT terminationCriterion, int cfratio, int inf, int sup);

    real find_root(int &nit_bis, int &nit_newt);
};


#endif //ROOTFINDERALLINONE_ROBUST_H
