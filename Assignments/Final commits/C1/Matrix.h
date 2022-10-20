//
//  Matrix.h
//  Determinant2
//
//  Created by ing.conti on 07/10/22.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cmath>

#include <limits>

constexpr double INVALID{ std::numeric_limits<double>::quiet_NaN() };

using std::vector;

// DO NOT ALTER Class name.
class Matrix{

private:
    // “YOUR CODE HERE” if needed
    vector<vector<double>> mat;

public:
    Matrix( size_t nRows, size_t nCols); // zeros matrix, only to allow run
    double getElem(size_t i, size_t j) const;
    double determinant() const;

    // “YOUR CODE HERE”
    // write here the constructor that allow to call:
    // Matrix m1 = Matrix( {{1, 2}, {3,4}}  );
    Matrix( const vector<vector<double>>  & mat_init );
    Matrix complementary(int i, int j) const;

};


#endif //MATRIX_H
