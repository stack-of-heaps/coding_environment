/***************************************************************************
 *Name: Kyle Karthauser                                                    *
 *Date: 1/29/18                                                            *
 *Description: This function implements the "Collatz Conjecture,"          *
 *sometimes referred to as a hailstone function. It accepts as input       *
 *an integer. If the integer is even, it is divided by 2. If it is odd,    *
 *multiply by 3 and add 1. The result is evaluated as either even or odd   *
 *and the process continues until the function returns a value of 1.       *
 *The function counts the number of steps it takes to reach 1 and returns  *
 *that value.                                                              *
 **************************************************************************/

int hailstone(int seed){
  static int collatz = 0;

  if (seed <= 0) // Screening input
  {
  std::cout << "Invalid input\n";
  return 0;
  }

  else if (seed == 1) // If user enters 1, we are done
  {
      collatz = 0;
      return collatz; // Var for counting number of iterations necessary to reach seed = 1
  }

else 
 {
     while (seed != 1) // Collatz conjecture loop
     {
         if (seed % 2 != 0) // Processing odd numbers
            {
            seed = (seed * 3) + 1;
            collatz++;
            }
         if (seed % 2 == 0) // Processing even numbers
         {
             seed = seed / 2;
             collatz++;
         }
         else
         return collatz;
     };
};
return collatz;
}
