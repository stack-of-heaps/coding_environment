//Name: Kyle Karthauser
//Date: 4/9/18
//Description: int yomu(string$ string) is an input checker based on https://www.geeksforgeeks.org/converting-strings-numbers-cc/.
//It returns -1 if input is invalid.
//It works by converting a string to an int with stringstream.
//***************************************************************************
#include "yomu.hpp"
#include <sstream>

int yomu(const std::string& input){

    int returnInt;
    std::istringstream i(input);
    if (!(i >> returnInt)) 
        return -1;
    else
        return returnInt;

}
