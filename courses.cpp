#include "courses.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

void courses::addCourses() {
    // cin.ignore();
    cout << "Set the Course-No.: ";
    cin >> s[0];
    cin.ignore();
    cout << "Set the Course-Title: ";
    getline(cin, s[1]);
    cout << "Set the Course-Fee: ";
    cin >> s[2];
    fstream course("courses.txt", ios::app);
    fstream tempCourse("temp.txt", ios::app);
    course.seekg(0, ios::end);
    if ((course.tellg() == 0)) {
        course << s[0] << ',' << s[1] << ',' << s[2];
        tempCourse << s[0] << ',' << s[1] << ',' << s[2];
        return;
    }
    course << ',' << s[0] << ',' << s[1] << ',' << s[2];
    tempCourse << ',' << s[0] << ',' << s[1] << ',' << s[2];
    course.close();
    tempCourse.close();
}

void courses::deleteCourses() {
    string delCourse;
    cout << "Enter the Course-No. to delete: ";
    cin >> delCourse;
    // cin >> s[0];
    fstream course("courses.txt", ios::out | ios::in);
    fstream tempCourse("temp.txt", ios::out | ios::in);
    bool frstInfo = true;
    while (!course.eof()) {
        // course>>s[0]>>s[1]>>s[2];
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
}