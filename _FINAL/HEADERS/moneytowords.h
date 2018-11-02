#include "numErr.h"

int moneyError,lenvalue,outofrange;

void tosentenceCase(char text[]){
        int len = strlen(text);
        text[0] = toupper(text[0]);
        for (int i = 1; i < len; i++) {
                text[i] = tolower(text[i]);
        }
}
int isFloat(char num[],int *hasError){
        if (numDots(num) == 1) {
                return 1;
        }else if (numDots(num) > 1) {
                *hasError = 1;
                return 0;
        }else {
                return 0;
        }
}
int getPlace(char money[],int *grpPlace,int *hasError){
        *grpPlace = 1;
        int numPlace = strlen(money);
        int len = strlen(money);
        int floating = isFloat(money,hasError);
        if (floating) {
                int i = 0;
                while(money[i] != '.') {
                        i++;
                }

                if (len > (i+3)) {
                        *hasError = 1;
                        strcpy(money,"");
                }else if(iscntrl(money[i+1])) {
                        numPlace -= 1;
                        lenvalue -= 3;
                }else if(iscntrl(money[i+2])) {
                        numPlace -= 2;
                        lenvalue -= 4;
                }else{
                        numPlace -= 3;
                        lenvalue -= 5;
                }

                //TODO: determine if .3 only or .30 or .35
        }

        while (numPlace != 1 && numPlace != 2 && numPlace != 3) {
                numPlace -=3;
                *grpPlace += 1;
        }

        return numPlace;
}

void returnUnit(int grpPlace,char inwords[]){
        switch (grpPlace) {
        case 0: strcpy(inwords,"Centavo(s) "); break;
        case 1: strcpy(inwords,"Peso(s) "); break;
        case 2: strcpy(inwords,"Thousand "); break;
        case 3: strcpy(inwords,"Million "); break;
        case 4: strcpy(inwords,"Billion "); break;
        case 5: strcpy(inwords,"Trillion "); break;
        case 6: strcpy(inwords,"Quadrillion "); break;
        case 7: strcpy(inwords,"Quintillion "); break;
        case 8: strcpy(inwords,"Sextillion "); break;
        default: outofrange = 1;
        }
}
void convertToSimple(char num,char inwords[]){
        switch (num) {
        case '0': strcpy(inwords,"Zero "); break;
        case '1': strcpy(inwords,"One "); break;
        case '2': strcpy(inwords,"Two "); break;
        case '3': strcpy(inwords,"Three "); break;
        case '4': strcpy(inwords,"Four "); break;
        case '5': strcpy(inwords,"Five "); break;
        case '6': strcpy(inwords,"Six "); break;
        case '7': strcpy(inwords,"Seven "); break;
        case '8': strcpy(inwords,"Eight "); break;
        case '9': strcpy(inwords,"Nine "); break;
        default: strcpy(inwords,""); break;
        }
}

void convertToTens(char num,char inwords[]){
        switch (num) {
        case '2': strcpy(inwords,"Twenty ");  break;
        case '3': strcpy(inwords,"Thirty "); break;
        case '4': strcpy(inwords,"Forty "); break;
        case '5': strcpy(inwords,"Fifty "); break;
        case '6': strcpy(inwords,"Sixty "); break;
        case '7': strcpy(inwords,"Seventy "); break;
        case '8': strcpy(inwords,"Eighty "); break;
        case '9': strcpy(inwords,"Ninety "); break;
        default: strcpy(inwords,""); break;

        }
}

void convertToTeen(char num,char inwords[]){
        switch (num) {
        case '0': strcpy(inwords,"Ten ");      break;
        case '1': strcpy(inwords,"Eleven "); break;
        case '2': strcpy(inwords,"Twelve "); break;
        case '3': strcpy(inwords,"Thirteen "); break;
        case '4': strcpy(inwords,"Fourteen "); break;
        case '5': strcpy(inwords,"Fifteen "); break;
        case '6': strcpy(inwords,"Sixteen "); break;
        case '7': strcpy(inwords,"Seventeen "); break;
        case '8': strcpy(inwords,"Eighteen "); break;
        case '9': strcpy(inwords,"Nineteen "); break;
        }
}

void pretrimmer(char text[],int places){
        int len = strlen(text);
        char oldtext[len];
        char newtext[len];
        strcpy(oldtext,text);
        for (int i = places; i < len; i++) {
                newtext[i-places] = oldtext[i];
        }
        strcpy(text,newtext);
}

void trimmer(char text[],char temp_text[],int places){
        for (int i = 0; i < places; i++) {
                temp_text[i] = text[i];
        }
}
void convertToWordsA(char money[],char inwords[],int start){
        char temp_inwords[30];
        convertToSimple(money[start],temp_inwords);
        strcat(inwords,temp_inwords);
        if (money[start] != '0') {
                strcat(inwords,"Hundred ");
        }
}

void convertToWordsB(char money[],char inwords[],int start){
        char temp_inwords[30];
        iscntrl(money[start+1]) ? money[start+1] = 0 : 0;
        if (money[start] == '1') {
                convertToTeen(money[start+1],temp_inwords);
                strcat(inwords,temp_inwords);
        }else{
                convertToTens(money[start],temp_inwords);
                strcat(inwords,temp_inwords);
                convertToSimple(money[start+1],temp_inwords);
                strcat(inwords,temp_inwords);
        }
}

void convertToWords(int numPlace,int grpPlace,char money[],char inwords[]){
        char temp_inwords[30];
        if (numPlace == 3) {
                convertToWordsA(money,inwords,0);
                convertToWordsB(money,inwords,1);
        }else if(numPlace == 2) {
                convertToWordsB(money,inwords,0);
        }else{
                convertToSimple(money[0],temp_inwords);
                strcat(inwords,temp_inwords);
        }
        returnUnit(grpPlace,temp_inwords);
        strcat(inwords,temp_inwords);
}


int mtw(char money[],char inwords[]){
        int lent,numPlace,grpPlace,maxGrp,dotPos,len,hasError = 0,numZero = 0;
        char cent[3],temp_inwords[50];
        strcpy(inwords,"");
        strcpy(temp_inwords,"");

        if (money[0] == '0') {
                while (money[numZero] == '0') {
                        numZero++;
                }
                pretrimmer(money,numZero);
        }

        len = strlen(money);
        dotPos = len;
        char temp_money[len+1];
        if (money[0] == '.') {
                for (int i = 0; i < len+1; i++) {
                        temp_money[i+1] = money[i];
                }
                temp_money[0] = '0';
                strcpy(money,temp_money);
        }



        numPlace = getPlace(money,&grpPlace,&hasError);
        maxGrp = grpPlace;

        if (isFloat(money,&hasError)) {
                for (int i = 0; i < len; i++) {
                        if (money[i] == '.') {
                                dotPos = i;
                        }
                }
                cent[0] = money[dotPos+1];
                cent[1] = money[dotPos+2];
                lent = iscntrl(money[dotPos+1]);


                strcat(temp_inwords,"and ");
                if ((cent[0] == '0' && cent[1] == '0') || lent) {
                        strcat(temp_inwords,"zero centavo");
                }else{
                        convertToWords(2,0,cent,temp_inwords);
                }
        }
        convertToWords(numPlace,grpPlace,money,inwords);
        pretrimmer(money,numPlace);
        numPlace = 3;
        for (int i = 1; i < maxGrp; i++) {
                grpPlace--;
                convertToWords(numPlace,grpPlace,money,inwords);
                pretrimmer(money,3);
        }

        strcat(inwords,temp_inwords);
        if (hasError) {
                return 0;
        }else{
                return 1;
        }

}
