//
// Created by Danilo Ardagna on 02/06/22.
//

#include "Tensor.h"
#include <iostream>
#include <cmath>
#include <limits>

Tensor::Tensor(const index_type& dim) : dimensions(dim) {
    /* Your code goes here*/
    if(dim.size()==0)
        std::cerr << "Fatal error" << std::endl;
}


double Tensor::get(unsigned int i, int j, int k) const {
    /* Your code goes here*/
    if (!check_index(i,j,k)) {
        std::cerr << "Fatal error" << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }
    else {
        index_type index=compute_index(i, j, k);
        if (values.find(index)!=values.end())
            return values.at(index);
        else{

        }
    }
    return std::numeric_limits<double>::quiet_NaN();
}


void Tensor::set(double value, unsigned int i, int j, int k) {
    /* Your code goes here*/
    index_type index = compute_index(i,j,k);
}


Tensor Tensor::operator*(double alpha) const {
    /* Your code goes here*/
    Tensor result(dimensions);

    for (auto cit=values.cbegin(); cit != values.cend(); ++cit ){
        result.values[cit->first] = alpha*cit->second;
    }

    return result;
}




    /* compute tensor norm.
     * norm_type can be "inf", "euclidean", "2" (same as euclidean), "fro"
     * Note that "fro" can be applied only if the tensor is a bi-dimensional matrix
     * */
double Tensor::norm(const std::string& norm_type) const {

        /* Your code goes here*/
}


void Tensor::print() const {

    /* Your code goes here*/


}

double Tensor::infinity_norm() const {
    return 0;
}

double Tensor::euclidean_norm() const {
    return 0;
}

bool Tensor::check_index(unsigned int i, int j, int k) const {

    if (dimensions.size()==0)
        return false;

    if (i >= dimensions[0])
        return false;

    if ((j>=0 and dimensions.size() == 1) or (j >= dimensions[1]))
        return false;

    if ((k>=0 and dimensions.size() <= 2)or (k >= dimensions[2]))
        return false;

    return true;

Tensor::index_type Tensor::compute_index(unsigned int i, int j, int k) const{

    index_type new_index(dimesions.size());

    new_index[0]=i;

    if (j>0)
        new_index[1]=j;

    if (k>0)
        new_index[2]=k;

    return new_index;
}


