#include "fibNR.hpp"

int fibNRCalc(int n) {

    int first = 0;
    int second = 1;
    int temp = first;
    int counter = 2;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    else {
        while (counter < n) {

            int temp = second;
            second = first + second;
            first = temp;
            counter++;
        }

        return first+second;
    }
}
