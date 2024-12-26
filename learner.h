#ifndef LEARNER_H
#define LEARNER_H

class learner {
  protected:
    int ID;
    char username[80];
    char password[20];

  public:
    void getID(int serial);
    void registration(int serial);
    int login();
    void operator==(learner) const;
    void showData() const;
    void learnersMenu() const;
};

#endif