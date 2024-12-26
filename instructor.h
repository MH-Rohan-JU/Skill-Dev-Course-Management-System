#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "courses.h"
#include <string>
#include <unordered_map>
using namespace std;

class instructor : public courses {
  private:
    string instructorName;
    string contact;
    int insPassword;

  public:
    unordered_map<int, string> um;
    void registration();
    void login();
    void addToFile();
    void seeWhoEnrolled();
    void instructorMenu();
    // void addCourses();
    // void showCourses();
    // void deleteCourses();
};

#endif