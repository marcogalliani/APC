#ifndef BLOCK_H_
#define BLOCK_H_

#include <vector>

#include "dense_matrix.hpp"

class Block
{
private:
  // specify the two extreme angles of the block
  std::size_t top_left_row;
  std::size_t top_left_col;
  std::size_t bottom_right_row;
  std::size_t bottom_right_col;

  DenseMatrix dm;

public:
  // construct a block with values in vals
  Block (std::size_t top_left_r, std::size_t top_left_c,
         std::size_t bottom_right_r, std::size_t bottom_right_c,
         const std::vector<double> & vals);

  std::size_t get_bottom_right_col() const;
  std::size_t get_bottom_right_row() const;

  std::size_t get_top_left_col() const;
  std::size_t get_top_left_row() const;

  // Operator () access (i,j) element of the matrix
  double & operator () (std::size_t i, std::size_t j);

  double operator () (std::size_t i, std::size_t j) const;
};

#endif /* BLOCK_H_ */
