#include "yomu.cpp"

int main(){

    std::string s;

    std::cout << "Please enter a mix of numbers and letters: " << std::endl;

    getline(std::cin, s);

    int f = yomu(s);

    std::cout << f << std::endl;

    return 0;
}
