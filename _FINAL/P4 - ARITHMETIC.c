/*
  * Author    : Edrian Jose D.G. Ferrer, Aldrin O. Dizor
  * Section   : BSCoE 1-5
  * Date      : August 07, 2018
  * Professor : Engr. Pederito Tenerife Jr.
*/
#include <stdio.h>
#include <stdlib.h>


int main() {

  int firstNum,
      secondNum,
      sum,
      diff,
      prod,
      quot;

  // Input
  printf("\nENTER FIRST NUMBER:");
  scanf("%d" , &firstNum);

  printf("\nENTER SECOND NUMBER:");
  scanf("%d" , &secondNum);

  // Process
  sum = firstNum + secondNum;
  diff = firstNum - secondNum;
  prod = firstNum * secondNum;
  quot = firstNum / secondNum;

  // Output
  printf("\nTHE SUM OF %d and %d IS %d\n", firstNum, secondNum, sum);
  printf("THE DIFFERENCE OF %d and %d IS %d\n", firstNum, secondNum, diff);
  printf("THE PRODUCT OF %d and %d IS %d\n", firstNum, secondNum, prod);
  printf("THE QUOTIENT OF %d and %d IS %d\n\n", firstNum, secondNum, quot);


  return 0;
}


//no code that follows
