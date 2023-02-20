#include "Centroid.h"

void
Centroid::update_coords (std::vector<Point*> const & ps)
{
    /* Your code goes here */
    //initialize a vector of x.size() elements to 0
    std::vector<double> new_coordinates(x.size(),0);

    for (int i = 0; i < ps.size(); ++i) {
        for (int j = 0; j < new_coordinates.size(); ++j) {

            //x is protected, we cannot access x of an object Point from an object Centroid
            //we can access the vector x of the object Centroid
            new_coordinates[i]+=ps[i]->get_coord(j);
        }
    }

    for (int j = 0; j < x.size(); ++j) {
        new_coordinates[j]/=ps.size();
    }

    //x = new_coordinates;
    swap(x,new_coordinates); //much more efficient than commented assignement

}
