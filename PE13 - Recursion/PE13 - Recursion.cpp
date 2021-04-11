// PE13 - Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n = 5; // Num of seats
int nHands = 4;
int oHands = 3;
int numOfHands = 0;

int iteration(int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            numOfHands += nHands;
        }
        else {
            numOfHands += oHands;
        }
    }
    return numOfHands-1;
}

int recursive(int n) {
    if (n <= 0) {
        return numOfHands;
    }
    else {
        if (n % 2 == 0) {
            numOfHands += nHands;
        }
        else {
            numOfHands += oHands;
        }
        return recursive(n - 1);
    }
}

int main()
{
    // Iteration
    cout << "Iteration: " << iteration(5) << endl;

    numOfHands = 0;

    // Recursion
    cout << "Recursive: " << recursive(5) << endl;
}