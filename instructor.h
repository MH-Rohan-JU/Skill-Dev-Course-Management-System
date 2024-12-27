#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "courses.h"
#include <string>
#include <unordered_map>
using namespace std;

// Inheritance
class instructor : public courses {
  private:
    string instructorName;
    string contact;
    int insPassword;

  public:
    unordered_map<int, string> um; // Standard Template Library (STL)
    void registration();
    void login();
    void addToFile();
    void seeWhoEnrolled();
    void instructorMenu();
};

#endif