#include <iostream>

void countDown(int num) {

    if (num == 0)
        std::cout << "Blast off!!!!!!" << std::endl;
    else {
        std::cout << num << "..." << std::endl;
        countDown(num-1);
    }
}


int factorial(int n) {

    if (n == 0)
        return 1;
    else {
        std::cout << "Current n: " << n << std::endl;
        return n * factorial(n-1);
    }
}

int gcd(int x, int y) {

    std::cout << "Asking for the greatest common denominator of " << x << "and " << y << std::endl;
    if (x % y == 0)
        std::cout << "GCD of " << x << " is " << y << std::endl;
    else {
        gcd(x, x % y);
    }
}

int fibSeries(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        std::cout << n << std::endl;
        return fibSeries(n - 1) + fibSeries (n - 2);
    }
}

int main(){

    countDown(5);

    std::cout << factorial(10) << std::endl;

    gcd(10, 100);

    gcd(100, 10);

    gcd(55, 12);

    gcd(99094141, 214);

    std::cout << fibSeries(10) << std::endl;

    return 0;
}
