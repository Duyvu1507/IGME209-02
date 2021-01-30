// helloworld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n" << std::endl;

    int seconds;
    seconds = 31 * 24 * 60 * 60;

    double area;
    area = 3.1415 * (pow(6.2, 2));

    double division;
    division = 11 / 3;

    std::cout << "There are " << seconds << " seconds in December" << std::endl;
    std::cout << "The area of a circle with a radius 6.2 is " << area << std::endl;
    std::cout << "With integer division, the number is always rounded down ie: 11 / 3 gives us " << division << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
