#include "instructor.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

void instructor::instructorMenu() {

    while (true) {
        cout << "\n1. Add a course." << endl;
        cout << "2. Delete a course." << endl;
        cout << "3. See all courses." << endl;
        cout << "4. See who enrolled." << endl;
        cout << "5. Log out." << endl;
        cout << "Select an option: ";
        int option;
        cin >> option;
        switch (option) {
        case 1:
            instructor::addCourses();
            cout << "\nCourse Added Successfully!" << endl;
            break;
        case 2:
            instructor::deleteCourses();
            cout << "\nThe selected course is Deleted!\n";
            instructor::copyFile();
            break;
        case 3:
            instructor::showCourses();
            break;
        case 4:
            cout << "Under Construction :3" << endl;
            break;
        case 5:
            return;
        }
    }
}

void instructor::registration() {
    std::srand(std::time(0));
    int random_number = 1000 + (std::rand() % (9000));
    cin.ignore();
    cout << "\nEnter your name: ";
    getline(cin, instructorName);
    cout << "\nWe will send you an OTP.\nPlease Provide your E-mail/Phone no: ";
    cin >> contact;
    cout << "\nYour OTP is: " << random_number << endl;
    cout << "Preserve this OTP for login in this session." << endl;
    um[random_number] = instructorName;
    instructorMenu();
}

void instructor::login() {
    cout << "\nEnter your 4-digit OTP: ";
    cin >> insPassword;
    for (auto i : um) {
        if (insPassword == i.first) {
            cout << "\nWelcome " << i.second << endl;
            instructorMenu();
            return;
        }
    }
    cout << "\nIncorrect OTP! or The session expired!" << endl;
    cout << "To log into the new session please register again..\n" << endl;
}
