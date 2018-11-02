/*

  * Author    : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.

  * Section   : BSCoE 1-5
  * Date      : September 29, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/

#include <console_design.h>
#include <numErr.h>
#include <logic_lang.h>

int main() {

  ConsoleProps calc = {"GRADES",{45,26},'F','0'};
  initconsole(calc);
  disableResize();
  // Constant characters and strings
  CString ThankYouMsg = "Thank you for using our program ...";
  CString Lecture     = "Input grades for Lecture [0-100]";
  CString Lab         = "Input grades for Laboratory [0-100]";
  CString TryAgain    = "Do you want to try Again, Y / N ?";

  // Temporary Storages -- used by error checking and input functions
          // xxxxx
  int  inpsize = 5;
  char input[inpsize],    // 97.55
       remarks[15];       // 1.25 - PASSED
  int  getGrade(char *text,
               float *grade,
               int inpsize);


  // Storage for final output values
  float lecGrade,         // e.g. 60
        labGrade,         // e.g. 40
        finalGrade,       // e.g. 98.475
        equivalentGrade;  // e.g. 1.00
  int   roundedGrade;     // e.g. 99


  // Storage for final grade components
  float hworkGrade,       // 15%
        recitationGrade,  // 10%
        quizGrade,        // 25%
        projectGrade,     // 15%
        examGrade;        // 35%
        //TOTAL           // 100%


  // Status Variables, used for control structures, read README.md file
  int numInit   = 0,
      tryAgain  = NO,
      correct   = YES,
      resetStats(int *tryAgain,
                 int *correct);

  // The character variable below is used to store the user answer for
  // Do you want to try again?
  char answer[5];

  //Programs display starts here


  do {

    //reseting all the status variables
    resetStats(&tryAgain,&correct);

    system("cls");        // clears the screen
    consoleColor(&calc,'F','0');
    // set the bgcolor to white and text color to light blue

    gotoxy(0,18);     line(47);
    gotoxy(15,1);     csdBar("LECTURE GRADES","8F",-1,1);
    gotoxy(5,5);      typeCT(Lecture,50);
    incy(3);          printf("Assignments: ");
    incx(30);         getGrade(input,&hworkGrade,inpsize);
    incxy(-30,2);     printf("Recitations: ");
    incx(30);         getGrade(input,&recitationGrade,inpsize);
    incxy(-30,2);     printf("Quizzes: ");
    incx(30);         getGrade(input,&quizGrade,inpsize);
    incxy(-30,2);     printf("Projects: ");
    incx(30);         getGrade(input,&projectGrade,inpsize);
    incxy(-30,2);     printf("Exam: ");
    incx(30);         getGrade(input,&examGrade,inpsize);


    //Programs processes

    //reassigning values of final grade components
    hworkGrade      *=  0.15;
    recitationGrade *=  0.10;
    quizGrade       *=  0.25;
    projectGrade    *=  0.15;
    examGrade       *=  0.35;
    //TOTAL         //  1.00

    // getting the final grade by just adding all of it's components
    lecGrade =   hworkGrade
                 + recitationGrade
                 + quizGrade
                 + projectGrade
                 + examGrade;
    //TOTAL      // XX.XX [0-100] %



    /*codes are below are the same as the above codes
    the only difference is that the above codes gets the user input
    for lecture grades, while the below set of codes gets the user
    input for laboratory grades */

    system("cls");        // clears the screen
    consoleColor(&calc,'F','0');
    // set the bgcolor to white and text color to light blue

    gotoxy(0,18);     line(47);
    gotoxy(15,1);     csdBar("LABORATORY GRADES","8F",-1,1);
    gotoxy(5,5);      typeCT(Lab,50);
    incy(3);          printf("Assignments: ");
    incx(30);         getGrade(input,&hworkGrade,inpsize);
    incxy(-30,2);     printf("Recitations: ");
    incx(30);         getGrade(input,&recitationGrade,inpsize);
    incxy(-30,2);     printf("Quizzes: ");
    incx(30);         getGrade(input,&quizGrade,inpsize);
    incxy(-30,2);     printf("Projects: ");
    incx(30);         getGrade(input,&projectGrade,inpsize);
    incxy(-30,2);     printf("Exam: ");
    incx(30);         getGrade(input,&examGrade,inpsize);



    //Programs processes

    //reassigning values of final grade components
    hworkGrade      *=  0.15;
    recitationGrade *=  0.10;
    quizGrade       *=  0.25;
    projectGrade    *=  0.15;
    examGrade       *=  0.35;
    //TOTAL         //  1.00

    // getting the final grade by just adding all of it's components
    labGrade =   hworkGrade
                 + recitationGrade
                 + quizGrade
                 + projectGrade
                 + examGrade;
    //TOTAL      // XX.XX [0-100] %

    /*rounding off the final grade to easily compare it
      to the standard of equivalent grades.*/


    finalGrade =   (lecGrade * 0.6)
                 + (labGrade * 0.4);

    roundedGrade = round(finalGrade);


    /* The below formula computes for equivalent grade for final grades
      within the range of 75-99, final grades out of this range
      will be handled first by control structures. */

    equivalentGrade = 3 - (((roundedGrade-73)/3)*0.25);


    /* The control structure below handles final grades
       below and above the range of 75 -99

       below 75 final grade will have a 5.00 equivalent grade,
       above 99 or 100 final grade will have a 1.00 equivalent grade
       */

    system("cls");                 // clears the screen
    consoleColor(&calc,'E','0');   // sets the background color to light-green

    if (finalGrade == 100) {
           equivalentGrade = 1.00;
           sprintf(remarks,"PASSED");
    }else if (finalGrade < 74.5) {
           consoleColor(&calc,'C','0'); // sets the bgcolor to red only if equivalent grade is 5.00
           equivalentGrade = 5.00;
           sprintf(remarks,"FAILED");
    }else{
           sprintf(remarks,"PASSED");
    }

    gotoxy(17,1);      csdBar("GRADE REPORT","8F",-1,1);
    gotoxy(5,5);       printf("%s", remarks);
    incy(3);           printf("Lecture Grade:");
    incx(30);          printf("%.2f", lecGrade);
    incxy(-30,2);      printf("Laboratory Grade:");
    incx(30);          printf("%.2f", labGrade);
    incxy(-30,2);      printf("Final Grade:");
    incx(30);          printf("%.2f", finalGrade);
    incxy(-30,2);      printf("Equivalent Grade:");
    incx(30);          printf("%.2f", equivalentGrade);
    incxy(-30,3);





    do {

      printf("\n");
      if (!correct) {
        system("cls");    // clears the screen
        gotoxy(5,5); printf("Invalid answer\n");
      }

      incy(2);  typeCT(TryAgain,75);
      incy(2);  gets(answer);

      answer[0] = toupper(answer[0]); // converts the answer to uppercase char.


      //The control structure below performs specific task dependent from the user input


      if (!strcmp(answer,"Y") || !strcmp(answer,"Yes") || !strcmp(answer,"YES") || !strcmp(answer,"YEs") || !strcmp(answer,"YeS")) {
          tryAgain = YES;
          correct = YES;
      }else if (!strcmp(answer,"N") || !strcmp(answer,"No") || !strcmp(answer,"NO")) {
          tryAgain = NO;
          correct = YES;
      }else{
          correct = NO;
      }
    } while(!correct);


    numInit++;
  } while(tryAgain);



  system("cls");    // clears the screen
  gotoxy(5,2);

  if (typeCT(ThankYouMsg,150)) {
    incy(2);        //Press any key to continue..
    return 0;
  }
}//main funtion




int resetStats(int *tryAgain,int *correct){
  *tryAgain = NO;
  *correct = YES;
  return 0;
}


int getGrade(char *text,float *grade,int inpsize){
  int err = 0;
  int hasError = 0,endclear = 1;
  do {
    csdInput(text,"B0",inpsize);
    err = checkNumErr(text);
    erasel(YPOS+2);
    erasel(22);erasel(23);erasel(25);
    for (int i = 1; i < strlen(text); i++) {
      if (!isdigit(text[i])) {
        endclear  = 0;
      }
    }
    if (text[0] == '-' && endclear) {
      store_xy();   gotox(5);
      incy(2);      printf("%s", "Invalid input, Try again");
      gotoxy(5,22); printf("Do not input a negative number");
      restore_xy(); Space(inpsize + 7);
      gotox(XPOS);
      hasError = 1;
    }else if (err) {
      store_xy();   gotox(5);
      incy(2);      printf("%s", "Invalid input, Try again");
      gotoxy(5,22); printf("%s", text);
      incy(1);      mapError(text);
      incy(2);      getNumErrMsg();
      restore_xy(); Space(inpsize + 7);
      gotox(XPOS);
      hasError = 1;
    }else if (iscntrl(text[0])) {

      store_xy();   gotox(5);
      incy(2);      printf("%s", "Invalid input, Try again");
      gotoxy(5,22); printf("Do not input control characters");
      restore_xy(); Space(inpsize + 7);
      gotox(XPOS);
      hasError = 1;

    }else{
      *grade = atof(text);
      if (*grade > 100 || *grade < 0) {
        store_xy();   gotox(5);
        incy(2);      printf("%s", "Out of range, Try again");
        gotoxy(5,22); printf("Do not input grades greater than 100");
        restore_xy(); Space(inpsize + 7);
        gotox(XPOS);
        hasError = 1;
      }else{
        hasError = 0;
      }


    }
  } while(hasError);



}
