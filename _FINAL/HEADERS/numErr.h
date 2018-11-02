#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

char charErrorMap[100],dotErrorMap[100];
int errorcode = -1,globalNumdots = 0;
char ERRORCODE[3];
int hasChar(char input[]){
  int len = strlen(input);
  for (int i = 0; i < len; i++) {
    charErrorMap[i] = '0';
  }
  int hasCharError = 0;
  for (int i = 0; i < len; i++) {
    if (!isdigit(input[i]) && input[i] != '.') {
      hasCharError = 1;
      charErrorMap[i] = '1';
    }else{
      charErrorMap[i] = '0';
    }
  }
  return hasCharError;
}

int numDots(char input[]){
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
      dotErrorMap[i] = '0';
    }
    int dots = 0;
    for (int i = 0; i < len; i++) {
      if (input[i] == '.') {
        if (dots >= 1) {
          dotErrorMap[i] = '1';
        }else{
          dotErrorMap[i] = '0';
        }
        dots++;
      }
    }
    return dots;
}
int checkNumErr(char input[]){
  int charError = hasChar(input);
  int dots = numDots(input);
  globalNumdots = dots;
  if (charError && dots > 1) {
    errorcode = 3;
    return 3; //absolute error
  }else if (dots > 1){
    errorcode = 2;
    return 2; //multiple dots error
  }else if (charError) {
    errorcode = 1;
    return 1; //character error
  }else{
    errorcode = 0;
    return 0; //no errors
  }
}


int findNumErr(char num[],int findChar,int unSigned,int floating){
  int hasError = 0;
  char parseError[] = {'0','0','0'};
  int len = strlen(num);
  int negateInit = 0,dotInit = 0;
    for (int i = 0; i < len; i++) {
      if (findChar &&!isdigit(num[i]) && (num[i] != '-') && (num[i] != '.')) {
        hasError = 1;
        parseError[0] = 1;
      }

      if (num[i] == '-') {
        if (negateInit) {
          hasError = 1;
          parseError[0] = 1;
        }else if (unSigned) {
          hasError = 1;
          parseError[1] = 1;
          negateInit = 1;
        }else{
          negateInit = 1;
        }
      }

      if (num[i] == '.') {
        if (dotInit) {
          hasError = 1;
          parseError[0] = 1;
        }else if (!floating) {
          hasError = 1;
          parseError[2] = 1;
          dotInit = 1;
        }else{
          dotInit = 1;
        }
      }
  }


  if (hasError) {
    strcpy(ERRORCODE,parseError);
    return 1;
  }else{
    return 0;
  }
}
void mapError(char input[]){
  int len = strlen(input);
  int err = checkNumErr(input);
  int clen = strlen(charErrorMap);
  int dlen = strlen(dotErrorMap);
  int maxlen = fmax(clen,dlen);
  char errorMap[maxlen];
  globalNumdots = numDots(input);
  errorcode = err;
  if (err != 0) {
    for (int i = 0; i < maxlen; i++) {
      if (charErrorMap[i] == dotErrorMap[i]) {
          errorMap[i] = charErrorMap[i];
      }else{
        errorMap[i] = (charErrorMap[i]) + (dotErrorMap[i]);
      }
    }
    for (int i = 0; i < len; i++) {
      if (errorMap[i] == '0') {
        printf(" ");
      }else{
        printf("^");
      }
    }
    printf("\n");
  }


}

void getNumErrMsg(){
  if (errorcode != -1) {
    switch (errorcode) {
      case 3: printf("You input a non-digit");break;
      case 2: printf("You input %d dots,NaN.",globalNumdots); break;
      case 1: printf("You input a non-digit"); break;
      case 0:printf("Valid input"); break;
    }
  }

}
