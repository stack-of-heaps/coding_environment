#include "menu.hpp"

int main() {


    DLL* nodeList = new DLL();

    nodeList -> addToHead(5);
    std::cout << nodeList -> getHead() -> getVal() << std::endl;

    nodeList -> addToTail(4);
    std::cout << nodeList -> getTail() -> getVal() << std::endl;

    nodeList -> traverse();

    nodeList -> reverselyTraverse();

    return 0;
}
