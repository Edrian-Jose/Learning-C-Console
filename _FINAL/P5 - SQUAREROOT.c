
/*

  * Author    : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.
  * Section   : BSCoE 1-5
  * Date      : August 07, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
  float squareroot;
  int base,base_sqr;
  unsigned int unsigned_base;

    //prompts the user
    printf("Enter a number :");
    scanf("%d", &base);

    //get the absolute value of the base
    base_sqr = pow(base,2);
    unsigned_base = pow(base_sqr,0.5);

    //raise the power to 1/2 to get the squareroot
    squareroot = pow(unsigned_base,0.5);

  //Display the process Input
  if (base > 0) {
    printf("The square root of %d is %f \n\n",base,squareroot);
  }
  else{
    printf("The square root of %d is %fi \n\n",base,squareroot);
  }


  return 0;
}
