#include "fibR.hpp"
#include "fibNR.hpp"
#include <chrono>
#include <cmath>

using namespace std;


//Chrono implementation taken from:
//https://www.guyrutenberg.com/2013/01/27/using-stdchronohigh_resolution_clock-example/

int main() {

    cout << "Average time required to calculate the 30th Fibonacci Number 100 Times" << endl;
    cout << endl;

    int counterR = 1;
    int runTimeSumR = 0;

    while (counterR < 101) {
        auto start = chrono::high_resolution_clock::now();
        fibRCalc(30);
        auto end = chrono::high_resolution_clock::now();

        runTimeSumR += chrono::duration_cast<chrono::nanoseconds>(end-start).count();
        counterR++;
    }

    double averageR = (runTimeSumR/counterR) / 1000000000;

    std::cout << "1) Average time to run recursive function: " << runTimeSumR/counterR << " nanoseconds " << "( " << averageR << " seconds)" << endl;

    int counterNR = 1;
    int runTimeSumNR = 0;

    while (counterNR < 101) {
        auto start2 = chrono::high_resolution_clock::now();
        fibNRCalc(30);
        auto end2 = chrono::high_resolution_clock::now();

  
        runTimeSumNR += chrono::duration_cast<chrono::nanoseconds>(end2-start2).count();
        counterNR++;
    }

    double averageNR = (runTimeSumNR/counterNR) / 1000000000;
    std::cout << "2) Average time to run non-recursive function: " << runTimeSumNR/counterNR << " nanoseconds " << "( " << averageNR << " seconds)" << endl;


    cout << "***Non-recursive is " << abs(runTimeSumNR - runTimeSumR) / runTimeSumNR* 100 << "% faster than recursive!" << endl;

    return 0;
}

