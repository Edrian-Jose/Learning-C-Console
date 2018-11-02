/*

  * Author    : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.

  * Section   : BSCoE 1-5
  * Date      : August 26, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/


#include <stdio.h>

int main() {

        // The first half of the right arrow
        /*

        *
        **
        ***
        ****
        *****

        */
        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < i+1; j++) {
                        printf("*");
                }
                printf("\n");
        }


        // The second half of the right arrow
        /*

        ****
        ***
        **
        *

        */
        for (int k = 4; k > 0; k--) {
                for (int l  = 0; l < k; l++) {
                        printf("*");
                }
                printf("\n");
        }
        return 0;
}
