/*
 * Author    : Edrian Jose D.G. Ferrer, Aldrin O. Dizor
 * Section   : BSCoE 1-5
 * Date      : October 16, 2018
 * Professor : Engr. Pederito Tenerife Jr.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy (short x, short y){
								COORD position = {x,y};
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
}
int main(){
								system("color E0");

								char input[200] = {0}, temp[10] = {0};
								int haserror = 0,i,j = 0, k, numbers[100], odd_counter = 0, zero_counter=0, even_counter = 0, positive_counter = 0, negative_counter = 0, sum_negative = 0, sum_positive = 0;
								char TryAgain;


								do {
																haserror = 0;
																system("cls");
																gotoxy(12,2); printf("Instruction: Enter Value/s you want to test, separate each number using comma. \n");
																gotoxy(15,4); printf("NUMBER/S: ");
																scanf("\n%[^\n]s", input);
																for(i = 0; i < strlen(input) - 1; i++) {
																								if ((input[i] == '-' && input[i+1] == ',') || (isdigit(input[i]) && input[i+1] == '-')) {
																																gotoxy(25,6); printf ("Invalid Input (invalid number)");
																																haserror =1;

																								}
																}
																for(i = 0; i < strlen(input) - 1; i++) {
																								if (input[i] == '-' && input[i+1] == '-') {
																																gotoxy(25,6); printf ("Invalid Input (repeating dashes)");
																																haserror =1;
																								}
																}
																for(i = 0; i < strlen(input) - 1; i++) {
																								if (input[i] == ',' && input[i+1] == ',') {
																																gotoxy(25,6); printf ("Invalid Input (repeating comma)");
																																haserror =1;
																								}
																}
																for(i = 0; i < strlen(input); i++) {
																								if ((!isdigit(input[i])) && input[i] != ',' && input[i] != '-') {
																																gotoxy(25,6); printf("Invalid Input (non-numeric)");
																																haserror =1;

																								}
																}
																if(input[strlen(input) - 1] == ',') {
																								gotoxy(25,6); printf("Invalid Input (trailing comma)");
																								haserror =1;

																}
																if(input[strlen(input) - 1] == '-') {
																								gotoxy(25,6); printf("Invalid Input (trailing dash)");
																								haserror =1;

																}
																if(input[0] == ',') {
																								printf("Invalid Input (leading comma)");
																								haserror =1;

																}
																for(i = 0; i <= strlen(input); i++) {
																								if (isdigit(input[i]) || input[i] == '-') {
																																temp[j] = input[i];
																																j++;
																								}else{
																																numbers[k] = atoi(temp);
																																j = 0;
																																memset(temp, 0, 10);
																																k++;
																								}
																}
																for (i = 0; i < k; i++) {
																								if(numbers[i] >= 0 && numbers[i] != 0) {
																																positive_counter++;
																																sum_positive += numbers[i];
																								}
																								else if (numbers[i] == 0) {
																																zero_counter++;
																								}
																								else{
																																negative_counter++;
																																sum_negative += numbers[i];
																								}
																								if(numbers[i] % 2 == 0 && numbers[i] != 0) {
																																even_counter++;
																								}
																								else if (numbers[i] == 0) {
																																zero_counter++;
																								}
																								else{
																																odd_counter++;
																								}
																}
																if (haserror == 0) {
																								gotoxy(15,6); printf("Sum of all Positive Numbers: %d\n", sum_positive);
																								gotoxy(15,7); printf("Sum of all Negative Numbers: %d\n", sum_negative);
																								gotoxy(15,8); printf("# of Positive Numbers: %d\n", positive_counter);
																								gotoxy(15,9); printf("# of Negative Numbers: %d\n", negative_counter);
																								gotoxy(15,10); printf("# of Even Numbers: %d\n", even_counter);
																								gotoxy(15,11); printf("# of Odd Numbers: %d", odd_counter);
																}
																gotoxy(12,13); printf("DO YOU WANT TO TRY AGAIN? PRESS [y/Y then Enter] TO TRY AGAIN, PRESS [any key then enter] to EXIT");
																scanf("\n%c",&TryAgain);
																i=0,j = 0, k=0, numbers[100], odd_counter = 0, even_counter = 0, positive_counter = 0, negative_counter = 0, sum_negative = 0, sum_positive = 0;
								}
								while (TryAgain == 'y' || TryAgain == 'Y');
}
