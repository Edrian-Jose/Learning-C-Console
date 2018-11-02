/*

  * Author    : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.

  * Section   : BSCoE 1-5
  * Date      : August 24, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/


#include <stdio.h>
#include <windows.h>
#include <math.h>


short XPOS = 0,YPOS = 0;
void gotoxy(short x, short y);
void incxy(short x,short y);
void erase();


int main() {
        float hswork,recit,quiz,exam,project;
        float lecGrade,labGrade,totalGrade,equivGrade;
        int roundedGrade;
        char status[] = "PASSED";
        gotoxy(15,2); printf("GRADES CALCULATOR");
        gotoxy(7,6); printf("Input grades (0-100) for Lecture");
        gotoxy(7,8); printf("Assignment / Seatwork :");
        gotoxy(36,8); scanf("%f", &hswork);
        gotoxy(7,10); printf("Recitation:");
        gotoxy(36,10); scanf("%f", &recit);
        gotoxy(7,12); printf("Quiz:");
        gotoxy(36,12); scanf("%f", &quiz);
        gotoxy(7,14); printf("Project:");
        gotoxy(36,14); scanf("%f", &project);
        gotoxy(7,16); printf("Exam:");
        gotoxy(36,16); scanf("%f", &exam);
        erase();

        hswork = hswork * 0.15;
        recit = recit * 0.10;
        quiz = quiz * 0.25;
        project = project * 0.15;
        exam = exam * 0.35;

        lecGrade = hswork + recit + quiz + project + exam;
        system("color E0");

        gotoxy(15,2); printf("GRADES CALCULATOR");
        gotoxy(7,6); printf("Input grades (0-100) for Laboratory");
        gotoxy(7,8); printf("Assignment / Seatwork :");
        gotoxy(36,8); scanf("%f", &hswork);
        gotoxy(7,10); printf("Recitation:");
        gotoxy(36,10); scanf("%f", &recit);
        gotoxy(7,12); printf("Quiz:");
        gotoxy(36,12); scanf("%f", &quiz);
        gotoxy(7,14); printf("Project:");
        gotoxy(36,14); scanf("%f", &project);
        gotoxy(7,16); printf("Exam:");
        gotoxy(36,16); scanf("%f", &exam);
        erase();
        hswork = hswork * 0.15;
        recit = recit * 0.10;
        quiz = quiz * 0.25;
        project = project * 0.15;
        exam = exam * 0.35;

        labGrade = hswork + recit + quiz + project + exam;
        totalGrade = lecGrade*0.6 + labGrade*0.4;

        roundedGrade = round(totalGrade);


        switch (roundedGrade) {
        case 75: equivGrade = 3; break;
        case 76 ... 78: equivGrade = 2.75; break;
        case 79 ... 81: equivGrade = 2.50; break;
        case 82 ... 84: equivGrade = 2.25; break;
        case 85 ... 87: equivGrade = 2.00; break;
        case 88 ... 90: equivGrade = 1.75; break;
        case 91 ... 93: equivGrade = 1.50; break;
        case 94 ... 96: equivGrade = 1.25; break;
        case 97 ... 100: equivGrade = 1; break;
        default: equivGrade = 5; strcpy(status,"FAILED");
        }
        if (equivGrade > 3.0) {
          system("color C0");
        }else{
          system("color A0");
        }
        gotoxy(10,5); printf("Your grade is %.2f",totalGrade);
        gotoxy(10,6); printf("Which is equivalent to %.2f",equivGrade);
        gotoxy(10,7); printf("%s",status);
        gotoxy(0,12);
        return 0;
}

void gotoxy(short x,short y){
        COORD pos = {x,y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
        XPOS = x;
        YPOS = y;
}

void incxy(short x,short y){
        XPOS += x,YPOS += y;
        gotoxy(XPOS,YPOS);
}

void erase(){
        XPOS = 0;
        while (YPOS != 0) {
                gotoxy(XPOS,YPOS);
                for (int i = 0; i < 50; i++) {
                        printf(" ");
                }
                YPOS--;
        }
}
