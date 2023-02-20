#include <iostream>

class Path {
protected:
    const unsigned length;
    unsigned avgRating = 5;
    unsigned numOfReviews = 0;
public:

    explicit Path(unsigned l);

    Path(Path& p);

    virtual unsigned getPoints() const;

    void rate(unsigned rating);

    virtual ~Path() {};
};