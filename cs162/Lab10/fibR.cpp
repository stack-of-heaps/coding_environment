#include "fibR.hpp"

int fibRCalc(int n) {

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return fibRCalc(n-1) + fibRCalc(n-2);

}
