//PE2 - Hello World

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Hello World!\n" << std::endl;

    // Seconds in December
    int seconds;
    seconds = 31 * 24 * 60 * 60;

    // Area of a circile with radius 6.2
    double area;
    area = 3.1415 * (pow(6.2, 2));

    // How integer division works
    double division;
    division = 11 / 3;

    // Output
    std::cout << "There are " << seconds << " seconds in December" << std::endl;
    std::cout << "The area of a circle with a radius 6.2 is " << std::setprecision(4) << area << std::endl;
    std::cout << "With integer division, the number is always rounded down ie: 11 / 3 gives us " << division << std::endl;
}