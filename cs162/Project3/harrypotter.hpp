#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class HarryPotter : public Character {

    private:
        int lifeCount;

    public:
        HarryPotter(std::string n);
        void defend(int* attackArray);

};

#endif
