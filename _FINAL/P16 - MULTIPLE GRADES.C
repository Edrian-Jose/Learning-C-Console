/*

 * Author    : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.

 * Section   : BSCoE 1-5
 * Date      : October 16, 2018
 * Professor : Engr. Pedrito Tenerife Jr.
 * Version   : Final Version

 */

#include "HEADERS/console_design.h"
#include "numErr.h"
#include "logic_lang.h"

int main() {


        ConsoleProps calc = {"GRADES",{60,50},'F','0'};
        initconsole(calc);
        disableResize();


        // Constant characters and strings
        CString ThankYouMsg = "Thank you for using our program ...";
        CString Lecture     = "Input grades for Lecture [0-100]";
        CString Lab         = "Input grades for Laboratory [0-100]";
        CString TryAgain    = "Do you want to try Again, Y / N ?";

        // Temporary Storages -- used by error checking and input functions

        int inpsize = 5;  // xxxxx
        char input[inpsize], // 97.55
             remarks[15]; // 1.25 - PASSED

        void  getMultipleGrades(char gradetype[],
                                char text[],
                                float *grade,
                                int inpsize);

        // Storage for final output values
        float lecGrade,   // e.g. 60
              labGrade,   // e.g. 40
              finalGrade, // e.g. 98.475
              equivalentGrade; // e.g. 1.00
        int roundedGrade; // e.g. 99


        // Storage for final grade components
        float hworkGrade, // 15%
              recitationGrade, // 10%
              quizGrade,  // 25%
              projectGrade, // 15%
              examGrade;  // 35%
        //TOTAL           // 100%


        // Multiple grades Variables
        int gradeIterations = 1;


        // Status Variables, used for control structures, read README.md file
        int numInit   = 0,
            tryAgain  = NO,
            correct   = YES,
        resetStats(int *tryAgain,
                   int *correct);



        // The character variable below is used to store the user answer for
        // Do you want to try again?
        char answer[5];

        do {
                // Program Display Starts Here
                consoleColor(&calc,'F','0');
                gotoxy(16,1);       csdBar("LECTURE GRADES", "8F", FILL, 1);
                gotoxy(5,26);       csdBar(" ","8f",FILL,1);
                gotoxy(5,4);        csdBar("ASSIGNMENTS","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Assignment",input,&hworkGrade,inpsize);
                gotoxy(5,4);        csdBar("RECITATIONS","9F", 2, 0);
                gotoxy(35,4);    getMultipleGrades("Recitation",input,&recitationGrade,inpsize);
                gotoxy(5,4);        csdBar("  QUIZZES  ","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Quiz",input,&quizGrade,inpsize);
                gotoxy(5,4);        csdBar(" PROJECTS  ","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Project",input,&projectGrade,inpsize);
                gotoxy(5,4);        csdBar("   EXAMS   ","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Exam",input,&examGrade,inpsize);


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

                system("cls");
                consoleColor(&calc,'F','0');
                gotoxy(16,1);       csdBar("LABORATORY GRADES", "3F", FILL, 1);
                gotoxy(5,26);       csdBar(" ","8f",FILL,1);
                gotoxy(5,4);        csdBar("ASSIGNMENTS","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Assignment",input,&hworkGrade,inpsize);
                gotoxy(5,4);        csdBar("RECITATIONS","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Recitation",input,&recitationGrade,inpsize);
                gotoxy(5,4);        csdBar("  QUIZZES  ","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Quiz",input,&quizGrade,inpsize);
                gotoxy(5,4);        csdBar(" PROJECTS  ","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Project",input,&projectGrade,inpsize);
                gotoxy(5,4);        csdBar("   EXAMS   ","9F", 2, 0);
                gotoxy(35,4);       getMultipleGrades("Exam",input,&examGrade,inpsize);

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

                system("cls");   // clears the screen
                consoleColor(&calc,'F','0'); // sets the background color to light-green
                gotoxy(17,1);
                if (finalGrade == 100) {
                        equivalentGrade = 1.00;
                        sprintf(remarks,"PASSED");
                        csdBar("GRADE REPORT","0F",-1,1);
                        gotoxy(12,5); printf("You got a perfect score\n");
                }else if (finalGrade < 74.5) {
                        // sets the bgcolor to red only if equivalent grade is 5.00
                        equivalentGrade = 5.00;
                        sprintf(remarks,"FAILED");
                        csdBar("GRADE REPORT","C0",-1,1);
                }else{
                        sprintf(remarks,"PASSED");
                        csdBar("GRADE REPORT","AF",-1,1);
                }


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
                                system("cls"); // clears the screen
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



        system("cls"); // clears the screen
        gotoxy(5,2);

        if (typeCT(ThankYouMsg,150)) {
                incy(2); //Press any key to continue..
                return 0;
        }
}








int resetStats(int *tryAgain,int *correct){
        *tryAgain = NO;
        *correct = YES;
        return 0;
}

void WriteError(char text[],char color[]){
        short x = XPOS,y = YPOS;
        gotoxy(5,26);
        csdBar(text,color,FILL,1);
        gotoxy(x,y);
}

void getMultipleGrades(char gradeType[],char text[],float *grade,int inpsize){
        int gradeIterations = 1,addAnother = 1,invalidAnswer = 0,err = 0,lineNum = 1;
        float temp_grade = 0,perm_grade = 0;
        char answer[10];
        char answerx;
        char statusGrade[20];
        char InvalidA[]     = "Invalid Answer";
        char InvalidI[]     = "Invalid Input";
        char Valid[]       = " ";
        *grade = 0;
        eraseFromTo(24,5);
        incx(35);

addAnotherx:;
        incxy(-30,2);       printf("%s No. %d\n",gradeType, gradeIterations);
        incx(30);

errx:   ;
        csdInput(text,"70",inpsize);
        err = findNumErr(text,TRUE,TRUE,TRUE);
        if (err) {
                WriteError(InvalidI,"4f");
        }else{
                temp_grade = atof(text);
                if (temp_grade > 100 || temp_grade < 0) {
                        WriteError(InvalidI,"4f");
                        err = 1;
                        goto errx;
                }
                *grade += temp_grade;
                perm_grade = *grade / gradeIterations;
                sprintf(statusGrade,"Current %s Grade : %.2f",gradeType,perm_grade);
                WriteError(statusGrade,"8f");
        }
        if (err) {
                goto errx;
        }


invalidAnswerx:;
        if (invalidAnswer)
        {
                erasel(YPOS);
                gotoy(YPOS-2);
        }
        incxy(-30,2);       printf("Add another %s? Y/ N ",gradeType);
        incx(30);           csdInput(answer, "E0", inpsize);
        answer[0] = toupper(answer[0]);
        if (!strcmp(answer,"Y") || !strcmp(answer,"Yes") || !strcmp(answer,"YES") || !strcmp(answer,"YEs") || !strcmp(answer,"YeS")) {
                addAnother = 1;
                invalidAnswer =   0;
                sprintf(statusGrade,"Current %s Grade : %.2f",gradeType,perm_grade);
                WriteError(statusGrade,"8F");
        } else if (!strcmp(answer,"N") || !strcmp(answer,"No") || !strcmp(answer,"NO")) {
                addAnother = 0;
                invalidAnswer = 0;
                sprintf(statusGrade,"Current %s Grade : %.2f",gradeType,perm_grade);
                WriteError(statusGrade,"8f");
        }else{
                invalidAnswer = 1;
                addAnother = 0;
                WriteError(InvalidA,"c0");
        }


        if (invalidAnswer) {
                goto invalidAnswerx;
        }

        gradeIterations++;
        lineNum++;
        if (lineNum > 8) {
                eraseFromTo(24,5);
                gotoxy(35,6);
                lineNum = 1;
        }
        erasel(YPOS);
        gotoy(YPOS-2);
        if (addAnother) {
                goto addAnotherx;
        }

        *grade = perm_grade;
        sprintf(statusGrade,"Current %s Grade : %.2f",gradeType,*grade);
}
