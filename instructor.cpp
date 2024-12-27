#include "instructor.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void instructor::seeWhoEnrolled() {
    ifstream enrollFIle("enrolled.txt", ios::app);
    cout << endl;
    cout << "Course-No." << setw(10) << "Learners" << setw(20) << '\n';
    cout << string(20, '-') << endl;
    int id;
    string name;
    while (!enrollFIle.eof()) {
        enrollFIle >> id >> name;
        cout << id << setw(18);
        cout << name << setw(20) << '\n';
    }
    enrollFIle.close();
}

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
            instructor::seeWhoEnrolled();
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
    cout << "Confirm OTP: ";
    cin >> insPassword;
    if (insPassword != random_number) {
        cout << "Incorrect OTP!" << endl;
        return;
    }
    cout << "Preserve this OTP for login in this session." << endl;
    cout << "\nWelcome " << instructorName << " as an Instructor <3" << endl;
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