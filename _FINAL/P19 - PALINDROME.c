/*

  * Author    : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.

  * Section   : BSCoE 1-5
  * Date      : October 9, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/

#include "console_ui.h"


int main() {

  system("color E0");

  char str[100],answer[10];

  int  len,
       hasDifference = 0,
       tryAgain = 0,
       repeat = 0;


  do {
    gotoxy(21,3);   printf("Input a series of characters\n");
    incy(2);        gets(str);

    len = strlen(str);
    char txt[len];
    strcpy(txt,str);

    for (int i = 0; i < len; i++) {
      if (txt[i] != txt[len-(i+1)]) {
        hasDifference = 1;
        break;
      }
    }

    incy(2);    if (hasDifference) {
                  printf("%s\n", "Not a palindrome");
                }else{
                  printf("%s\n", "A palindrome");
                }

    hasDifference = 0;

    do {
      if (repeat) {
        system("cls");
        gotoxy(21,3);printf("Invalid answer\n");
        repeat = 0;
      }

      incy(2);     printf("Do you want to try again? Y / N\n");
      incy(2);     gets(answer);

      answer[0] = toupper(answer[0]);

      if (!strcmp(answer,"Y") || !strcmp(answer,"Yes") || !strcmp(answer,"YES") || !strcmp(answer,"YeS") || !strcmp(answer,"YEs")) {

        tryAgain = 1;
        system("cls");
        gotoxy(0,0);

      }else if(!strcmp(answer,"N") || !strcmp(answer,"No") || !strcmp(answer,"NO")){

        tryAgain = 0;

      }else{

        repeat = 1;

      }
    } while(repeat);

  } while(tryAgain);

  gotoxy(21,YPOS+2);
  return 0;
}
