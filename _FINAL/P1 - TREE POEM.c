
/*  Name: Aldrin Ofiaza Dizor, Edrian Jose D.G. Ferrer
	Section: BSCPE 1-5
	Date: July 31, 2018
	Professor: Engr. Pedrito Tenerife Jr.  */

#include <stdio.h>
#include <string.h>
#include <windows.h>
#define tab 0x09
#define back 0x08

int main()
{
	/*
			T = tabs
			Bs(n) = Backspace(number of backspace)
	*/

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow,
		 						GWL_STYLE,
								GetWindowLong(consoleWindow,GWL_STYLE) &
								~WS_MAXIMIZEBOX &
								~WS_SIZEBOX);

	char T[20] 		= {tab,tab,tab,tab,tab,tab,tab};
	char Bs2[9] 	= {back,back};
	char Bs5[24] 	= {back,back,back,back,back};
	char Bs10[49] = {back,back,back,back,back,back,back,back,back,back};


	printf("\n\n");
	printf("%s",T);
	printf("I\n");
	printf("%s %s \b",T,Bs2);
	printf("think\n");
	printf("%s %s \b",T,Bs5);
	printf("That I shall\n");
	printf("%s %s %s \b ",T,Bs5,Bs2);
	printf("Never see a poem\n");
	printf("%s %s %s %s ",T,Bs5,Bs2,Bs2);
	printf("As lovely as a tree,\n");
	printf("%s %s %s",T,Bs10,Bs2);
	printf("A tree whose hungry mouth\n");
	printf("%s %s %s %s ",T,Bs10,Bs2,Bs2);
	printf("Is pressed against the earth's\n");
	printf("%s %s %s %s",T,Bs10,Bs2,Bs2);
	printf("Sweet flowing breast, a tree that\n");
	printf("%s %s %s ",T,Bs10,Bs5);
	printf("Looks at God all day, and lifts it's\n");
	printf("%s %s %s",T,Bs10,Bs5);
	printf("Leafy arms to pray. A tree that may in\n");
	printf("%s %s %s \b",T,Bs10,Bs5);
	printf("Summer wear, a nest of robin in her hair;\n");
	printf("%s %s %s %s \b",T,Bs10,Bs5,Bs2);
	printf("Upon whose bosom snow has lain; who intimately\n");
	printf("%s %s %s \b ",T,Bs5,Bs2);
	printf("Lives with rain.\n");
	printf("%s %s %s \b",T,Bs5,Bs2);
	printf("Poems are made by\n");
	printf("%s %s %s ",T,Bs5,Bs2);
	printf("Fools like Me\n");
	printf("%s %s",T,Bs2);
	printf("But\n");
	printf("%s %s",T,Bs2);
	printf("Only\n");
	printf("%s %s",T,Bs2);
	printf("God\n");
	printf("%s %s",T,Bs2);
	printf("Can\n");
	printf("%s %s",T,Bs2);
	printf("Make\n");
	printf("%s",T);
	printf("A\n");
	printf("%s %s",T,Bs2);
	printf("Tree\n");
	printf("%s %s \b",T,Bs5);
	printf("Joyce Kilmer");
	printf("%s %s",T,Bs2);
	printf("\n\n");

	return 0;
}
