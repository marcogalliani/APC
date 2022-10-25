//
//  Matrix.cpp
//  Determinant2
//
//  Created by ing.conti on 07/10/22.
//

#include <vector>
#include "Matrix.h"

// “YOUR CODE HERE” for constructor.


Matrix::Matrix( size_t nRows, size_t nCols) {
    // “YOUR CODE HERE”
    vector<double> zeros(nCols,0);

    for (int i = 0; i < nRows ; ++i) {
        mat.push_back(zeros);
    }
    /*vector<vector<double>> zeros(nRows, (vector<double> (nCols,0)));
    mat=zeros;*/
}

double Matrix::getElem(size_t i, size_t j) const{
    // “YOUR CODE HERE”
    if(i<mat.size() && j<mat[i].size())
        return mat[i][j];
    else
        return INVALID;// default value. Only to allow build.
}

double Matrix::determinant() const{

    // “YOUR CODE HERE”
    if (mat.size()!=mat[0].size())
        return INVALID;
    if (mat.size()==1)
        return mat[0][0];

    double sum=0;
    for (int j = 0; j < mat[0].size(); ++j) {
        sum += mat[0][j]*pow(-1,j)*complementary(0,j).determinant() ;
    }
    return sum;
}

Matrix::Matrix(const vector<vector<double>> & mat_init):mat(mat_init) {}

Matrix Matrix::complementary(int i, int j) const{
    size_t m=0, n=0;
    Matrix comp=Matrix(mat.size()-1,mat[0].size()-1);

    for (int k = 0; k < mat.size(); ++k) {
        if(k!=i){
            for (int l = 0; l < mat[0].size(); ++l) {
                if (l!=j) {
                    comp.mat[m][n]=mat[k][l];
                    n++;
                }
            }
            n=0;
            m++;
        }
    }
    return comp;
}
