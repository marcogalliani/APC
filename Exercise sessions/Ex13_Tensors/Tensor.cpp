//
// Created by Danilo Ardagna on 02/06/22.
//

#include "Tensor.h"
#include <iostream>
#include <cmath>
#include <limits>

//constructor
Tensor::Tensor(const index_type& dim) : dimensions(dim) {
    /* Your code goes here*/
    if(dim.size()==0)
        std::cout << "Fatal error" << std::endl;
}


//Getter and setter
void Tensor::set(double value, unsigned int i, int j, int k) {
    /* Your code goes here*/
    if (!check_index(i, j, k)) {
        std::cout << "Index not appropriate" << std::endl;
    }
    else{
        index_type indexes = compute_index(i, j, k);
        values[indexes] = value;
    }
}
double Tensor::get(unsigned i, int j, int k) const{
    /* Your code goes here*/
    if (!check_index(i,j,k)) {
        std::cout << "Fatal error\n";
        return std::numeric_limits<double>::quiet_NaN();
    }
    else {
        index_type index=compute_index(i, j, k);
        if (values.find(index)!=values.end())
            return values.at(index);
        else{
            std::cout << "Index not appropriate\n";
            return std::numeric_limits<double>::quiet_NaN();
        }
    }
}


//overloading *
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
 */
double Tensor::norm(const std::string& norm_type) const {

        /* Your code goes here*/
        if (norm_type == "inf")
            return infinity_norm();
        else if (norm_type == "euclidean" or norm_type == "2" )
            return euclidean_norm();
        else if (norm_type == "fro"){
            if(dimensions.size()==2)
                return euclidean_norm();
            else
                std::cout << "Frobenius norm can be computed only for matrices" << std::endl;
        }
        else{
            std::cout << "Unknown norm" << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
        return std::numeric_limits<double>::quiet_NaN();
}

//print
void Tensor::print() const {
    /* Your code goes here*/
    for (auto cit = values.begin(); cit != values.end();++cit){
        // print index
        for (auto index_coord : cit->first)
            std::cout << index_coord << " ";
        std::cout <<  " : ";
        // print value
        std::cout << cit->second << std::endl;
    }
}

//norm helpers
double Tensor::infinity_norm() const {
    double norm = -1;

    for (auto cit = values.cbegin(); cit != values.cend();++cit)
        if (abs(cit->second) > norm)
            norm = abs(cit->second);

    return norm;
}

double Tensor::euclidean_norm() const {
    double norm = 0;

    for (auto cit = values.cbegin(); cit != values.cend();++cit)
        norm += cit->second * cit->second;

    return sqrt(norm);
}

//utilities for indexes
bool Tensor::check_index(unsigned int i, int j, int k) const {

    if (dimensions.size() == 0) {
        std::cout << "size = 0" << std::endl;
        return false;
    }

    //errors on i
    if (i >= dimensions[0]){
        std::cout << "i" << std::endl;
        return false;
    }

    //errors on j
    if (j >= 0 and dimensions.size() == 1){
        std::cout << "j" << std::endl;
        return false;
    }
    if (j >= dimensions[1]){
        std::cout << "j" << std::endl;
        return false;
    }

    //errors on k
    if (k >= 0 and dimensions.size() <= 2){
        std::cout << "k" << std::endl;
        return false;
    }
    if (k >= dimensions[2]){
        std::cout << "k" << std::endl;
        return false;
    }

    return true;
}

Tensor::index_type Tensor::compute_index(unsigned int i, int j, int k) const{

    index_type new_index(dimensions.size());

    new_index[0]=i;

    if (j>0)
        new_index[1]=j;

    if (k>0)
        new_index[2]=k;

    return new_index;
}


