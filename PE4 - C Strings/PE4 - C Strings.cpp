// PE4 - C Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // Define first C string and print the length
    char word[100] = "supercalifraglistic"; 
    std::cout << strlen(word) << std::endl;

    // Define second C string and append it to first and prints the result
    char word2[100] = "expialidocious";
    strcat_s(word, word2);
    std::cout << word << std::endl;

    // Finds how many times the letter i appears in the combined string
    int count = 0;
    for (char i : word) {
        if (i == 'i') {
            count++;
        }
    }
    std::cout << "The letter i appears " << count << " times in the combined string" << std::endl;

    
}

