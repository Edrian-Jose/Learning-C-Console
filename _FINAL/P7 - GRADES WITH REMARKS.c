/*

  * Authors   : Ferrer, Edrian Jose D.G.
                Dizor, Aldrin O.
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
  float quiz,
        hswork,
        project,
        recitation,
        exam,
        totalGrade;



  //prompt the user to input the grades for lecture
  gotoxy(5,0);    printf("Input grades[0-100] for lecture: \n\n");
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

  //process the input data
  // converts the input grade (0-100%) to specified percentage (e.g. 30%)

    hswork     = hswork * 0.15;
    recitation = recitation * 0.10;
    quiz       = quiz * 0.25;
    project    = project * 0.15;
    exam       = exam * 0.35;

    totalGrade = hswork +       // 0 - 15
                 recitation +   // 0 - 10
                 quiz +         // 0 - 25
                 project +      // 0 - 15
                 exam;          // 0 - 35
                 //totalGrade   // 0 - 100


    printf("\n\tYour grade is %.2f, ", totalGrade);

    // Determine if totalGrade is passses or failed
    if (totalGrade >= 75) {
      printf("PASSED\n\n");
    }else{
      printf("FAILED\n\n");
    }
    return 0;
}


//no code that follows
