//
// Created by Danilo Ardagna on 14/10/2020.
//

#include "BaseKO.h"

int BaseKO::get_x() const{
    return x;

}

void BaseKO::set_x(int val){
   x = val;

}

BaseKO BaseKO::operator=(const BaseKO& rhs) {    // return copy BaseKO
    x = rhs.x;
    return *this;
}