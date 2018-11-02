/*

  * Authors   : Dizor, Aldrin O.
                Ferrer, Edrian Jose D.G.
  * Section   : BSCoE 1-5
  * Date      : August 21, 2018
  * Professor : Engr. Pedrito Tenerife Jr.
  * Version   : Final Version

*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>


void gotoxy(short x,short y){
  COORD pos = {x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main() {


  //Variable Declarations
  float quiz,
        hswork,
        project,
        recitation,
        exam,
        totalGrade,
        equivGrade;

  int roundedTotalGrade;

  char status[] = "PASSED";
  char prompt[] = "\tInput the grades(0-100)";


  //prompt the user to input the grades for lecture
  gotoxy(5,0);    printf("%s for lecture: \n\n",prompt);
                  printf("\tAssignment / Seatwork : ");
                  scanf("%f", &hswork);
                  printf("\tRecitation: ");
                  scanf("%f", &recitation);
                  printf("\tQuiz: ");
                  scanf("%f", &quiz);
                  printf("\tProject: ");
                  scanf("%f", &project);
                  printf("\tExam: ");
                  scanf("%f", &exam);

  // process the input data
  // converts the input grade (0-100%) to specified percentage

    hswork      = hswork     * 0.15;
    recitation  = recitation * 0.10;
    quiz        = quiz       * 0.25;
    project     = project    * 0.15;
    exam        = exam       * 0.35;

    totalGrade = hswork +
                 recitation +
                 quiz +
                 project +
                 exam;


    roundedTotalGrade = round(totalGrade);



    if (roundedTotalGrade < 75) {
      equivGrade = 5; strcpy(status,"FAILED");
    }
    else if (roundedTotalGrade == 75) {
      equivGrade = 3;
    }
    else if (roundedTotalGrade < 79) {
      equivGrade = 2.75;
    }
    else if (roundedTotalGrade < 82) {
      equivGrade = 2.50;
    }
    else if (roundedTotalGrade < 85) {
      equivGrade = 2.25;
    }
    else if (roundedTotalGrade < 88) {
      equivGrade = 2.00;
    }
    else if (roundedTotalGrade < 91) {
      equivGrade = 1.75;
    }
    else if (roundedTotalGrade < 94) {
      equivGrade = 1.50;
    }
    else if (roundedTotalGrade < 97) {
      equivGrade = 1.25;
    }
    else{
      equivGrade = 1.00;
    }


    printf("\nYour grade is %.2f which is equivalent to %.2f, %s\n\n", totalGrade, equivGrade, status);

return 0;
}


//no code that follows
