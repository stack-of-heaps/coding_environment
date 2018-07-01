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
    int sum = 0; // Used to store and then write data to Sum.txt

    cout << "Please enter your filename.\n";
    getline(cin, fileName);

    inputFile.open(fileName);

    if (inputFile)
        {
        while (inputFile >> fileData) // Reading data
        {
        sum += fileData;
        };

        inputFile.close();

        outputFile.open("sum.txt");
        outputFile << sum; // Write data
        outputFile.close();
        cout << "result written to sum.txt" << endl;
        }
        else
        cout << "could not access file" << endl;  
    return 0;
    }