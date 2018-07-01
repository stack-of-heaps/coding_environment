#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character {

    public:
        Vampire(std::string n);

        void attack(int* attackArray);
        void defend(int* attackArray);
};

#endif
