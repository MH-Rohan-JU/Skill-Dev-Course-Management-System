#ifndef ABSTRUCT_H
#define ABSTRUCT_H
#include <string>

class abstruct {
  public:
    double rate;
    std::string name;
    abstruct() : rate(0) {} // Default Constructor
    virtual void showRatings() = 0;
};

#endif