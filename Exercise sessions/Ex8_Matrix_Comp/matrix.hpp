#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstddef>
#include <iostream>

class Matrix
{
protected:
  std::size_t n_rows;
  std::size_t n_cols;

public:
  // construct a matrix object with rows rows and cols cols
  Matrix (std::size_t rows, std::size_t cols);

  // operator access the (i,j) element of the matrix
  // this two methods are specified to be pure virtual methods
  // thus, Matrix becomes an abstract class
  virtual double& operator () (std::size_t i, std::size_t j) = 0;

  virtual double operator () (std::size_t i, std::size_t j) const = 0;

  std::size_t get_n_cols() const;
  std::size_t get_n_rows() const;

  void print() const;

  virtual ~Matrix() = default;
};

#endif /* MATRIX_H_ */
