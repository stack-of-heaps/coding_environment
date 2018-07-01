#ifndef DLL_HPP
#define DLL_HPP

class DLL {

    protected:
        struct listNode {
            int value;
            listNode* next;
            listNode* prev;
            
            listNode(int val, listNode* next1 = nullptr, listNode* prev1 = nullptr) {
               value = val;
               next = next1;
               prev = prev1;
            }
        };
        listNode* head;
        listNode* tail;

    public:

        DLL();
        ~DLL();
       void add(int v);
       void addToHead(int v);
       void addToTail(int v);
       void deleteFirstNode();
       void deleteLastNode();
       void remove();
       void display();
       void reverselyTraverse();
        void printTail();
        void printHead();
};

#endif
