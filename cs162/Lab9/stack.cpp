#include "stack.hpp"
#include <iostream>

void palindromer(std::string theString) {

    //Declare empty char stack
    std::stack<char> palindrome;

    //Push string elements one-by-one into LIFO stack object
    for (int i = 0; i < theString.size(); i++)
        palindrome.push(theString[i]);

    //Print the user's string
    std::cout << theString;
   
    //Pop off each letter of the palindrome object
    while (!palindrome.empty()) {
        std::cout << palindrome.top();
        palindrome.pop();
    }
}
