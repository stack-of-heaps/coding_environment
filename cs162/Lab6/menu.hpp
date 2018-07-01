#ifndef MENU_HPP
#define MENU_HPP

#include "dll.hpp"
#include "yomu.hpp"

static DLL* nodeList = new DLL();

bool dispMenu();
void menuChoice(int menuItem, DLL* node = nodeList);

void printNodes(Node* node);

#endif
