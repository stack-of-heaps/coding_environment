#include "dll.hpp"

DLL::DLL() {
    head = nullptr;
    tail = nullptr;
}

Node* DLL::getHead() {
    return head;
}

Node* DLL::getTail() {
    return tail;
}

void DLL::addToHead(int v) {

    if (head == nullptr) {
        
        std::cout << "List is currently empty. Creating list." << std::endl;
        head = new Node(v, head);

    }
       
    else 
        head = head -> addHeadNode(v, head);

}

void DLL::addToTail(int v) {

    if (tail == nullptr) {
        std::cout << "Tail position is currently empty. Creating tail." << std::endl;
        tail = new Node(v, tail);
    }
    else {
        Node* temp = tail;
        
        tail = tail -> addTailNode(v, tail);
    }
}

void DLL::deleteHead() {

    if (head == nullptr)
        std::cout << "Head doesn't point to anything. Can't delete." << std::endl;

    else {
        Node* tempPtr = head -> prevNode();
        delete head;
        head = tempPtr;
        delete tempPtr;
    }
}

void DLL::deleteTail() {

    if (tail == nullptr)
        std::cout << "Tail doesn't point to anything. Can't delete." << std::endl;

    else {
        Node* tempPtr = tail -> nextNode();
        delete tail;
        tail = tempPtr;
        delete tempPtr;
    }
}


void DLL::traverse() {

    if (head == nullptr && tail == nullptr)
        std::cout << "The list is empty!" << std::endl;

    else if (getTail() == nullptr)
        std::cout << head -> getVal() << std::endl;

    else if (getHead() == nullptr)
        std::cout << tail -> getVal() << std::endl;

    else {
        std::cout << "Starting from the head: ";
        Node* ptr = this -> getHead();

        while (ptr != nullptr){
            std::cout << ptr -> getVal();
            ptr = ptr -> nextNode();
        }
    }

}

void DLL::reverselyTraverse() {

    if (head == nullptr && tail == nullptr)
        std::cout << "The list is empty!" << std::endl;

    else if (getTail() == nullptr)
        std::cout << head -> getVal() << std::endl;

    else if (getHead() == nullptr)
        std::cout << tail -> getVal() << std::endl;

    else {

        std::cout << std::endl;
        std::cout << "Starting from the tail: " << std::endl;
        Node* ptr = tail;

        while (ptr != nullptr) {
            std::cout << ptr -> getVal();
            ptr = ptr -> prevNode();
        }
    }

}
