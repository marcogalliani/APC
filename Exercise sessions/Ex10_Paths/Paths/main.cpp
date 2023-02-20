#include "HikingPath.hh"
#include <iostream>

unsigned runAndRate(Path& p, unsigned r);

int main() {
  unsigned ted = 0;
  unsigned david = 0;

  Path woodsPath(5);
  HikingPath glacierWay(15, 800);

  david += runAndRate(woodsPath, 8);
  ted += runAndRate(woodsPath, 4);
  ted += runAndRate(glacierWay, 12);

  Path flatWay(glacierWay);
  flatWay.rate(8);
  david += flatWay.getPoints();

  std::cout << "David: " << david << std::endl;
  std::cout << "Ted: " << ted << std::endl;

}

unsigned runAndRate(Path& p, unsigned r) {
  unsigned pts = p.getPoints();
  p.rate(r);
  return pts;
}