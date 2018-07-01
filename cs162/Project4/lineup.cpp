#include "lineup.hpp"

Lineup::Lineup(std::string n) {
    name = n;
}

Lineup::~Lineup() {
}

//checks to see if the lineup has any fighters in it
bool Lineup::isEmpty(){

    if (this -> head == nullptr)
        return true;
    else
        return false;
}


//Returns the character at the front. This "loads" the combatants into the
//match class prior to the start of the fight.
Character* Lineup::getFront() {
    if (!isEmpty())
        return head -> fighter;
    else {
        std::cout << "List is empty !" << std::endl;
    }
}

//Takes the fighter created in the preceding menu function and adds it to the queue container
void Lineup::addBack(Character* f) {
    //Case: List is empty
    if (isEmpty()) {
        head = new Node(f);
        head -> next = head;
        head -> prev = head;
    }

    //Case: List consists of one node 
    else if (head -> next == head) {
        Node* tempPtr;
        tempPtr = new Node(f);
        tempPtr -> next = head;
        tempPtr -> prev = head;
        head -> next = tempPtr;
        head -> prev = tempPtr;
    }
       
    //If this is the 3rd, 4th, 5th... node
    else {
        Node* tempPtr;
        tempPtr = new Node(f);
        tempPtr -> next = head;
        tempPtr -> prev = head -> prev;
        head -> prev -> next = tempPtr;
        head -> prev = tempPtr;
    }
}

//Take the current head of the lineup and move them to the back.
//Used after the head fighter wins a round.
//1) Create a pointer to mark the last member of the list
//2) Move current head there
//3) Make head -> next the new head
//4) Make head -> prev -> prev
void Lineup::moveToBack() {
    if (isEmpty()) 
        std::cout << "Invalid operation. The lineup is empty." << std::endl;

    else if (head -> next == head) 
        std::cout << "Fighter " << head -> fighter -> getName() << " is the only fighter in the lineup. Cannot move back." << std::endl;

    else {
        std::cout << "Placing " << head -> fighter -> getName() << " at the back of the lineup..." << std::endl;
/*
        Node* tempPtr = head -> next;
        while (tempPtr -> next != head)
            Node* tempPtr2 = head;
            head = head -> next;
            head -> prev = tempPtr2;
            tempPtr2 -> next = head;
            tempPtr2 -> prev = tempPtr;
            tempPtr -> next = tempPtr2;
            tempPtr = tempPtr -> next;
    }
    */
        Node* tempPtr = head;
        tempPtr -> prev = head -> prev -> prev;
        head = head -> next;
        head -> prev = tempPtr;
        tempPtr -> next = head;
        tempPtr = nullptr;
    }
}



//Prints name of lineup plus the name of each fighter.
//For debugging purposes
void Lineup::printLineup() {
    if (isEmpty()) 
        std::cout << "Lineup is empty ! " << std::endl;

    else if (head -> next == head) {
        std::cout << "Lineup " << name << ": " << std::endl;
        std::cout << "Fighter 1: " << head -> fighter -> getName() << std::endl;
    }

    else {
        int counter = 1;
        std::cout << "Lineup " << name << ": " << std::endl;
       
        std::cout << "Fighter #" << counter << ": " << head -> fighter -> getName() << std::endl;

        Node* tempPtr = head -> next;
        while (tempPtr != head) {
            counter++;
            std::cout << "Fighter #" << counter << ": ";
            std::cout << tempPtr -> fighter -> getName() << std::endl;
            tempPtr = tempPtr -> next;
        }
    }
}

void Lineup::removeFront() {

    if (isEmpty()) 
        std::cout << "Lineup is empty !" << std::endl;
    
    else if (head -> next == head) {
        delete head;
        head = nullptr;
    }
    
    else {
        Node* tempPtr = head -> next;
        tempPtr -> prev = head -> prev;
        head -> prev -> next = tempPtr;
        head = tempPtr;
        tempPtr = nullptr;
    }
}

std::string Lineup::getLineupName(){
    return name;
}
