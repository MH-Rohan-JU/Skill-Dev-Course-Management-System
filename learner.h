#ifndef LEARNER_H
#define LEARNER_H

#include "instructor.h"
class learner {
  protected:
    int ID;
    char username[80];
    char password[20];

  public:
    void getID(int serial);
    void registration(int serial);
    int login();
    void operator==(learner);
    void showData() const;
    void learnersMenu();
    instructor ins;
};

#endif