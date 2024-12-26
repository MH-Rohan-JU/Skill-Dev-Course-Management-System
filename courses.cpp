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
    // cin >> s[0];
    ifstream course("courses.txt", ios::app);
    ofstream tempCourse("temp.txt");
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
    // course.seekg(0);
    // tempCourse.seekg(0);
    // frstInfo = true;
    // while (!tempCourse.eof()) {
    //     getline(tempCourse, s[0], ',');
    //     getline(tempCourse, s[1], ',');
    //     getline(tempCourse, s[2], ',');
    //     if (frstInfo) {
    //         course << s[0] << ',' << s[1] << ',' << s[2];
    //         frstInfo = false;
    //         continue;
    //     }
    //     course << ',' << s[0] << ',' << s[1] << ',' << s[2];
    //     frstInfo = false;
    // }
    course.close();
    tempCourse.close();
}