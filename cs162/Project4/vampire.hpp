#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character {

    public:
        Vampire(std::string n);

        int defend(int atk);
};

#endif
