// PE - Stringstream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int currentMonth = 3;
    int currentDay = 27;
    int daysInEachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char info[90] = "Duy Vu 7 / 15";

    stringstream ss(info);
    string firstName;
    string lastName;
    int birthMonth;
    int birthDay;
    char slash;

    ss >> firstName >> lastName >> birthMonth >> slash >> birthDay;

    int daysTillBday = 0;
    bool cont = true;
    while (cont == true) {
        if (currentMonth == birthMonth && currentDay == birthDay) {
            cont = false;
        }
        daysTillBday += 1;
        currentDay += 1;
        if (currentDay > daysInEachMonth[currentMonth - 1]) {
            currentDay = 1;
            currentMonth += 1;
        }
        if (currentMonth == 13) {
            currentMonth = 1;
        }
    }

    cout << firstName << ", your birthday is in " << daysTillBday << " day(s)" << endl;
    
}

