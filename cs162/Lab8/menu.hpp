#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include <fstream>

typedef std::vector<int> vec;

void readInFiles(std::string fileName, vec &vec);

void simpleSearch(vec &file0, vec &file1, vec &file2, vec &file3);

void bSearch(vec, vec, vec, vec);

#endif
