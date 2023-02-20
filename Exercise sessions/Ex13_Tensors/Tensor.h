//
// Created by Danilo Ardagna on 02/06/22.
//

#ifndef TENSORS_TENSOR_H
#define TENSORS_TENSOR_H

#include <vector>
#include <map>
#include <string>

class Tensor {
public:

    typedef std::vector<int>  index_type;

private:
    //we need to store the dimensions of the tensor
    index_type dimensions;

    std::map<index_type, double> values;

    //norm helpers
    double infinity_norm() const;
    double euclidean_norm() const;

    //utilities for indexes
    bool check_index(unsigned int i, int j, int k) const;
    index_type compute_index(unsigned int i, int j, int k) const;


public:
    explicit Tensor(const index_type &dimensions);

    //getter and setter
    double get(unsigned i, int j=-1, int k=-1) const;
    void set(double value, unsigned int i, int j=-1, int k=-1);

    //overloading *
    Tensor operator*(double alpha) const;

    /* compute tensor norm.
     * norm_type can be "inf", "euclidean", "2" (same as euclidean), "fro"
     * Note that "fro" can be applied only if the tensor is a bi-dimensional matrix
     * */
    double norm(const std::string& norm_type) const;

    //print
    void print() const;
};


#endif //TENSORS_TENSOR_H
