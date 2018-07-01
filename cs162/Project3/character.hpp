#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <random>
#include <iostream>

static std::random_device randyEngine;
static std::mt19937 Twister(randyEngine());

class Character {

    protected:
        std::string name;
        int attackDieRolls; // e.g. 2d6 = 2 rolls, 6 sides
        int attackDieSides;
        int defenseDieRolls;
        int defenseDieSides;

        int armor;
        int strength;

        bool getsAttack;

        std::string charType;

    public:
        Character(std::string n, int atkRolls, int atkSides, int defRolls, int defSides, int arm, int str, std::string type);
        virtual void attack(int* attackArray);
        //For the defend function, there are several special cases for attack values.
        //-5: Medusa's glare
        //-10: Vampire's charm
        //-99: Death
        virtual void defend(int* attackArray);
       
        void skipNextAttack();

        std::string getName();
        int getStrength();
        int getArmor();
        bool canAttack();

        std::string getType();
       
        void death();

};


#endif
