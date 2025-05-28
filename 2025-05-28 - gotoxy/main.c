#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "gotoxy.h"

#define ESC 27
#define CAR 219

int main()
{
    char c;
    int x=0;
    int y=0;
    printf("%c", CAR);
    do{
        c = getch();

        switch(c){
            case ESC:
                while(!kbhit()){
                    x=rand()%60;
                    y=rand()%24;
                    gotoxy(x,y);
                    color(rand()%256);
                    printf("Hasta la vista.....");
                    Sleep(250);
                }
                break;
            case 59:
                color(15);
                break;
            case 60:
                color(23);
                break;
            case 61:
                color(33);
                break;
            case 62:
                color(44);
                break;
            case 72:
                if(y>0){
                    y--;
                    gotoxy(x,y);
                    printf("%c", CAR);
                }else{
                    Beep(523,523);
                }
                break;
            case 75:
                if(x>0){
                    x--;
                    gotoxy(x,y);
                    printf("%c", CAR);
               }else{
                    Beep(523,523);
                }
                break;
            case 77:
                if(x<80){
                    x++;
                    gotoxy(x,y);
                    printf("%c", CAR);
               }else{
                    Beep(523,523);
                }
                break;
            case 80:
                if(y<24){
                    y++;
                    gotoxy(x,y);
                    printf("%c", CAR);
               }else{
                    Beep(523,523);
                }
                break;
        }
    }while(c!=ESC);


    return 0;
}
