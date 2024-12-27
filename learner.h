#ifndef LEARNER_H
#define LEARNER_H

#include "instructor.h"

class learner {
  protected:
    int ID;
    char username[80];
    char password[20];

  public:
    instructor ins; // Aggregation
    void getID(int serial);
    void registration(int serial);
    int login();
    void operator==(learner); // Operator Overloading
    void showData() const;
    void learnersMenu();
    void enroll();
    void rateUs();
};

#endif