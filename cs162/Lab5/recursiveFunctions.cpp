#include "recursiveFunctions.hpp"

#include <iostream>

//Takes a string as input and prints each character in reverse until the beginning
//of the string is reached
void stringInReverse(std::string userString) {

    if (userString.size() == 1)
       std::cout << userString << std::endl;
    else {
        int stringLength = userString.size();

        std::cout << userString[stringLength-1];
        userString.pop_back();
        stringInReverse(userString);
    } 
}

//takes a pointer to an array as input as well as the number of elements in that array.
//returns the value of the last value in the array and then calls the function again.
//function ends and returns final sum when number of elements in the array = 0
int sumOfArray(int* array, int arrayNums){

    if (arrayNums == 0)
        return array[0];
    else {
        return array[arrayNums] + sumOfArray(array, arrayNums-1);
    }
}

//simply returns the number passed to the function + the next smallest non-zero integer.
//ends when n == 1
int triangleNumber(int n) {

    if (n == 1)
        return n;
    else 
        return n + triangleNumber(n - 1);

}
