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
                for (int j = i; j < 5; j++) {
                        printf(" ");
                }
                for (int k = 0; k < i+1; k++) {
                        printf("*");
                }
                printf("\n");
        }
        for (int l = 4; l > 0; l--) {
                for (int m  = l; m < 6; m++) {
                        printf(" ");
                }
                for (int n = 0; n < l; n++) {
                        printf("*");
                }
                printf("\n");
        }
        return 0;
}
