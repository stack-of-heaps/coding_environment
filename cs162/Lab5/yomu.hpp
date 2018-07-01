#ifndef YOMU_HPP
#define YOMU_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <cstring>
#include "menu.hpp"

int intYomu();
int intYomu(int min);
int intYomu(int low, int high);
int intYomu(int choice1, int choice2, std::string);

double doubleYomu();
double doubleYomu(double min);
double doubleYomu(double low, double high);
double doubleYomu(double choice1, double choice2, std::string);

#endif
