#ifndef COURSES_H
#define COURSES_H
#include <string>
using namespace std;

class courses {
  private:
    string s[3];

  public:
    void addCourses();
    void deleteCourses();
    void showCourses();
    void copyFile();
};

#endif