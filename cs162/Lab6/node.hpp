#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node {

    private:
    
        Node* nextPtr;
        Node* prevPtr;
        int val;

    public:
        void setVal(int v);
        int getVal();
        Node* nextNode();
        Node* prevNode();

        void setNextNode(Node* nextNode);
        void setPrevNode(Node* prevNode);

        void printNodes();
        void printNodesReverse();
        Node* addHeadNode(int val, Node* head);
        Node* addTailNode(int val, Node* tail);
        Node(int v);
};

#endif
