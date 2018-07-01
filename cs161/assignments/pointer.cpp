#include <iostream>

int* ptr = NULL;

int returnInt(int);

int main(){


std::cout << "Enter array size" << std::endl;

int arraySize;

std::cin>>arraySize;

ptr = new int[arraySize];

for (int count = 0; count < arraySize; count++){
    *(ptr + count) = count;
    std::cout << *(ptr + count) << std::endl;
    }

std::cout << returnInt(3);
    return 0;
}

int returnInt(int tester){
    int giver = tester*2;
    return giver;
}