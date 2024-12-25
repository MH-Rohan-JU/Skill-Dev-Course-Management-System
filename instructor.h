#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "learner.h"

class instructor : public learner {
  public:
    void addCourses();
    void showCourses();
    void deleteCourses();
    void seeWhoEnrolled();
};
#endif