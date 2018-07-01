/********************************************************
* Author: Kyle Karthauser                               *
* Date: 1/20/18                                         *
* Description: This program opens a file, reads the     *
* contents (in this case, integers), computes           *
* the sum of the integers, and writes the sum           *
* to a file called "sum.txt." The program then          *  
* outputs "result written to sum.txt."                  *
* If the program can't find the file specified,         *
* it will print out "could not access file."            *
********************************************************/

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
    {
    
    int fileData; // Variable to hold data read from file
    string fileName;
    
    ifstream inputFile;
    ofstream outputFile;

    cout << "Please enter a filename.\n";
    getline(cin, fileName);

    inputFile.open(fileName);

    while (inputFile >> fileData)
        {
        cout << fileData;
        };

    return 0;
    }