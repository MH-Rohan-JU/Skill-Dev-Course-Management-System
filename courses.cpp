#include "courses.h"
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

void courses::addCourses() {

    cout << "Set the Course-Serial No. [1,2,3...]: ";
    cin >> s[0];
    cin.ignore();
    cout << "Set the Course-Title: ";
    getline(cin, s[1]);
    cout << "Set the Course-Fee: ";
    cin >> s[2];
    fstream course("courses.txt", ios::app);
    course.seekg(0, ios::end);
    if ((course.tellg() == 0)) {
        course << s[0] << ',' << s[1] << ',' << s[2] << " BDT";
        return;
    }
    course << ',' << s[0] << ',' << s[1] << ',' << s[2] << " BDT";

    course.close();
}

void courses::copyFile() {
    ofstream course("courses.txt");
    ifstream tempCourse("temp.txt", ios::app);
    bool frstInfo = true;
    while (!tempCourse.eof()) {
        getline(tempCourse, s[0], ',');
        getline(tempCourse, s[1], ',');
        getline(tempCourse, s[2], ',');
        if (frstInfo) {
            course << s[0] << ',' << s[1] << ',' << s[2];
            frstInfo = false;
            continue;
        }
        course << ',' << s[0] << ',' << s[1] << ',' << s[2];
        frstInfo = false;
    }
    course.close();
    tempCourse.close();
}

void courses::deleteCourses() {
    string delCourse;
    cout << "Enter the Course-No. to delete: ";
    cin >> delCourse;

    ifstream course("courses.txt", ios::app);
    ofstream tempCourse("temp.txt");

    bool frstInfo = true;
    while (!course.eof()) {

        getline(course, s[0], ',');
        getline(course, s[1], ',');
        getline(course, s[2], ',');
        if (s[0] == delCourse) {
            continue;
        }
        if (frstInfo) {
            tempCourse << s[0] << ',' << s[1] << ',' << s[2];
            frstInfo = false;
            continue;
        }
        tempCourse << ',' << s[0] << ',' << s[1] << ',' << s[2];
        frstInfo = false;
    }

    course.close();
    tempCourse.close();
}

void courses::showCourses() {

    ifstream courseFile("courses.txt", ios::app);

    cout << endl;
    cout << "Course-No." << setw(21) << "Course-Title" << setw(20)
         << "Course-Fee" << setw(20) << endl;
    cout << string(52, '-') << endl;

    cin.ignore();
    while (!courseFile.eof()) {
        getline(courseFile, s[0], ',');
        cout << s[0] << setw(30);
        getline(courseFile, s[1], ',');
        cout << s[1] << setw(20);
        getline(courseFile, s[2], ',');
        cout << s[2] << setw(10);
        cout << '\n';
    }
    cout << endl;
    courseFile.close();
}