#include "dll.hpp"
#include <iostream>

DLL::DLL() {
    head = nullptr;
    tail = nullptr;
}

DLL::~DLL() {
    listNode* ptr = head;
    while (ptr != nullptr) {
        listNode* tempPtr = ptr;
        ptr = ptr -> next;
        delete tempPtr;
    }

    delete head;
    delete tail;
}

void DLL::printHead() {
    if (head != nullptr)
    std::cout << head -> value << std::endl;
}

void DLL::printTail(){
    if (tail != nullptr)
    std::cout << tail -> value << std::endl;
}

void DLL::display() {
    if (tail == nullptr && head == nullptr)
        std::cout << "No list to display!" << std::endl;
    else if (head == nullptr)
        std::cout << "Null!" << std::endl;
    else {
        listNode* ptr = head;
        while (ptr) {
            std::cout << ptr -> value << std::endl;
            ptr = ptr -> next;
        }
    }
}

void DLL::reverselyTraverse() {
    if (tail == nullptr && head == nullptr)
        std::cout << "No list to display!" << std::endl;
    else {
        listNode* ptr = tail;
        while (ptr) {
            std::cout << ptr -> value << std::endl;
            ptr = ptr -> prev;
        }
    }
}
void DLL::addToHead(int v) {
    if (head == nullptr) {
        std::cout << "No head yet. Creating head: (" << v << ")" << std::endl;

        head = new listNode(v);
    }

    else if (tail == nullptr) {
        std::cout << "No tail yet. Value " << v << "will be the tail." << std::endl;
        tail = new listNode(v);
        head -> next = tail;
        tail -> prev = head;
    }

    else {
        std::cout << std::endl;
        std::cout << "Adding " << v << " to Head: " << std::endl;
        listNode* temp = new listNode(v);
        head -> prev = temp;
        temp -> next = head;
        head = temp;
        }
    }

void DLL::addToTail(int v) {
    if (tail == nullptr && head == nullptr){
        std::cout << "No head or tail. Creating head (" << v << ")" << std::endl;
        addToHead(v);
    }

    else if (tail == nullptr) {
        std::cout << "No tail yet. Creating tail (" << v << ")" << std::endl;
        tail = new listNode(v);
        tail -> prev = head;
        head -> next = tail;
    }

    else {
        std::cout << std::endl;
        std::cout << "Adding " << v << " to Tail " << std::endl;
        listNode* temp = new listNode(v);
        tail -> next = temp;
        temp -> prev = tail; 
        tail = temp;
    }
}

void DLL::deleteFirstNode() {

    if (head == nullptr) {
        std::cout << "No head to delete" << std::endl;
        return;
    }
    else if (head -> next == nullptr)  {
        delete head;
        head = nullptr;
    }

    else {
        std::cout << std::endl;
        std::cout << "Deleting First Node: " << std::endl;
        listNode* ptr = head;
        ptr = head -> next;
        delete head;
        head = ptr;
    }

}

void DLL::deleteLastNode(){

    if (tail == nullptr) {
        std::cout << "No tail to delete" << std::endl;
        return;
    }
    else if (tail -> prev == nullptr) {
        delete tail;
        tail = nullptr;
    }
    else {
        std::cout << std::endl;
        std::cout << "Deleting Last Node: " << std::endl;
        listNode* ptr = tail;
        ptr = tail -> prev;
        delete tail;
        tail = ptr;
    }

}
