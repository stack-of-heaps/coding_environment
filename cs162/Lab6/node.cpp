#include "node.hpp"

Node::Node(int v) {
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

void Node::printNodes() {
    Node* ptr = this;
    //check if the node is empty 
    if (ptr == nullptr)
        std::cout << "The list is empty." << std::endl;

    else {

        //otherwise print all the node values
        while (ptr != nullptr) {
            std::cout << ptr -> getVal() << " "; 
            ptr = ptr -> nextNode();
        }
    }
}

    void Node::printNodesReverse() {
    Node* ptr = this;
    //check if the node is empty 
    if (ptr == nullptr)
        std::cout << "The list is empty." << std::endl;

    else {

        //otherwise print all the node values
        while (ptr != nullptr) {
            std::cout << ptr -> getVal() << " "; 
            ptr = ptr -> prevNode();
        }
    }
}

    Node* Node::addHeadNode(int val, Node* oldHead) {
        Node* temp = new Node(val);
        oldHead -> prevPtr = temp;
        oldHead = temp;

    }

    Node* Node::addTailNode(int val, Node* oldTail) {
        Node* temp = new Node(val);
        oldTail -> prevPtr = oldTail = new Node(val);
    }


Node* Node::nextNode() {
    return nextPtr;
}

Node* Node::prevNode() {
    return prevPtr;
}

void Node::setNextNode(Node* nextNode) {

   nextPtr = nextNode; 

}

void Node::setPrevNode(Node* prevNode) {

    prevPtr = prevNode;

}
