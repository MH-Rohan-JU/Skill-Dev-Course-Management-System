#include "instructor.h"
#include <iostream>
#include <string>
using namespace std;

void instructor::registration() {
    int random_number = 1000 + (std::rand() % (9000));
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, instructorName);
    cout << "\nWe will send you an OTP.\nPlease Provide your E-mail/Phone no: ";
    cin >> contact;
    cout << "Your OTP is: " << random_number << endl;
    cout << "\nPreserve this OTP for login in this session." << endl;
    um[random_number] = instructorName;
}

void instructor::login() {
    cout << "\nEnter your 4-digit OTP: ";
    cin >> insPassword;
    for (auto i : um) {
        if (insPassword == i.first) {
            cout << "\nWelcome " << i.second << endl;
            return;
        }
    }
    cout << "\nIncorrect OTP! or The session expired!" << endl;
    cout << "To log into the new session please register again..\n" << endl;
}