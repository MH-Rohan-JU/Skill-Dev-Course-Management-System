#include "learner.h"
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void MainMenu(learner &l1, learner &l2) {
    fstream file;
    file.open("Learners.dat", ios::app | ios::in | ios::out | ios::binary);
    file.seekg(0, ios ::end);
    int ts = file.tellg();
    int serial = ts / sizeof(learner);
    ++serial;
    int i, pos;

    cout << "####################################" << endl;
    cout << "#              HOMEPAGE            #" << endl;
    cout << "####################################" << endl;
    cout << "1. Register/Sign up" << endl;
    cout << "2. Login / Sign in" << endl;
    cout << "3. View Courses as a Guest" << endl;
    cout << "4. Exit" << endl;
    int option;
    cout << "Choose an option: ";
    cin >> option;
    switch (option) {
    case 1:
        l1.registration(serial);
        file.write(reinterpret_cast<char *>(&l1), sizeof(l1));
        cout << "\nRegistration is successful.\nYour ID no. is: " << serial
             << ".\nPreserve this ID number for future logins.\n"
             << endl;
        break;
    case 2:
        i = l1.login();
        pos = (i - 1) * sizeof(learner);
        file.seekg(pos);
        file.read(reinterpret_cast<char *>(&l2), sizeof(l2));
        l1 == l2;
        // l2.showdata();
        cout << endl;
        // l1.showdata();
        break;
    case 3:
        cout << "\nUnavailable now!" << endl;
        break;
    case 4:
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
    fstream file;
    file.open("Learners.dat", ios::app | ios::in | ios::out | ios::binary);
    while (true) {
        MainMenu(l1, l2);
    }
    return 0;
}