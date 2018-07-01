#include "menu.hpp"
#include "yomu.hpp"
#include "recursiveFunctions.hpp"

/*************************************************************
 * This menu program first asks for a choice of function to execute.
 * 1 -> Reverse String
 * 2 -> Array Sum
 * 3 -> Triangle Numbers
 * 4 -> Quit
 * Input is restricted to 1-4.
 * menu(5) "calls" the menu; that is, menu(5) will present users with a choice of menu options.
 * main.cpp calls menu(5) in a loop.
 * choosing menu(4) returns -1, which ends the menu loop in main.
 * ***********************************************************/

int menu(int choice) {

    switch (choice) {
        case 5: {
            std::cout << "Welcome to Lab5 Menu" << std::endl;
            std::cout << "1. Reverse String Function" << std::endl;
            std::cout << "2. Array Sum Function" << std::endl;
            std::cout << "3. Triangular Numbers Function" << std::endl;
            std::cout << "4. Quit" << std::endl;
            std::cout << "Which would you like to initiate?" << std::endl;
            int userChoice = intYomu(1, 4);
            menu(userChoice);
            break;
        }

        case 4: {
            return -1;
            break;
        }

        case 1: {
            std::cout << "Please enter a string: " << std::endl;
            std::string userString;
            getline(std::cin, userString);
            stringInReverse(userString);
            break;
        }

        case 2: {
            int* array;
            std::cout << "How many integers in this array?" << std::endl;
            int arrayNums = intYomu(1);
            array = new int[arrayNums];
            for (int i = 0; i < arrayNums; i++) {
                std::cout << "Please enter a value for array position #" << i + 1 << std::endl;
                array[i] = intYomu();
            }
            std::cout << sumOfArray(array, arrayNums) << std::endl;
            delete [] array;
            array = nullptr;
            break; 
        }

        case 3: {
            std::cout << "Let's keep it simple. Just give me one integer." << std::endl;
            int userInput = intYomu(1);
            std::cout << triangleNumber(userInput) << std::endl;
            break;
            }
    }
}
