#include <iostream>
#include "findMedian.cpp"

int main(){

double medianR;

int arrayGo[4] = {523, 59, 1, 3900};

medianR = findMedian(arrayGo, 4);

std::cout << medianR;

    return 0;
}