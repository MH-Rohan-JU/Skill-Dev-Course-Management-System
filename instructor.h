#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "learner.h"
#include <string>
using namespace std;

class instructor : public learner {
  private:
    string instructorName;
    int insPassword;

  public:
    void registration();
    void login();
    void addCourses();
    void showCourses();
    void deleteCourses();
    void seeWhoEnrolled();
};
#endif