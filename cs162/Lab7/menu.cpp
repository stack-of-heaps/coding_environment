#include "menu.hpp"

bool dispMenu() {
    std::cout << "[///////] QUEUE MENU [///////]" << std::endl;
    std::cout << "1. Add a value to the back of the queue" << std::endl;
    std::cout << "2. Display the front value" << std::endl;
    std::cout << "3. Remove the front node" << std::endl;
    std::cout << "4. Display entire queue" << std::endl;
    std::cout << "5. Quit" << std::endl;

    int userChoice = intYomu(1, 5);

    if (userChoice == 5)
        return false;
    else 
    menuChoice(userChoice);

}

void menuChoice(int userChoice){
    switch (userChoice) {

        case 1: { 
                    std::cout << "Enter an integer to add to the back of the queue: ";
                    int userInput = intYomu();
                    mainQueue -> addBack(userInput);
                    std::cout << std::endl;
                    dispMenu();
            break;
                }
        
        case 2: { 
                    std::cout << "The front value of the queue is: " << mainQueue -> getFront() << std::endl;
                    std::cout << std::endl;
                    dispMenu();
            break;
                }
    
        case 3: {
                    mainQueue -> removeFront();
                    std::cout << std::endl;
                    dispMenu();
            break;
                }
    
        case 4: {
                    mainQueue -> printQueue();
                    std::cout << std::endl;
                    dispMenu();

            break;
                }
        
    }
}

