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
        for (int i = 0; i < 5; i++) {
                for (int fst = 0; fst < i+1; fst++) {
                        printf("*");
                }
                for (int spc = 4; spc > i; spc--){
                        if (i < 4) {
                                printf(" ");
                        }
                }
                for (int spc = 3; spc > i; spc--) {
                        if (i < 4) {
                                printf(" ");
                        }
                }
                int lst = 0;
                if (i == 4) {
                        lst = 1;
                }
                for (; lst < i+1; lst++) {
                        printf("*");
                }
                printf("\n");

        }

        for (int j = 4; j > 0; j--) {
                for (int fstb = 0; fstb < j; fstb++) {
                        printf("*");
                }
                for (int spcb = j; spcb < 5; spcb++) {
                        printf(" ");
                }

                for (int spcb = j; spcb < 4; spcb++) {
                        if (j != 4) {
                                printf(" ");
                        }
                }
                for (int lstb = 0; lstb < j; lstb++) {
                        printf("*");
                }
                printf("\n");
        }
        return 0;
}
