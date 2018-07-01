#include "menu.hpp"
#include "algorithms.hpp"

int main() {

    typedef std::vector<int> vec;
    
    vec file0, file1, file2, file3;

    readInFiles("file0.txt", file0);
    readInFiles("file1.txt", file1);
    readInFiles("file2.txt", file2);
    readInFiles("file3.txt", file3);

    simpleSearch(file0, file1, file2, file3);

    algoSort(file0);
    algoSort(file1);
    algoSort(file2);
    algoSort(file3);

    std::cout << std::endl;

    bSearch(file0, file1, file2, file3);

    return 0;
}
