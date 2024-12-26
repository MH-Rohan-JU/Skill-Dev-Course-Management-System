#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class user {
  protected:
    int ID;
    int insPassword;
    char username[80];
    char password[20];
    string instructorName;
    string contact;
};

#endif