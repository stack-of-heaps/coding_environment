#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {

    protected:
    struct QueueNode {
        QueueNode* nextPtr;
        QueueNode* prevPtr;
        int val;

        QueueNode(int v, QueueNode* prev1 = nullptr, QueueNode* next1 = nullptr) {
            val = v;
            nextPtr = prev1;
            prevPtr = next1;
        }
    };

    QueueNode* head;

    public:
    Queue();
    ~Queue();

    bool isEmpty();
    //checks if the queue is empty. If so, returns true; otherwise, return false. 
    
    void addBack(int val);
    //    takes a user-inputted integer, creates a QueueNode with user-inputted integer, and appends it to the back of the list.

    int getFront();
     //   returns the value of the node at the front of the queue. 

    void removeFront();
      //  removes the front QueueNode of the queue and free the memory. 

    void printQueue();
       // traverses through the queue from head using next pointers, and prints the values of each QueueNode in the queue.

};

#endif
