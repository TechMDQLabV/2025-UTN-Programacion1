#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "gotoxy.h"

int main() {
    int x = 50;
    int y = 0;
    int grupo = 1;
    int bloque = 0;
    gotoxy(x,y);
    printf(" <<<<< Colores >>>>> ");
    x = 0;
    y = 1;

    for(int i=0; i<256; i++) {
        if(i%16 == 0 && i>0) {
            if(grupo % 7 == 0) {
                grupo++;
                bloque += 20;
                x = 0;
                y = 20;
            } else {
                x+=17;
                y = 2 + bloque;
            }
        } else {
            y++;
        }
        gotoxy(x,y);
        color(i);
        printf(" Color: %3d ", i);

    }
    system("pause");

    return 0;
}

int eliminarPosArregloInt(int a[], int v, int pos){
    for(int i=pos;i<v;i++){
        a[i]=a[i+1];
    }
    return (pos < v) ? v-1 : v;
}

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%4d - ", a[i]);
    }
}
