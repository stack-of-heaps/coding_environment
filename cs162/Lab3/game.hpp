#ifndef GAME_HPP
#define GAME_HPP
#include "die.hpp"
#include "loadedDie.hpp"

#include <vector>

void game(int numberOfRounds, std::vector<Die*>&dice, std::vector<LoadedDie*>&loadedDice);

#endif
