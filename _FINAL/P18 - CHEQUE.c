/*

  * Author    : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.

  * Section   : BSCoE 1-5
  * Date      : October 16, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/

#include "console_design.h"
#include "HEADERS/moneytowords.h"


int main(int argc, char const *argv[]) {

  int checkNum = 0,
      isSuccess,
      tryAgain=0,
      InvalidAnswer=0,
      done = 0;

  char money[50],
       checkNo[10],
       answer[5],
       inwords[300];


  char BottomText[50] = "PEDRITO TENERIFE JR. | 1258-9705-5795 || ";

  //initialize the console
  ConsoleProps calc = {"CHEQUE",{100,28},'F','0'};
                      initconsole(calc);
                      disableResize();

  gotoxy(5,2);        typeCT("A FRIENDLY INSTRUCTIONS",20);
  incy(3);            typeCT("1. Input only digits in the money deposit input",20);
  incy(2);            typeCT("WRONG :  Amount: Php 123c..",20);
  incy(2);            typeCT("CORRECT: Amount: Php 12345.67",20);

  Sleep(2500);
  eraseFromTo(9,3);

  incxy(5,1);         typeCT("2. Do not input value greater than 999.99 trillion, or less than 1 centavos",20);
  incy(2);            typeCT("EXAMPLE : Amount: Php 1.675",20);
  incy(3);            typeCT("3. Do not input control characters",20);
  incy(2);            typeCT("EXAMPLE : Amount: Php 1 23",20);

  Sleep(2500);
  system("cls");
  done = 1;

  start:;

  checkNum++;
  sprintf(checkNo,"%04d",checkNum);
  strcpy(BottomText,"PEDRITO TENERIFE JR. | 1258-9705-5795 || ");
  strcat(BottomText,checkNo);

  gotoxy(5,25);   csdBar(BottomText,"70",FILL,1);
  gotoxy(76,2);   csdBar(checkNo, "0E", 6, 1);
  gotoxy(5,5);    csdBar("BANK OF DEPOSIT", "E4", 2, 1);
  incx(65);       printf("Date: 10/23/2018");
  gotoxy(5,10);   printf("PAY TO THE");
  incy(1);        printf("ORDER OF\n");
  incx(12);       printf("__________________________________");
  incxy(5,-1);    if (checkNum % 2 == 0) {
                    printf("FERRER, EDRIAN JOSE D.G.");
                  }else{
                    printf("  DIZOR, BARRY ALDRIN O.");
                  }

  do {
    isSuccess = 0;
    strcpy(money,"");

    gotoxy(65,10);  printf("Amount: Php ");
    incxy(12,1);    printf("____________________");
    incy(-1);       csdInput(money,"F0",25);

    temp_gotoxy(5,1);

    if (findNumErr(money,TRUE,TRUE,TRUE)) {
      isSuccess = 0;
    }else{
      isSuccess = mtw(money,inwords);
      if (outofrange) {
        isSuccess = 0;
        outofrange = 0;
      }
    }

    if (isSuccess) {
      erasel(14);
      tosentenceCase(inwords);
    }else{
      temp_gotoxy(5,14);
      printf("Invalid money input, try again");
      restore_xy();
    }

  } while(!isSuccess);

  gotoxy(5,14);   wraptext(inwords,81);

  do {
    gotoxy(5,28); typeCT("Do you want to try Again [Y/N] ? ",60);
                  gets(answer);

    erasel(28);

    answer[0] = toupper(answer[0]);

    if (!strcmp(answer,"Y") || !strcmp(answer,"Yes") || !strcmp(answer,"YES")) {
      tryAgain = 1;
      InvalidAnswer = 0;
    }else if (!strcmp(answer,"N") || !strcmp(answer,"No") || !strcmp(answer,"NO")) {
      tryAgain = 0;
      InvalidAnswer = 0;
    }else{
      tryAgain = 0;
      InvalidAnswer = 1;
    }

  } while(InvalidAnswer);


  if (tryAgain) {
    eraseFromTo(24,13);
    goto start;
  }

  gotoxy(5,28); return 0;
}
