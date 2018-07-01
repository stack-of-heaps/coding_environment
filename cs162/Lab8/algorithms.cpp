#include "algorithms.hpp"
#include <iostream>
#include <fstream>

//Simple Search
//Starts at the first value of the vector and proceeds through to the last.
//If value is found, returns true.
//if not found, returns false.
bool algoSearch(int val, vec &thisVec) {

    std::cout << "Searching..." << std::endl;

    for (int i = 0; i < thisVec.size(); i++) {
        if (thisVec[i] == val)
            return true;
    }
    return false;
}

//Sort
//We will be using BUBBLESORT.
//Algorithm code from https://www.geeksforgeeks.org/bubble-sort/
bool algoSort(vec &thisVec) {


    int tempVal;
/*
 * This was my own crude attempt at the algorithm, for what it's worth--
 * obviously not an ideal solution as every time we swap, I start the whole
 * process over!
    bool wasSwapped = true;

    while (wasSwapped) {
        for (int i = 0; i < thisVec.size() - 1; i++) 
            if (thisVec[i] > thisVec[i+1])  {
                tempVal = thisVec[i];
                thisVec[i] = thisVec[i + 1];
                thisVec[i + 1] = tempVal;
                i = -1;
            }
            else
                wasSwapped = false;
    }
*/

    for (int i = 0; i < thisVec.size(); i++)
        for (int j = 0; j < thisVec.size() - i - 1; j++)
            if (thisVec[j] > thisVec[j+1]) {
                int tempVal = thisVec[j];
                thisVec[j] = thisVec[j+1];
                thisVec[j+1] = tempVal;
            }

    //Print the vector to show you it's done.
    for (int i = 0; i < thisVec.size(); i++)
        std::cout << thisVec[i] << ", ";

    std::cout << std::endl;

    std::cout << "Sorted list will be saved to a file. Please enter a filename." << std::endl;
    std::string userFile;
    getline(std::cin, userFile);
    std::ofstream newFile(userFile);
    
    for (int i = 0; i < thisVec.size(); i++)
        newFile << thisVec[i];

    newFile.close();

    std::cout << std::endl;
}

//Binary Search
//Code source: algolist.net/Algorithms/Binary_search

bool algoBinarySearch(int val, vec vec, int from, int to) {


    while (from <= to){

        int middleVal = (from + to) / 2;
        if (vec[middleVal] == val)
            return true;
        else if (vec[middleVal] > val)
            to = middleVal - 1;
        else if (vec[middleVal] < val)
            from = middleVal + 1;
    }
    return false;

}
