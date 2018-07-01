#ifndef DLL_HPP
#define DLL_HPP

#include "node.hpp"

class DLL {

    private:
    
        Node* head;
        Node* tail;

    public:
        
        DLL();
        Node* getHead();
        Node* getTail();
        void addToHead(int v);
        void addToTail(int v);
        void deleteHead();
        void deleteTail();
        void addHeadNode(int v, Node* head);
        void traverse();
        void reverselyTraverse();

};

#endif
