#include "rating.h"
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

void rating::showRatings() {

    ifstream rateFile("ratings.txt", ios::app);

    cout << endl;
    cout << "Ratings" << setw(18);
    cout << "Username" << setw(18);
    cout << endl;
    cout << string(26, '.') << endl;

    setiosflags(ios::right);
    while (!rateFile.eof()) {
        rateFile >> name >> rate;
        cout << rate << setw(20);
        cout << name << setw(20);
        cout << '\n';
    }
    cout << endl;

    rateFile.close();
}