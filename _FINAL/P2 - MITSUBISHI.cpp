

/*
  Name: Aldrin Ofiaza Dizor, Edrian Jose D.G. Ferrer
	Section: BSCPE 1-5
	Date: July 31, 2018
	Professor: Engr. Pedrito Tenerife Jr.
	Version : Final
*/

/*
	************* NOTE *****************
	run this command to your command prompt
	or shell to execute this program
	gcc program2.cpp -o program2.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

*/

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

int main()
	{
		char answer;
		printf("Do you want to display?\n");
		scanf("\n%c", &answer);
		if (answer == 'Y') {
			initwindow(600,500,"MITSUBISHI",500,100,FALSE,FALSE);
			setcolor(4);
			line(300,30,380,170);
			line(300,30,220,170);
			line(380,170,220,430);
			line(220,170,380,430);
			line(300,300,460,300);
			line(460,300,537,430);
			line(300,300,140,300);
			line(140,300,63,430);
			line(380,430,537,430);
			line(220,430,63,430);

			setfillstyle(SOLID_FILL,RED);
    	floodfill(300,36,4);
    	setfillstyle(SOLID_FILL,RED);
    	floodfill(380,320,4);
    	setfillstyle(SOLID_FILL,RED);
    	floodfill(240,320,4);
       	setfillstyle(SOLID_FILL,WHITE);
    	floodfill(30,30,4);
			getch();
		}


	}
