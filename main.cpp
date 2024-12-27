#include "abstract.h"
#include "instructor.h"
#include "learner.h"
#include "rating.h"
#include <fstream>
#include <iostream>
using namespace std;

void regMenu(learner &l1, learner &l2, instructor &i1) {

    fstream file;
    file.open("Learners.dat", ios::app | ios::in | ios::out | ios::binary);
    file.seekg(0, ios ::end);
    int ts = file.tellg();
    int serial = ts / sizeof(learner);
    ++serial;
    int i, pos;

    cout << "\n------------------------------------";
    cout << "\n*********** REGISTRATION ***********\n";
    cout << "------------------------------------\n";
    cout << "1. Register as an Instructor." << endl;
    cout << "2. Register as a Learner." << endl;
    cout << "3. Return to HOMEPAGE." << endl;
    cout << "4. Exit." << endl;
    int option;
    cout << "Choose an option: ";
    cin >> option;

    switch (option) {
    case 1:
        i1.registration();
        break;
    case 2:
        l1.registration(serial);
        file.write(reinterpret_cast<char *>(&l1), sizeof(l1));
        cout << "\nRegistration is successful.\nYour ID no. is: " << serial
             << ".\nPreserve this ID number for future logins.\n"
             << endl;

        l1.learnersMenu();
        break;
    case 3:
        return;
    case 4:
        cout << "\nBest of Luck! Goodbye..." << endl;
        exit(0);
        break;
    }
    file.close();
}

void logMenu(learner &l1, learner &l2, instructor &i1) {

    fstream file;
    file.open("Learners.dat", ios::app | ios::in | ios::out | ios::binary);
    file.seekg(0, ios ::end);
    int ts = file.tellg();
    int serial = ts / sizeof(learner);
    ++serial;
    int i, pos;

    cout << "\n--------------------------------";
    cout << "\n************ LOG IN ************\n";
    cout << "--------------------------------\n";
    cout << "1. Login as an Instructor." << endl;
    cout << "2. Login as a Learner." << endl;
    cout << "3. Return to HOMEPAGE." << endl;
    cout << "4. Exit." << endl;

    int option;
    cout << "Choose an option: ";
    cin >> option;

    switch (option) {
    case 1:
        i1.login();
        break;
    case 2:
        i = l1.login();
        pos = (i - 1) * sizeof(learner);
        file.seekg(pos);
        file.read(reinterpret_cast<char *>(&l2), sizeof(l2));
        l1 == l2;
        cout << endl;
        break;
    case 3:
        return;
    case 4:
        cout << "\nBest of Luck! Goodbye..." << endl;
        exit(0);
    default:
        cout << "Invalid Option! Please try again..." << endl;
        return;
    }
    file.close();
}

void MainMenu(learner &l1, learner &l2, instructor &i1, abstruct *&abst) {
    cout << "####################################" << endl;
    cout << "#              HOMEPAGE            #" << endl;
    cout << "####################################" << endl;
    cout << "1. Register/Sign up" << endl;
    cout << "2. Login / Sign in" << endl;
    cout << "3. View Courses as a Guest" << endl;
    cout << "4. See who rated us" << endl;
    cout << "5. Exit" << endl;
    int option;
    cout << "Choose an option: ";
    cin >> option;

    switch (option) {
    case 1:
        regMenu(l1, l2, i1);
        break;
    case 2:
        logMenu(l1, l2, i1);
        break;
    case 3:
        i1.showCourses();
        break;
    case 4:
        abst->showRatings();
        break;
    case 5:
        cout << "\nBest of Luck! Goodbye..." << endl;
        exit(0);
        break;
    default:
        cout << "\nInvalid Option! Please try again." << endl;
        break;
    }
}

int main() {
    learner l1, l2;
    instructor i1;
    abstruct *abst = new rating(); // Dynamic Binding
    fstream file;                  // File System

    while (true) {
        MainMenu(l1, l2, i1, abst);
    }

    return 0;
}