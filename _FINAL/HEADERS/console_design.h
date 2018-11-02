
#include "console_ui.h"
#define FILL -1
CONSOLE_SCREEN_BUFFER_INFO console_info;
char console_bg = '0',console_fg = 'F';
typedef struct {
        char title[100];
        struct {
                short width;
                short height;
        }windowSize;
        char bgcolor;
        char textcolor;
}ConsoleProps;

void disableResize(){
        HWND hwnd = GetConsoleWindow();
        DWORD style = GetWindowLong(hwnd, GWL_STYLE);
        style &= ~WS_MAXIMIZEBOX;
        style &= ~WS_SIZEBOX;
        SetWindowLong(hwnd, GWL_STYLE, style);
        SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
}

int initconsole(ConsoleProps console){
        CONSOLE_SCREEN_BUFFER_INFO console_info_tmp;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTitle(console.title);
        char color[] = "color   ";
        color[6] = console.bgcolor;
        color[7] = console.textcolor;
        system(color);
        console_bg = console.bgcolor;
        console_fg = console.textcolor;


        short wx = console.windowSize.width + 1;
        short wy = console.windowSize.height + 1;
        SMALL_RECT windowSze = {0, 0, wx, wy};
        int i = SetConsoleWindowInfo(hConsole, TRUE, &windowSze);
        GetConsoleScreenBufferInfo(hConsole,&console_info_tmp);
        short bx = (console_info_tmp.srWindow.Right - console_info.srWindow.Left + 1);
        short by = (console_info_tmp.srWindow.Bottom - console_info.srWindow.Top + 1);
        COORD bufferSize = {bx, by};
        int j = SetConsoleScreenBufferSize(hConsole, bufferSize);
        GetConsoleScreenBufferInfo(hConsole,&console_info);
        if (j && i) {
                return 1;
        }else{
                return 0;
        }
}


int consoleColor(ConsoleProps *console,char bgcolor,char textcolor){
        console->bgcolor = bgcolor;
        console->textcolor = textcolor;
        initconsole(*console);
        disableResize();
        return 0;
}

WORD csd_getColor(char *color){
        WORD config;
        char bg = toupper(color[0]);
        char fg = toupper(color[1]);

        switch (bg) {
        case '1': config = BACKGROUND_BLUE; break;
        case '2': config = BACKGROUND_GREEN; break;
        case '3': config = BACKGROUND_BLUE | BACKGROUND_GREEN; break;
        case '4': config = BACKGROUND_RED; break;
        case '5': config = BACKGROUND_BLUE | BACKGROUND_RED; break;
        case '6': config = BACKGROUND_RED | BACKGROUND_GREEN; break;
        case '7': config = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN; break;
        case '8': config = BACKGROUND_INTENSITY; break;
        case '9': config = BACKGROUND_BLUE | BACKGROUND_INTENSITY; break;
        case 'A': config = BACKGROUND_GREEN | BACKGROUND_INTENSITY; break;
        case 'B': config = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY; break;
        case 'C': config = BACKGROUND_RED | BACKGROUND_INTENSITY; break;
        case 'D': config = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY; break;
        case 'E': config = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY; break;
        case 'F': config = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY; break;
        }


        switch (fg) {
        case '1': config |= FOREGROUND_BLUE; break;
        case '2': config |= FOREGROUND_GREEN; break;
        case '3': config |= FOREGROUND_BLUE | FOREGROUND_GREEN; break;
        case '4': config |= FOREGROUND_RED; break;
        case '5': config |= FOREGROUND_BLUE | FOREGROUND_RED; break;
        case '6': config |= FOREGROUND_RED | FOREGROUND_GREEN; break;
        case '7': config |= FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN; break;
        case '8': config |= FOREGROUND_INTENSITY; break;
        case '9': config |= FOREGROUND_BLUE | FOREGROUND_INTENSITY; break;
        case 'A': config |= FOREGROUND_GREEN | FOREGROUND_INTENSITY; break;
        case 'B': config |= FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY; break;
        case 'C': config |= FOREGROUND_RED | FOREGROUND_INTENSITY; break;
        case 'D': config |= FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY; break;
        case 'E': config |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; break;
        case 'F': config |= FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY; break;
        }

        return config;
}
void restoreConsoleColor(){
        char console_color[] = {console_bg,console_fg};
        WORD system_config = csd_getColor(console_color);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),system_config);
}

void csdBar(char text[],char color[],short wsize,short hsize){
        int len = strlen(text);
        int paddingLeft = 0,paddingRight = 0,barWidth = 0;
        char console_color[] = {console_bg,console_fg};
        WORD config = csd_getColor(color);
        WORD system_config = csd_getColor(console_color);



        if (wsize == FILL) {
                paddingLeft = XPOS;
                paddingRight = console_info.dwSize.X - XPOS - len;
        }
        else{
                paddingLeft = wsize;
                paddingRight = paddingLeft;
        }
        barWidth = paddingLeft + len + paddingRight;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),config);

        store_xy();
        gotox(XPOS-paddingLeft);
        for (int j = 0; j < hsize; j++) {
                gotoy(YPOS-1);
                Space(barWidth);
        }

        restore_xy();

        store_xy();
        gotox(XPOS-paddingLeft);
        Space(paddingLeft);
        printf("%s", text);
        restore_xy();

        store_xy();
        gotox(XPOS+len);
        Space(paddingRight);
        restore_xy();

        store_xy();
        gotox(XPOS-paddingLeft);
        for (int j = 0; j < hsize; j++) {
                gotoy(YPOS+1);
                Space(barWidth);
        }
        restore_xy();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),system_config);
}


void csdInput(char *storage,char color[], int size){
        WORD config = csd_getColor(color);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),config);
        for (int i = 0; i < size; i++) {
                printf("%c", 32);
        }
        gotox(XPOS);
        gets(storage);
        restoreConsoleColor();
        gotox(XPOS);
        printf("%5s", storage);
}
