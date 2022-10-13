//
// Created by Danilo Ardagna on 14/10/2020.
//

#include "BaseOK.h"


int BaseOK::get_x() const{
    return x;

}

void BaseOK::set_x(int val){
    x = val;

}

BaseOK& BaseOK::operator=(const BaseOK& rhs) {    // BaseOK&
    x = rhs.x;
    return *this;
}