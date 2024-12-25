#include "learner.h"
#include <iostream>
#include <string.h>
using namespace std;

void learner::getID(int serial) { ID = serial; }
void learner::registration(int serial) {
    cout << "\n[N.B. Username must be a single word. You may use your "
            "nickname.\n";
    cout
        << "Else, use hypen(-) of underscore(_) instead of space if you have a "
           "bigger name]\n"
        << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    learner::getID(serial);
}

int learner::login() {
    int id;
    cout << "\nEnter your ID no: ";
    cin >> id;
    getID(id);
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    return id;
}

void learner::operator==(learner l2) const {
    if (!strcmp(username, l2.username)) {
        if (!strcmp(password, l2.password)) {
            cout << "\nLogin Succeeded!" << endl;
            cout<<"Welcome "<<username<<" to our platform :)"<<endl;
        } else {
            cout << "\nIncorrect Password!" << endl;
        }
    } else {
        cout << "\nInvalid Username!";
    }
    return;
}

void learner::showData() const {
    cout << "ID: " << ID << endl;
    cout << "Name: " << username << endl;
    cout << "Pass: " << password << endl;
}