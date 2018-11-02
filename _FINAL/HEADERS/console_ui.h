#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

//global
short XPOS = 0,YPOS = 0;
short _X,_Y,_iXY = 1;
typedef char* String;
typedef const char* CString;
//function declarations

//sets the console cursor position
void gotoxy(short x,short y){
  COORD position = {x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position);
  XPOS = x;
  YPOS = y;
}
void gotox(short x){
  gotoxy(x,YPOS);
}

void gotoy(short y){
  gotoxy(XPOS,y);
}
//increment the current position of console cursor
void incxy(short x,short y){
  gotoxy(XPOS+x,YPOS+y);
}


void incx(short x){
  gotoxy(XPOS+x,YPOS);
}

void incy(short y){
  gotoxy(XPOS,YPOS+y);
}

void line(short width){
  for (int i = 0; i < width; i++) {
    printf("_");
  }
}

void pos(COORD pos,int increment){
  if (increment) {
    incxy(pos.X,pos.Y);
  }else{
    gotoxy(pos.X,pos.Y);
  }
}


void store_xy(){
  if (_iXY) {
    _X = XPOS;
    _Y = YPOS;
    _iXY = 0;
  }
}

void temp_gotoxy(short x,short y){
  if (_iXY) {
    _X = XPOS;
    _Y = YPOS;
    _iXY = 0;
  }
  gotoxy(x,y);
}

void temp_incxy(short x,short y){
  temp_gotoxy(XPOS+x,YPOS+y);
}

void restore_xy(){
  XPOS = _X;
  YPOS = _Y;
  _iXY = 1;
  gotoxy(XPOS,YPOS);
}

void erasel(short y){
  CONSOLE_SCREEN_BUFFER_INFO console_info_tmp;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(hConsole,&console_info_tmp);
  int i = 0;
  temp_gotoxy(0,y);
  while (i < console_info_tmp.dwSize.X) {
    printf("%c",32);
    i++;
  }
  restore_xy();
}


void eraseAll(){
  gotoxy(0,YPOS);

  do {
    erasel(YPOS);
    gotoxy(0,--YPOS);
  } while(YPOS != -1);

  gotoxy(0,0);
}

void eraseFromTo(short from,short to){
  gotoxy(0,from);
  do {
    erasel(YPOS);
    gotoxy(0,--YPOS);
  } while(YPOS != (to-1));

  gotoxy(0,to);
}

int typeT(String text,int duration){
  setvbuf(stdin, NULL, _IONBF, 0);
  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    printf("%c", text[i]);
    Sleep(duration);
  }

  return 1;
}

int typeCT(CString text,int duration){
  setvbuf(stdin, NULL, _IONBF, 0);
  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    printf("%c", text[i]);
    Sleep(duration);
  }

  return 1;
}

void Space(int size){
  for (int i = 0; i < size; i++) {
    printf("%c", 32);
  }
}


int wraptext(char text[],int width){
  int counter = 0;
  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    if (counter > width) {
      incy(1);
      counter = 0;
    }
    printf("%c", text[i]);
    counter++;
  }
  return 0;
}
