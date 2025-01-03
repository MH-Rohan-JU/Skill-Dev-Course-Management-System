#include "learner.h"
#include <ctime>
#include <fstream>
#include <ios>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void learner::getID(int serial) { ID = serial; }

void learner::rateUs() {
    double rate;
    cout << "\nRate something out of 5: ";
    cin >> rate;
    rate *= 1.00;
    if (rate < 0 || rate > 5) {
        cout << "I\nnvalid rating!!" << endl;
        return;
    }
    ofstream rateFile("ratings.txt", ios::app);
    rateFile << ' ' << username << ' ' << rate;
    cout << "\nThanks for your rating ;)" << endl;
}

void learner::enroll() {
    ofstream enrollFile("enrolled.txt", ios::app);
    ifstream courseFile("courses.txt", ios::app);
    int courseNo, checkOTP;
    std::srand(std::time(0));
    int random_number = 1000 + (std::rand() % (9000));
    cout << "\nYour OTP: " << random_number;
    cout << "\nConfirm OTP: ";
    cin >> checkOTP;
    if (random_number != checkOTP) {
        cout << "\nIncorrect OTP!" << endl;
        return;
    }
    cout << "\nEnter the Course-No. you want to enroll: ";
    cin >> courseNo;
    string cn = to_string(courseNo);
    string cnf;
    bool found = false;
    while (!courseFile.eof()) {
        getline(courseFile, cnf, ',');
        if (cnf == cn) {
            found = true;
            break;
        }
    }
    if (found) {
        enrollFile << ' ' << courseNo << ' ' << username;
        cout << "\nEnrolled Successfully!" << endl;
    } else {
        cout << "\nCourse not found!!" << endl;
    }
    enrollFile.close();
    courseFile.close();
}

void learner::learnersMenu() {
    while (true) {
        cout << "\n1. See the courses.\n";
        cout << "2. Enroll a course.\n";
        cout << "3. Rate Us.\n";
        cout << "4. Log out.\n";
        cout << "Select an option: ";
        int option;
        cin >> option;

        switch (option) {
        case 1:
            ins.showCourses();
            break;
        case 2:
            enroll();
            break;
        case 3:
            rateUs();
            break;
        case 5:
            return;
        default:
            cout << "\nInvalid Option!" << endl;
            return;
        }
    }
}
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

    getID(serial);
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

void learner::operator==(learner l2) {
    if (!strcmp(username, l2.username)) {
        if (!strcmp(password, l2.password)) {
            cout << "\nLogin Succeeded!" << endl;
            cout << "Welcome " << username << " to our platform :)" << endl;
            learner::learnersMenu();
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