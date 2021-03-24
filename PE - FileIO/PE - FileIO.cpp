// PE - FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
    ofstream ofs("text.txt", ofstream::out);
    ofs << "Hello World";
    ofs.close();

    ifstream inFile("text.txt", ifstream::binary);
    inFile.seekg(0, ios::end);
    int length = (int)inFile.tellg();

    inFile.seekg(0, ios::beg);

    char* fileContents = new char[length + 1];
    inFile.read(fileContents, length);
    fileContents[length] = 0;

    if (inFile.is_open()) {
        cout << fileContents << endl;
    }

    inFile.close();
}

