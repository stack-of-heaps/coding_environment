/********************************************************
* Author: Kyle Karthauser                               *
* Date: 1/20/18                                         *
* Description: This program asks the user to input a    *
* number. Another user is then asked to try to guess    *
* that number. If the guess is too high, that feedback  *
* is given. If too low, that feedback is given. Upon    *
* entering the correct number, the program outputs      *
* how many tries it took to guess the number.           *
********************************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int secretNumber; // User-determined "secret" number
int userGuess; // Holds guesses made by user
int tryCounter = 0; // Counts number of guesses made

int main()
    {

    cout << "Enter the number for the player to guess." << endl;
    cin >> secretNumber;
    cout << "Enter your guess." << endl;
    cin >> userGuess;
    tryCounter++;
    do
        {
        if (userGuess > secretNumber)
            {
            cout << "Too high - try again." << endl;
            cin >> userGuess;
            tryCounter++;
            }
        else if (userGuess < secretNumber)
            {
            cout << "Too low - try again." << endl;
            cin >> userGuess;
            tryCounter++;
            }
        }
        while (userGuess != secretNumber);

    cout << "You guessed it in " << tryCounter << " tries." << endl;

    return 0;
    }   