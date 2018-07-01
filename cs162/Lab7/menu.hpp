#ifndef MENU_HPP
#define MENU_HPP

#include "yomu.hpp"
#include "queue.hpp"

static Queue* mainQueue = new Queue();

bool dispMenu(Queue* mainQueue);

void menuChoice(int userChoice);

#endif
