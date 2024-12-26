#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
#include <unordered_map>
using namespace std;

class instructor {
  private:
    string instructorName;
    string contact;
    int insPassword;

  public:
    unordered_map<int, string> um;
    void registration();
    void login();
    void addToFile();
    // void addCourses();
    // void showCourses();
    // void deleteCourses();
    // void seeWhoEnrolled();
};

#endif