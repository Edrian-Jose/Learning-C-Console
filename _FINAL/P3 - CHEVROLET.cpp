
/*  Name: Aldrin Ofiaza Dizor, Edrian Jose D.G. Ferrer
	Section: BSCPE 1-5
	Date: July 31, 2018
	Professor: Engr. Pedrito Tenerife Jr.  */


#include <plane.h> // plane.h contains already all the the necessary includes for graphics and stdio

int main() {
  initwindow(625,400,"Chevrolet Logo",450,150,false,false); // initialize window with 625 width and 400 height
  cleardevice(); // clear the screen
  setcolor(15); //set the color painter to white
  createPlane(50,50,75,12,0,3,1,1,2,1,2,0,5,0,5,1,7,1,6,3,5,3,5,4,2,4,2,3); // see plane.h for syntax
  setfillstyle(SOLID_FILL, 15);
  floodfill(200,150,15);
  getch();
  return 0;
}
