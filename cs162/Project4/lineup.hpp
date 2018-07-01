#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "character.hpp"
#include <string>

class Lineup {

    private:
        std::string name;

        struct Node {
            Character* fighter;
            Node* next;
            Node* prev;

            Node(Character* f) {fighter = f;};
        };

        Node* head = nullptr;

    public:
        Lineup(std::string n);
        ~Lineup();
    bool isEmpty();
    void addBack(Character* fighter);
    Character* getFront();
    void removeFront();
    void moveToBack();
    void printLineup();
    std::string getLineupName();    
    
};

#endif
