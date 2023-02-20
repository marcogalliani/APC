#ifndef BLOCKMATRIX_H_
#define BLOCKMATRIX_H_

#include <vector>

#include "block.hpp"

// Block matrix is a subclass of Matrix
class BlockMatrix: public Matrix{
private:
    // vector of blocks in the matrix
    std::vector<Block> blocks;

    // check if (i,j) is in the matrix
    bool indexes_in_range (std::size_t i, std::size_t j) const;

    // check if (i,j) is in the block
    bool indexes_in_block (std::size_t i, std::size_t j, const Block & block) const;

public:
    // construct a block matrix with 0 cols 0 rows
    BlockMatrix();


    void add_block (const Block & block);

    // 0verride virtual methods of Matrix
    // access (i,j) element of the matrix
    virtual double&  operator () (std::size_t i, std::size_t j) override;

    // access (i,j) element of the matrix
    virtual double  operator () (std::size_t i, std::size_t j) const override;
};

#endif /* BLOCKMATRIX_H_ */
