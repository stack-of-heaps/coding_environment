#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"

class Medusa : public Character {

    public:
        Medusa(std::string n);

        void attack(int* attackArray);
        
};

#endif
