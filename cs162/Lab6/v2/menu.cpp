#include "menu.hpp"
#include "dll.hpp"
#include "yomu.hpp"

#include <iostream>

DLL* listNode = new DLL();

bool dispMenu() {

    std::cout << "1. Add a new node to the head;" << std::endl;
    std::cout << "2. Add a new node to the tail;" << std::endl;
    std::cout << "3. Delete from head;" << std::endl;
    std::cout << "4. Delete from tail;" << std::endl;
    std::cout << "5. Traverse the list reversely;" << std::endl;
    std::cout << "6. Print list head;" << std::endl;
    std::cout << "7. Print list tail;" << std::endl;
    std::cout << "8. Exit." << std::endl;

    std::cout << "Please enter a choice 1-8." << std::endl;

    int userChoice = intYomu(1, 8);

    menuChoice(userChoice);
}

void menuChoice(int menuItem) {

    switch (menuItem) {

        case 1: {
                int newVal;
                std::cout << "Enter an integer: " << std::endl;
                newVal = intYomu();
                nodeList -> addToHead(newVal);
                menuChoice(10);
            break;
                }

        case 2: {
                int newVal;
                std::cout << "Enter an integer: " << std::endl;
                newVal = intYomu();
                nodeList -> addToTail(newVal);
                menuChoice(10);
            break;
                } 

        case 3: {
                nodeList -> deleteFirstNode();
                menuChoice(10);
            break;
                }

        case 4: { 
                nodeList -> deleteLastNode();
                menuChoice(10);
            break;
                }

        case 5: {
                nodeList -> reverselyTraverse();
            break;
                }

        case 6: {
                nodeList -> printHead();
            break;
                }
        case 7: {
                nodeList -> printTail();
            break;
                }
        case 8: exit (EXIT_SUCCESS);
            break;

        case 10: nodeList -> display();
            break;
    }
}
