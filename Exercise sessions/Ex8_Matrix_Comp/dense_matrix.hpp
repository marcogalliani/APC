#ifndef DENSE_MATRIX_HPP
#define DENSE_MATRIX_HPP

#include <istream>
#include <vector>

#include "matrix.hpp"

// dense matrix is a subclass of Matrix
class DenseMatrix : public Matrix
{
   private:
   // dense matrix is implemented storing all its values in a vector
   std::vector<double> m_data;

   // from (i,j) returns the index of the vector m_data
   std::size_t sub2ind (std::size_t i, std::size_t j) const;

   public:
   // construct a dense matrix with all zeros
   DenseMatrix (std::size_t rows, std::size_t columns,
         double value = 0.0);

   // construct a dense matrix with values in the vector values
   DenseMatrix (std::size_t rows, std::size_t columns,
         const std::vector<double>& values);


   void read (std::istream &);

   // swap a dense matrix with another one
   void swap (DenseMatrix &);

   // 0verride virtual methods of Matrix
   // implement operator () to access elem (i,j) of the dense matrix
   double & operator () (std::size_t i, std::size_t j) override;

   double operator () (std::size_t i, std::size_t j) const override;

   // compute transposed matrix
   DenseMatrix transposed (void) const;

   // returns a ptr to the data in the vector
   double * data (void);

   const double * data (void) const;
};

DenseMatrix operator * (const DenseMatrix &, const DenseMatrix &);

void swap (DenseMatrix &, DenseMatrix &);

#endif // DENSE_MATRIX_HH
