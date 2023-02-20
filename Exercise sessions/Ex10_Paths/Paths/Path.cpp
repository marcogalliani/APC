#include "Path.h"

Path::Path(unsigned int l) : length(l) {}

Path::Path(Path& p) : length(p.length) {
  avgRating = p.avgRating;
}

unsigned Path::getPoints() const{
  /* your code goes here */
  return (avgRating + 2) * length;
}

void Path::rate(unsigned int rating) {
  /* your code goes here */
  unsigned rating_sum = numOfReviews*avgRating;
  //update number of reviews
  numOfReviews++;
  //update points of the path
  rating_sum += rating;
  //update avgRating
  avgRating = rating_sum/numOfReviews;
}