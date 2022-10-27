#include <iostream>

#include "Function.h"
#include "FunctionMin.h"

int main() {

    const double step = 0.01;
    const double tolerance = 0.00001;

    std::vector<Monomials> terms;
    terms.push_back (Monomials (2, {2, 0}));
    terms.push_back (Monomials (2, {1, 1}));
    terms.push_back (Monomials (2, {0, 2}));
    terms.push_back (Monomials (-2, {0, 1}));
    terms.push_back (Monomials (6, {0, 0}));

    Function f;
    for (const Monomials & m: terms)
        f.addMonomial (m);

    const Point P1 ({0, 0});
    const Point P2 ({2, 2});

    std::cout << "Initial Points values" << std::endl;
    std::cout << f.eval (P1) << " " << f.eval (P2) << std::endl;

    const unsigned int max_iterations = 2000;
    FunctionMin  minRn=FunctionMin(f, {-5, -4}, {7, 9},tolerance, step, max_iterations);

    const Point P = minRn.solve ();
    std::cout << "Final solution standard grad: "
              << f.eval (P) << std::endl;
    P.print ();

    /*
  const Point Q = minRn.solve_multistart (1000);
  std::cout << "Final solution multi-start:"
            << f.eval (Q) << std::endl;
  Q.print ();

  const unsigned int n_domain_steps = 100;
  const Point R = minRn.solve_domain_decomposition (n_domain_steps, 100);
  std::cout << "Final solution domain decomposition:"
            << f.eval (R) << std::endl;
  R.print ();
*/

    return 0;
}
