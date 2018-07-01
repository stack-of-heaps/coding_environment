/* ******************************************************
 *       Name: Kyle Karthauser                           *
 *       Date: 1/28/18                                   *
 *       Description: This program will accept three int *
 *     parameters as reference variables. It will sort   *
 *       the three integers, lowest to high, and output  *
 *       them in that order.                             *
*********************************************************/

void smallSort(int &a, int &b, int &c){
 
    int valueShift; // This variable will take on a reference variable value and let us sort before re-assigning
   
    if (a > b)
        {
        valueShift = a;
        a = b;
        b = valueShift;
        }
    if (b > c)
        {
        valueShift = b;
        b = c;
        c = valueShift;
        }
    if (a > b)
        {
        valueShift = a;
        a = b;
        b = valueShift;
        };
    std::cout << a << ", " << b << ", " << c;
}


