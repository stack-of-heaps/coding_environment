/* Name: Kyle Karthauser
 * Description: I'm using a mix of menu and in-main programming to generate
 * the dice for the program. I could have passed my vectors to a menu 
 * function and returned them loaded, but this seems like too much fussing
 * over a relatively simple program.
 * 1) Dice are created
 * 2) Dice are rolled
 * 3) Results are printed
 */

#include "menu.hpp"
#include "game.hpp"
#include <vector>

int main(){

    menu();

    //These vectors will hold all of the Die and LoadedDie objects we create.
    //They will be passed to the game() function and handled there
    std::vector<Die*> dice;
    dice.reserve(2); //We only need two spots, one for each player
    std::vector<LoadedDie*> loadedDice;
    loadedDice.reserve(2);

    int dieChoice;

    //player one
    dieChoice = menuChooseDieType(1);

    int sideChoice;
    double weightChoice;

    if (dieChoice == 1) {
        std::cout << "How many sides on this die?" << std::endl;
        sideChoice = intYomu(1);
        dice.emplace_back(new Die(sideChoice));
    }
    if (dieChoice == 2) {
        std::cout << "How many sides on this die?" << std::endl;
        sideChoice = intYomu(1);
        std::cout << "How loaded do you want it to be?" << std::endl;
        std::cout << "Acceptable input: between 1.00 and 2.00." << std::endl;
        std::cout << "E.g., '1.5' would make high rolls 50% more likely." << std::endl;
        weightChoice = doubleYomu(1.00, 2.00);

        loadedDice.emplace_back(new LoadedDie(sideChoice, weightChoice));
    }

    //player two
    dieChoice = menuChooseDieType(2);

    if (dieChoice == 1) {
            std::cout << "How many sides on this die?" << std::endl;
            sideChoice = intYomu();
            dice.emplace_back(new Die(sideChoice));
        }
        if (dieChoice == 2) {
            std::cout << "How many sides on this die?" << std::endl;
            sideChoice = intYomu();
            std::cout << "How loaded do you want it to be?" << std::endl;
            std::cout << "Acceptable input: between 1.00 and 2.00." << std::endl;
            std::cout << "E.g., '1.5' would make high rolls 50% more likely." << std::endl;
            weightChoice = doubleYomu(1.00, 2.00);

            loadedDice.emplace_back(new LoadedDie(sideChoice, weightChoice));
        }

    int numberOfRounds = menuHowManyRounds();

    //game() actually handles everything from here
    game(numberOfRounds, dice, loadedDice);

return 0;    
}
