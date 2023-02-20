//
// Created by Marco Galliani on 30/12/22.
//

#ifndef PATHS_HIKINGPATH_HH
#define PATHS_HIKINGPATH_HH

#include "Path.h"

class HikingPath : public Path {
protected:
    const unsigned height;
public:
    HikingPath(unsigned l, unsigned h);

    unsigned getPoints() const override;
};


#endif //PATHS_HIKINGPATH_HH
