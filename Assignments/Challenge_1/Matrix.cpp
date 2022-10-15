//
//  Matrix.cpp
//  Determinant2
//
//  Created by ing.conti on 07/10/22.
//

#include <vector>
#include <iostream>

#include "Matrix.h"

// “YOUR CODE HERE” for constructor.


Matrix::Matrix( int nRows, int nCols){
    // “YOUR CODE HERE”
    vector<double> vect;

    for (int j = 0; j < nCols; ++j) {
        vect.push_back(0);
    }
    for (int i = 0; i < nRows ; ++i) {
        mat.push_back(vect);
    }
}


double Matrix::getElem(size_t i, size_t j) const{
    // “YOUR CODE HERE”
    if(i<mat.size()&& i >=0 && j<mat[i].size() && j>=0)
        return mat[i][j];
    else
        return INVALID; // default value. Only to allow build.

}

double Matrix::determinant() const{

    // “YOUR CODE HERE”
    if (mat.size()!=mat[0].size())
        return INVALID;
    if (mat.size()==1 && mat[0].size()==1)
        return mat[0][0];

    double sum=0;
    for (int j = 0; j < mat[0].size(); ++j) {
        sum += mat[0][j]*pow(-1,j)*complementary(0,j).determinant() ;
    }

    return sum;

}

Matrix::Matrix( std::vector<std::vector<double>> mat_init ):mat(mat_init) {}

void Matrix::print() {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}


void Matrix::setElem(size_t i, size_t j, double v) {
    mat[i][j]=v;
}

Matrix Matrix::complementary(int i, int j) const{

    Matrix comp=Matrix(mat.size()-1,mat[0].size()-1);
    for (int k = 0; k < mat.size(); ++k) {
        for (int l = 0; l < mat[0].size(); ++l) {
            if(k<i && l<j)
                comp.setElem(k,l,mat[k][l]);
            if(k>i && l<j)
                comp.setElem(k-1,l,mat[k][l]);
            if(k<i && l>j)
                comp.setElem(k,l-1,mat[k][l]);
            if(k>i && l>j)
                comp.setElem(k-1,l-1,mat[k][l]);
        }
    }
    return comp;
}

