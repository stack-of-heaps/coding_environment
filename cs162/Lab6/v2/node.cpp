#include "node.hpp"

Node::Node(int v){
    val = v;
    nextPtr = nullptr;
    prevPtr = nullptr;
}

void Node::setVal(int v) {
    val = v;
}

int Node::getVal() {
    return val;
}

Node* Node::nextNode() {
    return nextPtr;
}

Node* Node::prevNode() {
    return prevPtr;
}

Node* addNode(int v, Node* next1) {
    
    Node* temp = new Node(v);
    temp -> setNextNode(next1);
}

Node* addToHead(int v) {
    Node* tempNode = new Node(v);
    Node* ptr;
}

void Node::printNodes() {
    Node* ptr = this;

    while (ptr != nullptr) {
        std::cout << ptr -> getVal();
    ptr = ptr -> nextPtr;
    }
}
