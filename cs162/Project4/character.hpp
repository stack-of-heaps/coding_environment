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
        int maxStrength;

        std::string charType;

    public:
        Character(std::string n, int atkRolls, int atkSides, int defRolls, int defSides, int arm, int str, std::string type, int maxStr);
        virtual int attack();
        virtual int defend(int atk);
       
        std::string getName();
        int getStrength();
        int getArmor();

        std::string getType();
       
        void death();

        void restoreHealth();
    };


#endif
