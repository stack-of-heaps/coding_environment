/* Description: This is my input validation file. 
 * My ideal input validator is one that takes care of the while looping,
 * the checking, and the formatting all on its own. This current iteration
 * tries to do that. I am creating different functions for each return type.
 * I'm also trying to allow for some quick, custom-tailoring of how
 * the function behaves with just a few parameters. I can specify a range,
 * two specific values, and so on. 
 * 
 * Split into:
 * --int
 *   double
 *
 * --no constraints (intYomu/doubleYomu)
 *   minimum value (intYomu(int) / doubleYomu(double)
 *   range (intYomu(int, int) / doubleYomu(double, double)
 *   strict: only x vlaue or y value (intYomu(int x, int y) / doubleYomu(double x, double y)
 *
 * For decimal checking:
 *      --std::string::npos returns 0, there are no matches for find()
        --Technique taken from http://www.cplusplus.com/forum/beginner/14117/ 
       e
 */

#include "yomu.hpp"

//return int, no params
int intYomu(){

    bool validInput = false;
    std::string userInput;
    int returnInt;

    while (!validInput) {
        getline(std::cin, userInput);
 
        std::istringstream i(userInput);
        if (!(i >> returnInt)) 
            std::cout << "Invalid input." << std::endl;
    
        //check for a decimal
        else if (userInput.find('.') != std::string::npos)
            std::cout << "Invalid input. Please enter an integer." << std::endl;

        else { 
            validInput = true;
            return returnInt;
        }
    }
}

//int min 
int intYomu(int min){

    bool validInput = false;
    std::string userInput;
    int returnInt;

    while (!validInput) {
        getline(std::cin, userInput);
 
        std::istringstream i(userInput);
        if (!(i >> returnInt)) 
            std::cout << "Invalid input." << std::endl;

        else if (returnInt < min) 
            std::cout << "Invalid input. Must be at least " << min << std::endl;
        
        //check for decimal input
        else if (userInput.find('.') != std::string::npos)
            std::cout << "Invalid input. Please enter an integer." << std::endl;

        else { 
            validInput = true;
            return returnInt;
        }
    }
}

//int range
int intYomu(int low, int high){

    bool validInput = false;
    std::string userInput;
    int returnInt;

    while (!validInput) {
        getline(std::cin, userInput);
        
        std::istringstream i(userInput);
        if (!(i >> returnInt)) 
            std::cout << "Invalid input." << std::endl;

        else if ((returnInt < low) || (returnInt > high)) {
            std::cout << "Invalid input. Enter a number between " << low;
            std::cout << " and " << high << std::endl;
        }
        
        //check for decimal input
        //if "std::string::npos returns 0, there are no matches for find()
        else if (userInput.find('.') != std::string::npos)
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        
        else { 
            validInput = true;
            return returnInt;
        }
    }
}

//int strict
int intYomu(int choice1, int choice2, std::string){

    bool validInput = false;
    std::string userInput;
    int returnInt;

       while (!validInput) {
        getline(std::cin, userInput);

        std::istringstream i(userInput);
        
        if (!(i >> returnInt)) 
                std::cout << "Invalid input. Please enter an integer." << std::endl;
            
        else if ((returnInt < choice1) || (returnInt > choice2)) {
                std::cout << "Invalid input. Enter " << choice1;
                std::cout << " or " << choice2 << std::endl;
        }
        //check for decimal input
        else if (userInput.find('.') != std::string::npos)
                std::cout << "Invalid input. Please enter an integer." << std::endl;
            
        else {
            validInput = true;
        }
    }
       
            return returnInt;
}

//return a double, no params
double doubleYomu(){

    bool validInput = false;
    std::string userInput;
    double returnDouble;

    std::cin.clear();
    while (!validInput) {
        getline(std::cin, userInput);
        
        std::istringstream i(userInput);
        if (!(i >> returnDouble))
            std::cout << "Invalid input." << std::endl;
       
        else if (userInput.find('.') == std::string::npos) 
        std::cout << "Invalid input. Doubles require a decimal point." << std::endl;
        
        else { 
            validInput = true;
            return returnDouble;
        }
    }
}

//double min 
double doubleYomu(double min){

    bool validInput = false;
    std::string userInput;
    double returnDouble;

    while (!validInput) {
        getline(std::cin, userInput);
        
        std::istringstream i(userInput);
        if (!(i >> returnDouble)) {
            std::cout << "Invalid input." << std::endl;
        }
        else if (returnDouble < min) 
            std::cout << "Invalid input. Must be at least " << min << std::endl;
 
        else if (userInput.find('.') == std::string::npos) 
        std::cout << "Invalid input. Doubles require a decimal point." << std::endl;
       
        else { 
            validInput = true;
            return returnDouble;
        }
    }
}
//double range
double doubleYomu(double low, double high){

    bool validInput = false;
    std::string userInput;
    double returnDouble;

    while (!validInput) {
        getline(std::cin, userInput);
        
        std::istringstream i(userInput);
        if (!(i >> returnDouble)) {
            std::cout << "Invalid input." << std::endl;
        }
        else if ((returnDouble < low) || (returnDouble > high)) {
            std::cout << "Invalid input. Enter a number between " << low;
            std::cout << " and " << high << std::endl;
    }

        else if (userInput.find('.') == std::string::npos)
            std::cout << "Invalid input. Doubles require a decimal point." << std::endl;
       
        else { 
            validInput = true;
            return returnDouble;
        }
    }
}

//double strict
double doubleYomu(double choice1, double choice2, std::string){

    bool validInput = false;
    std::string userInput;
    double returnDouble;

    std::cin.clear();
    while (!validInput) {
        getline(std::cin, userInput);
        
        std::istringstream i(userInput);
        if (!(i >> returnDouble)) 
            std::cout << "Invalid input. Please enter a double." << std::endl;

        else if ((returnDouble < choice1) || (returnDouble > choice2)) {
            std::cout << "Invalid input. Enter " << choice1;
            std::cout << " or " << choice2 << std::endl;
    }
        else if (userInput.find('.') == std::string::npos)
            std::cout << "Invalid input. Doubles require a decimal point." << std::endl;
        
        else { 
            validInput = true;
            return returnDouble;
        }
    }
}
