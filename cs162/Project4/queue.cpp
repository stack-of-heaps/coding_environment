#include "queue.hpp"

#include <iostream>

Queue::Queue() {
    head = nullptr;
}

//Destructor method deletes
Queue::~Queue() {
    QueueNode* garbageCollector = head -> nextPtr;
    QueueNode* deleteThis = garbageCollector;
    while (garbageCollector != head) {
        garbageCollector = garbageCollector -> nextPtr;
        delete deleteThis;
        deleteThis = garbageCollector;
    }

    delete head;
    delete garbageCollector;
    delete deleteThis;
}

bool Queue::isEmpty(){

    if (this -> head == nullptr)
        return true;
    else
        return false;
}

int Queue::getFront() {
    if (!isEmpty())
        return head -> val;
    else {
        std::cout << "List is empty !" << std::endl;
        return 0;
    }
}

void Queue::addBack(int val) {
    //Case: List is empty
    if (isEmpty()) {
        std::cout << "Queue is empty. Creating first node." << std::endl;
        head = new QueueNode(val);
        head -> nextPtr = head;
        head -> prevPtr = head;
        
    }

    //Case: List consists of one node 
    else if (head -> nextPtr == head) {
        std::cout << "Adding second node... " << std::endl;
        QueueNode* tempPtr;
        tempPtr = new QueueNode(val);
        tempPtr -> nextPtr = head;
        tempPtr -> prevPtr = head;
        head -> nextPtr = tempPtr;
        head -> prevPtr = tempPtr;
    }
       
    //If this is the 3rd, 4th, 5th... node
    else {
        std::cout << "At least 3rd node: " << std::endl;
        QueueNode* tempPtr;
        tempPtr = new QueueNode(val);
        tempPtr -> nextPtr = head;
        tempPtr -> prevPtr = head -> prevPtr;
        head -> prevPtr -> nextPtr = tempPtr;
        head -> prevPtr = tempPtr;
    }
}

void Queue::removeFront() {
    //Case: No nodes
    if (isEmpty())
        std::cout << "List is empty. Cannot delete." << std::endl;

    //Case: 1 Node
    else if (head -> nextPtr == head) {
        std::cout << "Deleting head. List is now empty." << std::endl;
        delete head;
        head = nullptr;
    }

    //Case: 2+ Nodes
    else if (head -> nextPtr -> nextPtr == head) {
        std::cout << "Deleting..." << std::endl;
        QueueNode* tempPtr = head -> nextPtr;
        delete head;
        head = tempPtr;
        tempPtr -> nextPtr = head;
        tempPtr -> prevPtr = head;
    }
        else {
        std::cout << "Deleting... " << std::endl;
        QueueNode* tempPtr = head -> nextPtr;
        tempPtr -> prevPtr = head -> prevPtr;
        head -> prevPtr -> nextPtr = tempPtr;
        delete head;
        head = tempPtr;
        }
}

void Queue::printQueue() {

    int counter = 1;
    
    if (isEmpty()) 
        std::cout << "Queue is empty !" << std::endl;

    else if (head -> nextPtr == head) {
        std::cout << "Queue has one value: " << head -> val << std::endl;
        std::cout << std::endl;
    }

    else {
        QueueNode* tempPtr = head;
        std::cout << "Queue value #" << counter << ": " << tempPtr -> val << std::endl;
        tempPtr = tempPtr -> nextPtr;
        counter++;
        while (tempPtr != head) {
        std::cout << "Queue value #" << counter << ": " << tempPtr -> val << std::endl;
            tempPtr = tempPtr -> nextPtr;
            counter++;
        }
    }
}



