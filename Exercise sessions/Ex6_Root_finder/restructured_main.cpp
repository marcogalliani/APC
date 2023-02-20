//
// Created by Marco Galliani on 26/10/22.
//

#include "Function.h"
#include "RootFinder.h"
#include "Bisection.h"
#include "Newton.h"
#include "Robust.h"


int main() {

    int nit_bis;
    int nit_newt;
    std::cout << std::endl;
    std::cout << "Bisection" << std::endl;
    std::cout << Bisection(Function({-0.5,0.0,1.0}), 1e-8, 100, INCREMENT,0.,1.).find_root(nit_bis);
    std::cout << '\t' << nit_bis << std::endl;


    std::cout << "Newton" << std::endl;
    std::cout << Newton( Function({-0.5,0.0,1.0}), 1e-8, 100, INCREMENT,.1).find_root(nit_newt);
    std::cout << '\t' << nit_newt << std::endl;

    std::cout << "Robust" << std::endl;
    std::cout << Robust(Function({-0.5,0.0,1.0}),1e-8,100,INCREMENT,1e4,0.,1.).find_root(nit_bis,nit_newt);
    std::cout << '\t' << nit_bis << " " << nit_newt << std::endl;

    return 0;
}