//
// Created by Marco Galliani on 30/12/22.
//

#include "HikingPath.hh"

HikingPath::HikingPath(unsigned l, unsigned h): Path(l), height(h){}

unsigned HikingPath::getPoints() const {
    return 10*length+height/100;
}

