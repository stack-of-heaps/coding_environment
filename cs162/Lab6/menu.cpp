#include "menu.hpp"

#include <iostream>

bool dispMenu() {

    std::cout << "1. Add a new node to the head;" << std::endl;
    std::cout << "2. Add a new node to the tail;" << std::endl;
    std::cout << "3. Delete from head;" << std::endl;
    std::cout << "4. Delete from tail;" << std::endl;
    std::cout << "5. Traverse the list reversely;" << std::endl;
    std::cout << "6. Exit." << std::endl;

    std::cout << "Please enter a choice 1-6." << std::endl;

    int userChoice = intYomu(1, 6);

    menuChoice(userChoice);
}

void menuChoice(int menuItem, DLL* node) {

    switch (menuItem) {

        case 1: {
                int newVal;
                std::cout << "Enter an integer: " << std::endl;
                newVal = intYomu();
                menuChoice(7);
            break;
                }

        case 2: {
                int newVal;
                std::cout << "Enter an integer: " << std::endl;
                newVal = intYomu();
                Node* tail = nodeList -> getTail();
                tail = new Node(newVal, tail);
                menuChoice(7);
            break;
                } 

        case 3: {
                nodeList -> deleteHead();
                menuChoice(7);
            break;
                }

        case 4: { 
                nodeList -> deleteTail();
                menuChoice(7);
            break;
                }

        case 5: {
                nodeList -> reverselyTraverse();
                menuChoice(7);
            break;
                }

        case 6: exit (EXIT_SUCCESS);
            break;

        case 7: nodeList -> getHead() -> printNodes();
            break;
    }
}
